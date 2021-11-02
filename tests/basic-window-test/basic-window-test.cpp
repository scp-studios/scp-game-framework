#include <scp/window.hpp>

int main(int argc, char** argv)
{
    scp::window& window = scp::window::get_instance(1280, 720, "Basic Window Test", true);
    
    window.show();
    
    while (window.is_open())
    {
        window.swap_opengl_buffers();
        window.poll_events();
    }
}