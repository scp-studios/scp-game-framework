#ifndef F973E16E_C42F_400C_86EB_F395CA3B34F2
#define F973E16E_C42F_400C_86EB_F395CA3B34F2

#include <scp/scp.hpp>

namespace scp::graphics
{
    namespace opengl
    {
        void SCPGFFUNC enableContextDebugging();
        
        void SCPGFFUNC enable2DBlending();
        
        void SCPGFFUNC setClearColor(float red, float green, float blue, float alpha);
        
        void SCPGFFUNC clearColor();
        
        void SCPGFFUNC clearColorAndDepth();
        
        void SCPGFFUNC clearAll();
    }
}

#endif /* F973E16E_C42F_400C_86EB_F395CA3B34F2 */
