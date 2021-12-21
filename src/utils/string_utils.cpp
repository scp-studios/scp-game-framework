#include <scp/utils/string_utils.hpp>

namespace string_utils = scp::utils::string_utils;

bool string_utils::startsWith(std::string_view p_a, std::string_view p_b)
{
    for (std::string_view::iterator aIt = p_a.begin(), bIt = p_b.begin(); bIt != p_b.end(); aIt++, bIt++)
    {
        if (*aIt != *bIt)
        {
            return false;
        }
    }
    
    return true;
}