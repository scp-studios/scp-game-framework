#ifndef A4B50858_1312_4958_929D_53A03F80D5C8
#define A4B50858_1312_4958_929D_53A03F80D5C8

#include "../Renderer2D.hpp"

#include <scp/graphics/opengl/VertexArray.hpp>
#include <scp/graphics/opengl/ElementBuffer.hpp>
#include <scp/graphics/opengl/VertexBuffer.hpp>
#include <scp/graphics/opengl/Shader.hpp>

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
        uint64_t addSpriteImpl(uint32_t width, uint32_t height, float uvOffsetX, float uvOffsetY) override;
        
        // Render everything in the batch
        void renderImpl() override;
        
        // The shader
        Shader m_shader;
        
        // The vertex array
        VertexArray m_vertexArray;
        
        // The vertex buffer
        VertexBuffer m_vertexBuffer;
        
        // The element buffer of the render batch
        ElementBuffer m_elementBuffer;
        
        // Next sprite id. We are using an incremental system to identify sprites
        uint64_t m_nextSpriteID;
        
        // The amount of elements there is to draw.
        uint32_t m_numberOfElements;
    };
}

#endif /* A4B50858_1312_4958_929D_53A03F80D5C8 */
