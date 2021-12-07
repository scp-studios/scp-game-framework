#ifndef E1807A30_2BAB_4F2B_812D_33D2F4822F2F
#define E1807A30_2BAB_4F2B_812D_33D2F4822F2F

// Note: This not supposed to represent a Scene class that you would see in a
// game engine. It is supposed to be simply a container for a state in the 
// game and to handle stuff like events and stuff.

#include <scp/core-pch.hpp>

#include <scp/events.hpp>

namespace scp
{
    class Scene
    {
    public:
        // Default Constructor. It will serve as the "onCreate" function
        Scene() = default;
        
        // Templated version
        template<typename SceneType, typename... ArgTypes>
        void setActive(ArgTypes... args)
        {
            if (activeScene != nullptr)
            {
                delete activeScene;
            }
            
            activeScene = new SceneType(args...);
        }
        
        // Destructor. It will serve as the "onDestroy" function.
        virtual ~Scene() = default;
        
    private:
        // Called every iteration of the update thread
        virtual void onUpdate();
        
        // Rendering
        virtual void render();
        
        // Events
        virtual void onKeyPress(events::KeyPressEvent& event);
        virtual void onMouseClick(events::MouseButtonEvent& event);
        virtual void onMouseMove(events::MouseMoveEvent& event);
        virtual void onMouseScroll(events::MouseScrollEvent& event);
        
        // The currently active scene
        static Scene* activeScene;
    };
}

#endif /* E1807A30_2BAB_4F2B_812D_33D2F4822F2F */
