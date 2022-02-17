#ifndef F553A752_8478_43FE_9779_EE92C3815FD3
#define F553A752_8478_43FE_9779_EE92C3815FD3

// Basically, a list of events that will be used. They are currently all
// structs because I don't know what kind of method an event object
// would need.

#include <scp/scp.hpp>

namespace scp::events
{
    struct SCPGFFUNC  KeyPressEvent
    {
        int m_key;
        int m_scancode;
        int m_action;
        int m_mods;
    };
    
    
    
    
    
    
    
    
    
    struct SCPGFFUNC  MouseButtonEvent
    {
        int m_button;
        int m_action;
        int m_mods;
    };
    
    
    
    
    
    
    
    
    
    struct SCPGFFUNC  MouseMoveEvent
    {
        double m_x;
        double m_y;
    };
    
    
    
    
    
    
    
    
    
    struct SCPGFFUNC  MouseScrollEvent
    {
        double m_xoffset;
        double m_yoffset;
    };
}

#endif /* F553A752_8478_43FE_9779_EE92C3815FD3 */
