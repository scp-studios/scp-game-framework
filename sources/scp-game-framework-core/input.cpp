#include "pch.hpp"

#include <scp/window.hpp>

#include <scp/input.hpp>

// The position of the scroll wheel
static double scroll_pos = 0;

// The state of every key (either pressed or not pressed)
static std::vector<bool> keys(GLFW_KEY_LAST);

// The state of every mouse button (either clicked or not clicked)
static std::vector<bool> mouse_buttons(GLFW_MOUSE_BUTTON_LAST);

// The position of the mouse cursor.
static scp::input::mouse_position mouse_position_var = { 0, 0 };




bool scp::input::is_key_down(int p_key_code)
{
    return keys[p_key_code];
}




bool scp::input::is_button_down(int p_button_code)
{
    return mouse_buttons[p_button_code];
}




uint32_t scp::input::get_scroll_pos()
{
    return scroll_pos;
}




uint32_t scp::input::get_mouse_x()
{
    return mouse_position_var.x;
}




uint32_t scp::input::get_mouse_y()
{
    return mouse_position_var.y;
}




#define THE_THING window::get_instance().m_handle, p_callback
#define THE_WINDOW_HANDLE window::get_instance().m_handle




void scp::input::set_key_callback(GLFWkeyfun p_callback)
{
    if (p_callback != nullptr)
    {
        glfwSetKeyCallback(THE_THING);
    } else
    {
        glfwSetKeyCallback(THE_WINDOW_HANDLE, default_key_callback);
    }
}




void scp::input::set_mouse_pos_callback(GLFWcursorposfun p_callback)
{
    if (p_callback != nullptr)
    {
        glfwSetCursorPosCallback(THE_THING);
    } else
    {
        glfwSetCursorPosCallback(THE_WINDOW_HANDLE, default_cursor_pos_callback);
    }
}




void scp::input::set_scroll_callback(GLFWscrollfun p_callback)
{
    if (p_callback != nullptr)
    {
        glfwSetScrollCallback(THE_THING);
    } else
    {
        glfwSetScrollCallback(THE_WINDOW_HANDLE, default_scroll_callback);
    }
}




void scp::input::set_mouse_button_callback(GLFWmousebuttonfun p_callback)
{
    if (p_callback != nullptr)
    {
        glfwSetMouseButtonCallback(THE_THING);
    } else
    {
        glfwSetMouseButtonCallback(THE_WINDOW_HANDLE, default_mouse_button_callback);
    }
}




void scp::input::default_key_callback(GLFWwindow* p_window, int p_key, int p_scancode, int p_action, int p_mods)
{
    if (p_action == GLFW_PRESS)
    {
        keys[p_key] = true;
    } else if (p_action == GLFW_RELEASE)
    {
        keys[p_key] = false;
    }
}




void scp::input::default_cursor_pos_callback(GLFWwindow* p_window, double p_x_pos, double p_y_pos)
{
    mouse_position_var.x = p_x_pos;
    mouse_position_var.y = p_y_pos;
}




void scp::input::default_scroll_callback(GLFWwindow* p_window, double xoffset, double yoffset)
{
    scroll_pos = yoffset;
}




void scp::input::default_mouse_button_callback(GLFWwindow* p_window, int p_button, int p_action, int p_mods)
{
    if (p_action == GLFW_PRESS)
    {
        mouse_buttons[p_button] = true;
    } else if (p_action == GLFW_RELEASE)
    {
        mouse_buttons[p_button] = false;
    }
}