#ifndef BA3C753A_6897_4AA0_B3C5_F321D26B40E7
#define BA3C753A_6897_4AA0_B3C5_F321D26B40E7

#include <GLFW/glfw3.h>

namespace scp
{
    namespace input
    {
        // The position of the mouse cursor
        struct mouse_position
        {
            uint32_t x;
            uint32_t y;
        };
        
        // Returns wether the passed key is pressed down or not
        bool is_key_down(int key_code);
        
        // Returns the total amount that has been scrolled
        uint32_t get_scroll_pos();
        
        // Returns the x and y position of the mouse position
        uint32_t get_mouse_x();
        uint32_t get_mouse_y();
        
        // Returns the mouse position of the mouse pointer
        mouse_position get_mouse_position();
        
        // Set the key callback
        void set_key_callback(GLFWkeyfun callback);
        
        // Set the mouse position callback
        void set_mouse_pos_callback(GLFWcursorposfun callback);
        
        // Set the mouse scroll callback
        void set_scroll_callback(GLFWscrollfun callback);
    }
}

#endif /* BA3C753A_6897_4AA0_B3C5_F321D26B40E7 */
