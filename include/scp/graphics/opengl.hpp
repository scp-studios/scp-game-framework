#ifndef F973E16E_C42F_400C_86EB_F395CA3B34F2
#define F973E16E_C42F_400C_86EB_F395CA3B34F2

namespace scp::graphics
{
    namespace opengl
    {
        void enableContextDebugging();
        
        void enable2DBlending();
        
        void setClearColor(float red, float green, float blue, float alpha);
        
        void clearColor();
        
        void clearColorAndDepth();
        
        void clearAll();
    }
}

#endif /* F973E16E_C42F_400C_86EB_F395CA3B34F2 */
