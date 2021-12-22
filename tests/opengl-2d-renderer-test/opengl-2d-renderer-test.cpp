#include <stdlib.h>

#include <glad/glad.h>

#include <scp/Window.hpp>
#include <scp/Scene.hpp>

#include <scp/graphics/opengl.hpp>
#include <scp/graphics/Renderer2D.hpp>
#include <scp/graphics/API.hpp>

using scp::Window;
using scp::Scene;

using scp::graphics::Renderer2D;

class MyScene: public Scene
{
public:
    MyScene(): renderer(scp::graphics::API::OpenGL)
    {
        renderer.addSprite(1, 1, 0, 0);
    }
    
    void onUpdate() override
    {
        
    }
    
    void render() override
    {
        renderer.render();
    }
    
    ~MyScene()
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
        scp::graphics::opengl::enableContextDebugging();
        
        Scene::setActive<MyScene>();
        
        window.show();
        
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        
        while (window.isOpen())
        {
            Scene::updateActive();
            
            glClear(GL_COLOR_BUFFER_BIT);
            
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
    //#ifdef DO_NOT_DEFINE_THIS_MACRO_OR_ELSE_I_WILL_COME_OVER_TO_YOUR_HOUSE_AND_BEAT_YOU_WITH_A_BAT
    try
    {
        Application app;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    //#endif
    
    //std::cout << scp::utils::string_utils::startsWith("Hello World!", "Hello");
    
    return EXIT_SUCCESS;
}