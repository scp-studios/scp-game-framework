#ifndef CA18CFBE_60C5_4B2C_8FAA_24DBFCB63838
#define CA18CFBE_60C5_4B2C_8FAA_24DBFCB63838

#include <string_view>
#include <stdint.h>
#include <GLFW/glfw3.h>
#include <scp/graphics/api.hpp>

namespace scp
{
    struct window_data
    {
        uint32_t m_width;
        uint32_t m_height;
    };
    
    class window
    {
    public:
        // Obtain the instance of this class
        window& get_instance();
        window& get_instance(uint32_t width, uint32_t height, std::string_view title, bool fullscreen, graphics::api graphics_api = graphics::api::opengl);
        
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
