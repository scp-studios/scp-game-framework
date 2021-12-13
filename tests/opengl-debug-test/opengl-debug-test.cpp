#include <scp/Window.hpp>
#include <scp/Scene.hpp>
#include <scp/graphics/opengl.hpp>
#include <glad/glad.h>

using scp::Window;
namespace opengl = scp::graphics::opengl;

class Application
{
public:
    Application(): window(Window::getInstance(Window::SCREEN_SIZE_TIMES_66_PERCENT, Window::SCREEN_SIZE_TIMES_66_PERCENT, "OpenGL Debug Test", false, scp::graphics::API::OpenGL, true))
    {
        scp::Scene::setActive<scp::Scene>();
        
        glBindBuffer(GL_UNSIGNED_INT, 44);
        
        window.show();
    }
    
    void update()
    {
        window.update();
    }
    
    bool isRunning()
    {
        return window.isOpen();
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
        
        while (app.isRunning())
        {
            app.update();
        }
    }
    catch (std::runtime_error& e)
    {
        std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}