#include <stdexcept>

#include <scp/Window.hpp>

using scp::Window;
using scp::graphics::API;

static void errorCallback(int p_code, const char* p_message)
{
    std::cerr << "[GLFW ERROR " << p_code << "]: " << p_message << std::endl;
}










Window::Window(int32_t p_width, int32_t p_height, std::string_view p_title, bool p_fullscreen, API p_graphicsAPI):
m_graphicsAPI(p_graphicsAPI)
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    if (p_graphicsAPI == API::OpenGL)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    // Determine the width of the window.
    if (p_width == SCREEN_SIZE)
    {
        m_width = videoMode->width;
    } 
    else if (m_width == HALF_SCREEN_SIZE)
    {
        m_width = videoMode->width / 2;
    }
    else if (m_width == SCREEN_SIZE_TIMES_66_PERCENT)
    {
        m_width = videoMode->width * 0.666666666666666666666666666667;
    }
    else
    {
        m_width = p_width;
    }
    
    // Determine the height of the window
    if (p_height == SCREEN_SIZE)
    {
        m_height = videoMode->height;
    }
    else if (p_height == HALF_SCREEN_SIZE)
    {
        m_height = videoMode->height / 2;
    }
    else if (p_height == SCREEN_SIZE_TIMES_66_PERCENT)
    {
        m_height = videoMode->height * 0.666666666666666666666666666667;
    }
    else
    {
        m_height = p_height;
    }
    
    GLFWmonitor* monitor = nullptr;
    
    // Determine if it is fullscreen
    if (p_fullscreen)
    {
        monitor = glfwGetPrimaryMonitor();
    }
    
    // Finally, create the window
    m_window = glfwCreateWindow(m_width, m_height, p_title.data(), monitor, nullptr);
    if (m_window == nullptr)
    {
        throw std::runtime_error("Failed to create the window.");
    }
    
    if (p_graphicsAPI == API::OpenGL)
    {
        glfwMakeContextCurrent(m_window);
    }
}










void Window::show()
{
    glfwShowWindow(m_window);
}










bool Window::isOpen()
{
    return !glfwWindowShouldClose(m_window);
}










uint32_t Window::getWidth()
{
    return m_width;
}










uint32_t Window::getHeight()
{
    return m_height;
}










void Window::update()
{
    if (m_graphicsAPI == API::OpenGL)
    {
        glfwSwapBuffers(m_window);
    }
    
    glfwPollEvents();
}










Window::~Window()
{
    glfwDestroyWindow(m_window);
}