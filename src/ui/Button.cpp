#include <scp/Input.hpp>
#include <GLFW/glfw3.h>

#include <scp/ui/Button.hpp>

using scp::ui::Button;

Button::Button(double right, double left, double top, double bottom):
               m_right(right),
               m_left(left),
               m_top(top),
               m_bottom(bottom),
               m_input(Input::getInstance())
{
    
}

bool Button::isClicked()
{
    return isHovering() && m_input.isMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT);
}

bool Button::isHovering()
{
    double mouseX = m_input.getMouseX();
    double mouseY = m_input.getMouseY();
    
    bool xIntersect = (mouseX >= m_left) && (mouseX <= m_right);
    bool yIntersect = (mouseY >= m_top) && (mouseY <= m_bottom);
    
    return xIntersect && yIntersect;
}

void Button::move(double x, double y)
{
    m_right += x;
    m_left += x;
    
    m_top += y;
    m_bottom += y;
}