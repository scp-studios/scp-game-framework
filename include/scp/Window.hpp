#ifndef F9ADF020_F80C_4D0F_BE05_AEA0D5BBB0B3
#define F9ADF020_F80C_4D0F_BE05_AEA0D5BBB0B3

#include <scp/core-pch.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <scp/graphics/API.hpp>

namespace scp
{
    class Window
    {
    public:
        // Constructor
        Window(
            int32_t width = SCREEN_SIZE_TIMES_66_PERCENT, 
            int32_t height = SCREEN_SIZE_TIMES_66_PERCENT, 
            std::string_view title = "SCP Game Framework Window", 
            bool fullscreen = false, 
            graphics::API api = graphics::API::OpenGL
        );
        
        // Show the window
        void show();
        
        // Is the window still open?
        bool isOpen();
        
        // Get the window's width and height
        uint32_t getWidth();
        uint32_t getHeight();
        
        // Update the window
        void update();
        
        // Destructor
        ~Window();
        
        // Special values for window size
        static const int32_t SCREEN_SIZE = -1;
        static const int32_t HALF_SCREEN_SIZE = -2;
        static const int32_t SCREEN_SIZE_TIMES_66_PERCENT = -3;
        
    private:
        // The handle to the GLFW window
        GLFWwindow* m_window;
        
        // The graphics API that the window is using
        graphics::API m_graphicsAPI;
        
        // The window's width and height
        uint32_t m_width;
        uint32_t m_height;
        
        // TODO: Add event callbacks
    };
}

#endif /* F9ADF020_F80C_4D0F_BE05_AEA0D5BBB0B3 */
