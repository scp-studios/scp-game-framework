#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/graphics/Renderer2D.hpp>
#include <scp/graphics/API.hpp>

using scp::Window;
using scp::Scene;
using scp::graphics::Renderer2D;
using scp::graphics::API;

class MyScene: public Scene
{
public:
    MyScene(): renderer(API::OpenGL, "")
    {
        
    }
    
    void onUpdate() override
    {
        
    }
    
    void render() override
    {
        
    }
private:
    Renderer2D renderer;
};

class Application
{
public:
    Application(): window(Window::getInstance())
    {
        Scene::setActive<MyScene>();
    }
    
    void mainLoop()
    {
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
    Window& window;
};

int main()
{
    try
    {
        Application app;
        app.mainLoop();
    } catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}