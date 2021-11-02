#include "pch.hpp"

#include <scp/window.hpp>

using scp::window;

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
        // TODO: Throw an exception
    }
    
    
}