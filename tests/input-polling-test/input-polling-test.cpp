#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/Input.hpp>

using scp::Input;
using scp::Scene;

class MyScene: public scp::Scene
{
public:
    MyScene(Input& p_input): input(p_input)
    {
        
    }
    
    void onUpdate() override
    {
        if (input.isKeyDown(GLFW_KEY_F))
        {
            std::cout << "Yes!" << std::endl;
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
    // Not the best way to do things, but, hey, this is just a test.
    Input& input;
};


class Application
{
public:
    Application(): input(window)
    {
        scp::Scene::setActive<MyScene>(input);
        
        window.show();
        
        while (window.isOpen())
        {
            Scene::updateActive();
            Scene::renderActive();
            
            window.update();
        }
    }
    
    ~Application()
    {
        
    }
private:
    scp::Window window;
    
    scp::Input input;
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