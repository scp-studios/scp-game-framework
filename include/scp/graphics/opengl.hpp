#ifndef F973E16E_C42F_400C_86EB_F395CA3B34F2
#define F973E16E_C42F_400C_86EB_F395CA3B34F2

#include <scp/scp.hpp>

namespace scp::graphics
{
    SCPGFFUNC namespace opengl
    {
        SCPGFFUNC void enableContextDebugging();
        
        SCPGFFUNC void enable2DBlending();
        
        SCPGFFUNC void setClearColor(float red, float green, float blue, float alpha);
        
        SCPGFFUNC void clearColor();
        
        SCPGFFUNC void clearColorAndDepth();
        
        SCPGFFUNC void clearAll();
    }
}

#endif /* F973E16E_C42F_400C_86EB_F395CA3B34F2 */
