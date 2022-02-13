#include <scp/utils/file-utils.hpp>
#include <scp/utils/string_utils.hpp>

#include <sstream>

#include <scp/utils/AssetCollection.hpp>

using scp::utils::AssetCollection;

AssetCollection::AssetCollection(std::string_view contentPath, std::string_view configPath):
                                 m_contentStream(contentPath.data(), std::ofstream::binary)
{
    if (!m_contentStream.is_open())
    {
        std::cerr << "[ERROR]: Failed to open " << contentPath << std::endl;
    }
    
    std::ifstream configStream(configPath.data());
    if (!configStream.is_open())
    {
        std::cerr << "[ERROR]: Failed to open " << configPath << std::endl;
    }
    
    while (configStream.good())
    {
        std::string line;
        std::getline(configStream, line);
        
        std::vector<std::string> configLine = string_utils::splitString(line, ':');
        
        Configuration config;
        config.start = std::stoi(configLine[1]);
        config.end = std::stoi(configLine[2]);
        
        m_configurations.insert(std::pair<std::string, Configuration>(configLine[0], config));
    }
}

std::string AssetCollection::getTextAsset(std::string_view name)
{
    Configuration& config = m_configurations.at(name.data());
    
    m_contentStream.seekg(config.start);
    
    std::stringstream result;
    
    for (uint32_t i = config.start; i < config.end; i++)
    {
        char character;
        m_contentStream.read(&character, 1);
        
        result << character;
    }
    
    return result.str();
}

std::vector<char> AssetCollection::getBinaryAsset(std::string_view name)
{
    Configuration& config = m_configurations.at(name.data());
    m_contentStream.seekg(config.start);
    
    std::vector<char> result;
    
    for (uint32_t i = config.start; i < config.end; i++)
    {
        char character;
        m_contentStream.read(&character, 1);
        
        result.push_back(character);
    }
    
    return result;
}