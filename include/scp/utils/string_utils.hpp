#ifndef C38DD9E2_0700_478E_AFFE_836CEF804595
#define C38DD9E2_0700_478E_AFFE_836CEF804595

#include "pch.hpp"

namespace scp::utils
{
    namespace string_utils
    {
        SCPGFFUNC bool startsWith(std::string_view a, std::string_view b);
        
        SCPGFFUNC std::vector<std::string> splitString(std::string_view host, char delimiter);
    }
}

#endif /* C38DD9E2_0700_478E_AFFE_836CEF804595 */
