#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <sstream>

// Hello. This is a simple command line utility for packaging assets into a si-
// ngle file. It works recursively.

namespace stdfs = std::filesystem;

// Simple function to put all of the command line arguments into a single vect-
// or of strings, which is easier to work with.
static std::vector<std::string> preprocessCommandLineArguments(int argc, char** argv)
{
    std::vector<std::string> result(argc);
    
    for (uint32_t i = 0; i < argc; i++)
    {
        result[i] = argv[i];
    }
    
    return result;
}


// Obtain the files within the target directory.
static std::vector<std::string> getFiles(std::string_view directory, bool recursive)
{
    std::vector<std::string> files;
    for (const auto& file: stdfs::directory_iterator(directory))
    {
        files.push_back(file.path());
        
        if (recursive && file.is_directory())
        {
            std::vector<std::string> neng = getFiles(file.path().c_str(), recursive);
            files.insert(files.end(), neng.begin(), neng.end());
        }
    }
}

int main(int argc, char** argv)
{
    // Get the arguments into a vector
    auto args = preprocessCommandLineArguments(argc, argv);
    
    // The directory in which to archive. By default, it is "."
    std::string targetDir = ".";
    
    // The resulting file to write to.
    std::string resultFile = "mardikar.jay";
    
    // Whether or not to search recursively. By default, this is "yes"
    bool recursive = true;
    
    // What is the next argument?
    enum class Argument
    {
        RESULT, TARGET_DIR
    };
    
    Argument nextArgument = Argument::TARGET_DIR;
    
    // Process the command line arguments
    for (const auto& arg: args)
    {
        // Flag to not package recursively
        if (arg == "--no-recursive")
        {
            recursive = false;
        }
        else if (arg == "--result")
        {
            nextArgument = Argument::TARGET_DIR;
        }
        // If it isn't a flag, then it must be the target directory
        else
        {
            if (nextArgument == Argument::TARGET_DIR)
            {
                targetDir = arg;
            }
            else if (nextArgument == Argument::RESULT)
            {
                resultFile = arg;
            }
        }
    }
    
    // Get all of the files in the target directory
    std::vector<std::string> files = getFiles(targetDir, recursive);
    
    // Open the result file.
}