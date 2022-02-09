#ifndef A7FFA03B_A3C7_4F60_80C5_E21AC09F6508
#define A7FFA03B_A3C7_4F60_80C5_E21AC09F6508

namespace scp
{
    class Input;
}

namespace scp::ui
{
    // This is a button. It represents an object that can be clicked by the us-
    // er. It can also detect hovering. It is currently tied to one specific w-
    // indowing system though.
    class Button
    {
    public:
        // Create a button with the specified boundaries. I've set the default 
        // value all to 100 for obvious reasons. Of course, that doesn't mean
        // that you can't set it to something else.
        // The reason that I've chose to use doubles is mainly for stuff such 
        // as when the object moves by a fraction of a unit, rather than round-
        // ing to 0 and not moving at all, have the data be appended anyways.
        Button(double right = 100.0, double left = 100.0, double top = 100.0, double bottom = 100.0);
        
        // Check if the button is clicked
        bool isClicked();
        
        // Check if the mouse is hovering over the button
        bool isHovering();
        
        // Move the button by a certain amount
        void move(double x, double y);
        
        // Currently, I don't see any reasons why you would want to change the 
        // size of the button, since UI elements are mainly static.
        
    private:
        // Right, left, top, and bottom boundaries
        double m_right;
        double m_left;
        double m_top;
        double m_bottom;
        
        // The input instance.
        Input& m_input;
    };
}

#endif /* A7FFA03B_A3C7_4F60_80C5_E21AC09F6508 */
