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
        // The input class is a friend because it needs to access the private
        // window handle
        friend class Input;
        
        // The get instance thingy
        static Window& getInstance(
            int32_t width = SCREEN_SIZE_TIMES_66_PERCENT, 
            int32_t height = SCREEN_SIZE_TIMES_66_PERCENT, 
            std::string_view title = "SCP Game Framework Window", 
            bool fullscreen = false, 
            graphics::API api = graphics::API::OpenGL
        );
        
        // Delete these constructors, since we don't want to be able to create
        // a copy of a Window
        Window(Window& src) = delete;
        Window(Window&&) = delete;
        
        // Show the window
        void show() const;
        
        // Is the window still open?
        bool isOpen() const;
        
        // Get the window's width and height
        uint32_t getWidth() const;
        uint32_t getHeight() const;
        
        // Update the window
        void update() const;
        
        // Destructor
        ~Window();
        
        // Special values for window size
        static const int32_t SCREEN_SIZE = -1;
        static const int32_t HALF_SCREEN_SIZE = -2;
        static const int32_t SCREEN_SIZE_TIMES_66_PERCENT = -3;
        
    private:
        // Constructor
        Window(
            int32_t width, 
            int32_t height, 
            std::string_view, 
            bool fullscreen,
            graphics::API api
        );
        
        // The handle to the GLFW window
        GLFWwindow* m_window;
        
        // The graphics API that the window is using
        graphics::API m_graphicsAPI;
        
        // The window's width and height
        uint32_t m_width;
        uint32_t m_height;
        
        // The total amount that has been scrolled (Needs to be stored here
        // because GLFW doesn't have scroll polling functions)
        double m_totalScrollAmountX;
        double m_totalScrollAmountY;
        
        // The event callbacks
        static void keyCallback(GLFWwindow* window, int keycode, int scancode, int action, int mods);
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void mousePosCallback(GLFWwindow* window, double x, double y);
        static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
        
        // The window resize callback
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    };
}

#endif /* F9ADF020_F80C_4D0F_BE05_AEA0D5BBB0B3 */
