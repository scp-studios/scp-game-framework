#include <scp/Window.hpp>
#include <scp/Scene.hpp>

using scp::Window;
using scp::Scene;

int main()
{
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window window(Window::SCREEN_SIZE_TIMES_66_PERCENT, Window::SCREEN_SIZE_TIMES_66_PERCENT, "Basic Window Test");
    
    Scene::setActive<Scene>();
    
    window.show();
    
    while (window.isOpen())
    {
        window.update();
    }
}