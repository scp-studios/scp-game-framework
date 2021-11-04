#ifndef CA18CFBE_60C5_4B2C_8FAA_24DBFCB63838
#define CA18CFBE_60C5_4B2C_8FAA_24DBFCB63838

#include <string_view>
#include <stdint.h>

#include <GLFW/glfw3.h>

#include <scp/graphics/api.hpp>
#include <scp/input.hpp>

namespace scp
{
    
    struct window_data
    {
        uint32_t m_width;
        uint32_t m_height;
    };
    
    class window
    {
        // Input friend functions
        friend bool input::is_key_down(int key_code);
        friend uint32_t input::get_scroll_pos();
        friend uint32_t input::get_mouse_x();
        friend uint32_t input::get_mouse_y();
        friend input::mouse_position input::get_mouse_position();
        friend void input::set_key_callback(GLFWkeyfun callback);
        friend void input::set_mouse_pos_callback(GLFWcursorposfun callback);
        friend void input::set_scroll_callback(GLFWscrollfun callback);
        friend void input::set_mouse_button_callback(GLFWmousebuttonfun callback);
        
    public:
        // Obtain the instance of this class
        static window& get_instance();
        static window& get_instance(uint32_t width, uint32_t height, std::string_view title, bool fullscreen, graphics::api graphics_api = graphics::api::opengl);
        
        void show();
        
        bool is_open();
        
        // Note: This function is specifc to OpenGL
        void swap_opengl_buffers();
        
        void poll_events();
        
        uint32_t get_width();
        
        uint32_t get_height();
        
        ~window();
    
    private:
        // Constructor is private since this is a singleton class
        window(uint32_t width, uint32_t height, std::string_view title, bool fullscreen, scp::graphics::api p_graphics_api);
        
        // Data of the window.
        window_data m_data;
        
        // Window resize callback, specific to OpenGL
        static void opengl_window_resize_callback(GLFWwindow* window, int width, int height);
        
        // The handle to the GLFW window.
        GLFWwindow* m_handle;
    };
}

#endif /* CA18CFBE_60C5_4B2C_8FAA_24DBFCB63838 */
