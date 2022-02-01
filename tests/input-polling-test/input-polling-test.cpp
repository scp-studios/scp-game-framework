#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/Input.hpp>

using scp::Input;
using scp::Scene;
using scp::Window;

class MyScene: public scp::Scene
{
public:
    MyScene(): input(Input::getInstance())
    {
        
    }
    
    void onUpdate(double deltaTime) override
    {
        if (input.isKeyDown(GLFW_KEY_K))
        {
            std::cout << "Yes." << std::endl;
        } else
        {
            std::cout << "No." << std::endl;
        }
        
        scp::MousePosition mousePos = input.getMousePosition();
        std::cout << "Mouse pos: " << mousePos.x << " " << mousePos.y << std::endl;
        
        if (input.isMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT))
        {
            std::cout << "YAY" << std::endl;
        }
        
        std::cout << "Scroll thingy: " << input.getScrollY() << std::endl;
    }
private:
    Input& input;
};


class Application
{
public:
    Application()
    {
        Window& window = Window::getInstance();
        
        scp::Scene::setActive<MyScene>();
        
        window.show();
        
        while (window.isOpen())
        {
            Scene::updateActive(0.0);
            Scene::renderActive();
            
            window.update();
        }
    }
};



int main()
{
    try {
        Application app;
    } catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}