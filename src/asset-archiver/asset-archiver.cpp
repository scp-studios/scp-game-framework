#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>

// Hello. This is a simple command line utility for packaging assets into a si-
// ngle file. It works recursively.

namespace stdfs = std::filesystem;

// Unused argument suppressor
#define UNUSED_ARG(x) (void)x

// Simple function to put all of the command line arguments into a single vect-
// or of strings, which is easier to work with.
#if 0
static std::vector<std::string> preprocessCommandLineArguments(int argc, char** argv)
{
    std::vector<std::string> result(argc);
    
    for (uint32_t i = 0; i < argc; i++)
    {
        result[i] = argv[i];
    }
    
    return result;
}
#endif

static std::vector<std::string> splitString(std::string_view host, std::string_view separator)
{
    std::vector<std::string> result;
    
    size_t start = 0;
    size_t end = host.find(separator, start);
    
    while (end != std::string::npos)
    {
        result.push_back(std::string(host.substr(start, end - start)));
        start = end + separator.length();
        end = host.find(separator, start);
    }
    
    result.push_back(std::string(host.substr(start)));
    
    return result;
}

// Obtain the files within the target directory.
static std::vector<std::string> getFiles(std::string_view directory, bool recursive)
{
    std::vector<std::string> files;
    for (const auto& file: stdfs::directory_iterator(directory))
    {
        #ifdef _WIN32
        files.push_back(file.path().string());
        #else
        files.push_back(file.path());
        #endif
        
        if (recursive && file.is_directory())
        {
            #ifdef _WIN32
            std::vector<std::string> subdirectoryFiles = getFiles(file.path().string(), recursive);
            #else
            std::vector<std::string> subdirectoryFiles = getFiles(file.path().c_str(), recursive);
            #endif
            files.insert(files.end(), subdirectoryFiles.begin(), subdirectoryFiles.end());
        }
    }
    
    return files;
}

int main(int argc, char** argv)
{
    // We are not using these arguments yet.
    UNUSED_ARG(argc);
    UNUSED_ARG(argv);
    
    // I'll use command line arguments later. For now, they are just constants.
    const std::string targetDir = "./assets";
    const std::string contentOutput = "mardikar.jay";
    const std::string configOutput = "neng.li";
    
    // Obtain all of the files within the asset directory.
    std::vector<std::string> assetFiles = getFiles(targetDir, true);
    
    // This file is the file in which we output the content of the assets into.
    // They will be linked together into a single binary file.
    std::ofstream contentOutputFile(contentOutput, std::ofstream::binary);
    if (!contentOutputFile)
    {
        std::cerr << "[FATAL ERROR]: Failed to open " << contentOutput << " for writing.\n";
        return -1;
    }
    
    // This is the file in which we output the configuration file. It is where
    // the reader can then lookup the location of the assets within the content
    // file.
    std::ofstream configOutputFile(configOutput);
    if (!configOutputFile)
    {
        std::cerr << "[FATAL ERROR]: Failed to open " << configOutput << "for writing.\n";
        return -2;
    }
    
    // We need to keep track of where the file is.
    uint32_t startingMarker = 0;
    uint32_t endingMarker = 0;
    
    // We iterate through all of the assets.
    for (const auto& asset: assetFiles)
    {
        // At the start of each iteration, the starting marker is set to the p-
        // oint in which the last file ends.
        startingMarker = endingMarker;
        
        // We open the asset file for reading in binary mode.
        std::ifstream file(asset, std::ifstream::binary);
        if (!file)
        {
            std::cerr << "[WARNING]: Skipping " << asset << " due to an error in opening the file.\n";
            continue;
        }
        
        // Next, we iterate through the whole file.
        while (file)
        {
            // Read a character
            char character;
            file.read(&character, 1);
            
            // Push that character to the content file.
            contentOutputFile.write(&character, 1);
            
            // Increase the ending marker.
            endingMarker++;
        }
        
        // Finally, we add an entry in the configuration file
        configOutputFile << asset << ":" << startingMarker << ":" << endingMarker << "\n";
    }
    
    // Okay, now we're done.
    return 0;
}