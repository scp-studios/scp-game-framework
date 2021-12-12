#include <scp/Window.hpp>

#include <scp/Input.hpp>

using scp::Window;
using scp::Input;

Input& Input::getInstance()
{
    static Input input;
    return input;
}










Input::Input(): m_window(Window::getInstance())
{
    
}










bool Input::isKeyDown(int p_key) const
{
    return glfwGetKey(m_window.m_window, p_key);
}










bool Input::isMouseButtonDown(int p_mouseButton) const
{
    return glfwGetMouseButton(m_window.m_window, p_mouseButton);
}










scp::MousePosition Input::getMousePosition() const
{
    scp::MousePosition result = {};
    glfwGetCursorPos(m_window.m_window, &result.x, &result.y);
    
    return result;
}










double Input::getMouseX() const
{
    return getMousePosition().x;
}










double Input::getMouseY() const
{
    return getMousePosition().y;
}










double Input::getScrollX() const
{
    return m_window.m_totalScrollAmountX;
}










double Input::getScrollY() const
{
    return m_window.m_totalScrollAmountY;
}