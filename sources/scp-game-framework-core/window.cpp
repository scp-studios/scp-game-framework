#include "pch.hpp"

#include <glad/glad.h>

#include <scp/window.hpp>

using scp::window;

// The error callback for glfw
static void error_callback(int error_code, const char* message);

window& window::get_instance()
{
    get_instance(0, 0, "", false);
}





window& window::get_instance(uint32_t p_width, uint32_t p_height, std::string_view p_title, bool p_fullscreen, scp::graphics::api p_graphics_api)
{
    static window instance(p_width, p_height, p_title, p_fullscreen, p_graphics_api);
    return instance;
}




void window::show()
{
    glfwShowWindow(m_handle);
}




bool window::is_open()
{
    return !glfwWindowShouldClose(m_handle);
}




void window::swap_opengl_buffers()
{
    glfwSwapBuffers(m_handle);
}




void window::poll_events()
{
    glfwPollEvents();
}




uint32_t window::get_width()
{
    return m_data.m_width;
}




uint32_t window::get_height()
{
    return m_data.m_height;
}




window::~window()
{
    glfwDestroyWindow(m_handle);
    glfwTerminate();
}




window::window(uint32_t p_width, uint32_t p_height, std::string_view p_title, bool p_fullscreen, scp::graphics::api p_graphics_api)
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    glfwSetErrorCallback(error_callback);
    
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    if (p_graphics_api == scp::graphics::api::opengl)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    } else
    {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    }
    
    GLFWmonitor* monitor = nullptr;
    const GLFWvidmode* video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    if (p_fullscreen)
    {
        monitor = glfwGetPrimaryMonitor();
        m_data.m_width = video_mode->width;
        m_data.m_height = video_mode->height;
    } else
    {
        m_data.m_width = p_width;
        m_data.m_height = p_height;
    }
    
    m_handle = glfwCreateWindow(m_data.m_width, m_data.m_height, p_title.data(), monitor, nullptr);
    if (m_handle == nullptr)
    {
        throw std::runtime_error("Failed to create the GLFW window.");
    }
    
    glfwSetWindowUserPointer(m_handle, &m_data);
    
    if (p_graphics_api == scp::graphics::api::opengl)
    {
        glfwMakeContextCurrent(m_handle);
        
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            // TODO: Throw a custom exception to specify that glad OpenGL
            // has failed.
        }
        
        glfwSetFramebufferSizeCallback(m_handle, opengl_window_resize_callback);
    }
}




static void error_callback(int p_error_code, const char* p_message)
{
    std::cerr << "[GLFW ERROR " << p_error_code << "]: " << p_message << std::endl;
}




void window::opengl_window_resize_callback(GLFWwindow* p_window, int p_width, int p_height)
{
    window_data* data = reinterpret_cast<window_data*>(glfwGetWindowUserPointer(p_window));
    data->m_width = p_width;
    data->m_height = p_height;
    
    glViewport(0, 0, data->m_width, data->m_height);
}