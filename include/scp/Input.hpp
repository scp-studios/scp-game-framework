#ifndef A6A504A9_D986_437F_826D_C47BAB47380E
#define A6A504A9_D986_437F_826D_C47BAB47380E

namespace scp
{
    // A simple input class meant for input polling.
    
    // Input class. The reason that this is in a class is because different
    // windows will have different input objects
    
    class Window;
    
    struct MousePosition
    {
        double x;
        double y;
    };
    
    class Input
    {
    public:
        // Constructor
        Input(Window& window);
        
        // Is the key down?
        bool isKeyDown(int keycode) const;
        
        // Is the specified mouse button down?
        bool isMouseButtonDown(int mouseButton) const;
        
        // Gets the mouse position
        MousePosition getMousePosition() const;
        
        // Gets the mouse x and y positions respectively
        double getMouseX() const;
        double getMouseY() const;
        
        // Get the total scroll amount (X and Y respectively)
        double getScrollX() const;
        double getScrollY() const;
        
    private:
        // The window that the class is polling input from
        Window& m_window;
    };
}

#endif /* A6A504A9_D986_437F_826D_C47BAB47380E */
