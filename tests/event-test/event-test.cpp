#include <scp/Scene.hpp>
#include <scp/Window.hpp>
#include <scp/events.hpp>

#include <iostream>

using scp::Window;
using scp::Scene;

class MyScene: public scp::Scene
{
public:
    MyScene()
    {
        std::cout << "[INFO]: Hello!" << std::endl;
    }
    
    void onKeyPress(scp::events::KeyPressEvent& event) override
    {
        if (event.m_action == GLFW_PRESS && event.m_key == GLFW_KEY_K)
        {
            std::cout << "[INFO]: The K key has been pressed!" << std::endl;
        }
    }
    
    void onMouseClick(scp::events::MouseButtonEvent& event) override
    {
        if (event.m_action == GLFW_PRESS && event.m_button == GLFW_MOUSE_BUTTON_LEFT)
        {
            std::cout << "[INFO]: Left mouse button click!" << std::endl;
        }
    }
    
    void onMouseMove(scp::events::MouseMoveEvent& event) override
    {
        std::cout << "[INFO]: The mouse is now at " << event.m_x << ", " << event.m_y << std::endl;
    }
    
    void onMouseScroll(scp::events::MouseScrollEvent& event) override
    {
        std::cout << "[INFO]: The mouse has scrolled " << event.m_yoffset << std::endl;
    }
    
    ~MyScene()
    {
        std::cout << "[INFO]: Goodbye!" << std::endl;
    }
};

class Application
{
public:
    Application()
    {
        window = &Window::getInstance();
        
        Scene::setActive<MyScene>();
        
        window->show();
        
        while (window->isOpen())
        {
            window->update();
        }
    }
    
    ~Application()
    {
        
    }
    
private:
    Window* window;
};

int main()
{
    try
    {
        Application app;
    } catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
    }
}