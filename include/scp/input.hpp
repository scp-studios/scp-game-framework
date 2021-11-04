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
        
        // Returns whether the specified mouse button is pressed down
        bool is_button_down(int button_code);
        
        // Returns the total amount that has been scrolled
        uint32_t get_scroll_pos();
        
        // Returns the x and y position of the mouse position
        uint32_t get_mouse_x();
        uint32_t get_mouse_y();
        
        // Returns the mouse position of the mouse pointer
        mouse_position get_mouse_position();
        
        // Set the key callback. Uses the default callback function if
        // callback is equal to nullptr.
        void set_key_callback(GLFWkeyfun callback);
        
        // Set the mouse position callback. Uses the default callback function if
        // callback is equal to nullptr.
        void set_mouse_pos_callback(GLFWcursorposfun callback);
        
        // Set the mouse scroll callback. Uses the default callback function if
        // callback is equal to nullptr.
        void set_scroll_callback(GLFWscrollfun callback);
        
        // Set the mouse click callback. Uses the default callback function if
        // callback is equal to nullptr.
        void set_mouse_button_callback(GLFWmousebuttonfun callback);
        
        // The default input callbacks
        void default_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
        void default_cursor_pos_callback(GLFWwindow *window, double x_pos, double y_pos);
        void default_scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
        void default_mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    }
}

#endif /* BA3C753A_6897_4AA0_B3C5_F321D26B40E7 */
