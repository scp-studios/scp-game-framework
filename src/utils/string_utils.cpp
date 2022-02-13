#include <sstream>

#include <scp/utils/string_utils.hpp>

namespace string_utils = scp::utils::string_utils;

bool string_utils::startsWith(std::string_view p_a, std::string_view p_b)
{
    if (p_a.size() < p_b.size())
    {
        return false;
    }
    
    for (std::string_view::iterator aIt = p_a.begin(), bIt = p_b.begin(); bIt != p_b.end(); aIt++, bIt++)
    {
        if (*aIt != *bIt)
        {
            return false;
        }
    }
    
    return true;
}

std::vector<std::string> string_utils::splitString(std::string_view host, char delimiter)
{
    std::vector<std::string> result;
    
    std::stringstream stream(host.data());
    
    while (stream.good())
    {
        std::string part;
        std::getline(stream, part, delimiter);
        
        result.push_back(part);
    }
    
    return result;
}