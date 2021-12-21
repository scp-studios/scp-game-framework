#ifndef A4B50858_1312_4958_929D_53A03F80D5C8
#define A4B50858_1312_4958_929D_53A03F80D5C8

#include "../Renderer2D.hpp"

namespace scp::graphics::opengl
{
    class Renderer2D: public scp::graphics::Renderer2D
    {
    public:
        // Basic default constructor for now. I will add more later on.
        Renderer2D();
        
        ~Renderer2D();
        
    private:
        // Add a sprite
        void addSpriteImpl(uint32_t width, uint32_t height, uint32_t uvOffsetX, uint32_t uvOffsetY) override;
        
        // Render everything in the batch
        void renderImpl() override;
    };
}

#endif /* A4B50858_1312_4958_929D_53A03F80D5C8 */
