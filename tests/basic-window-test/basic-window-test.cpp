#include <scp/Window.hpp>

using scp::Window;

int main()
{
    std::cout << "[INFO]: Hello!" << std::endl;
    
    Window window(Window::SCREEN_SIZE_TIMES_66_PERCENT, Window::SCREEN_SIZE_TIMES_66_PERCENT, "Basic Window Test");
    
    window.show();
    
    while (window.isOpen())
    {
        window.update();
    }
}