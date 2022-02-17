#ifndef D45CFDBC_454C_4010_BBDE_C61E914FC19F
#define D45CFDBC_454C_4010_BBDE_C61E914FC19F

#include "pch.hpp"
#include <fstream>
#include <map>

namespace scp::utils
{
    struct Configuration
    {
        uint32_t start;
        uint32_t end;
    };

    class SCPGFFUNC AssetCollection
    {
    public:
        // Create an asset collection. Obtain 
        AssetCollection(std::string_view contentPath = "mardikar.jay", std::string_view configPath = "neng.li");
        
        // Get an asset that is a text.
        std::string getTextAsset(std::string_view name);
        
        // Get an asset that is in binary form.
        std::vector<char> getBinaryAsset(std::string_view name);
        
    private:
        // The actual file stream to read the assets
        std::ifstream m_contentStream;

        // The configurations.
        std::map<std::string, Configuration> m_configurations;
    };
}

#endif /* D45CFDBC_454C_4010_BBDE_C61E914FC19F */
