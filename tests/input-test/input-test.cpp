#include <scp/input.hpp>
#include <scp/window.hpp>

#include <iostream>

int main()
{
    scp::window window = scp::window::get_instance(1280, 720, "Input Test", false);
    
    scp::input::set_key_callback(nullptr);
    scp::input::set_mouse_button_callback(nullptr);
    scp::input::set_mouse_pos_callback(nullptr);
    scp::input::set_scroll_callback(nullptr);
    
    window.show();
    
    while (window.is_open())
    {
        if (scp::input::is_key_down(GLFW_KEY_K))
        {
            std::cout << "K is pressed down!" << std::endl;
        }
        
        if (scp::input::is_button_down(GLFW_MOUSE_BUTTON_LEFT))
        {
            std::cout << "The mouse is clicked!" << std::endl;
        }
        
        std::cout << "The mouse is scrolled at " << scp::input::get_scroll_pos() << std::endl;
        
        scp::input::mouse_position mouse_position = scp::input::get_mouse_position();
        std::cout << "The mouse pointer is at (" << mouse_position.x << ", " << mouse_position.y << ")\n";
        
        window.swap_opengl_buffers();
        window.poll_events();
    }
}