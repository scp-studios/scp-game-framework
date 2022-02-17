#ifndef A4B50858_1312_4958_929D_53A03F80D5C8
#define A4B50858_1312_4958_929D_53A03F80D5C8

#include <scp/graphics/pch.hpp>

#include "../Renderer2D.hpp"

#include <scp/graphics/opengl/VertexArray.hpp>
#include <scp/graphics/opengl/ElementBuffer.hpp>
#include <scp/graphics/opengl/VertexBuffer.hpp>
#include <scp/graphics/opengl/Shader.hpp>
#include <scp/graphics/opengl/Texture2D.hpp>

namespace scp::graphics::opengl
{
    class SCPGFFUNC  Renderer2D: public scp::graphics::Renderer2D
    {
    public:
        // Basic default constructor for now. I will add more later on.
        Renderer2D(std::string_view shaderSource);
        
        // Add a texture
        void addTextureImpl(std::string_view path) override;
        
        // Add a texture from an array of bytes
        void addTextureImpl(std::vector<uint8_t> data, bool raw) override;
        
        // Begin drawing
        void beginImpl() override;
        
        // Draw a textured quad
        void drawTexturedQuadImpl(float width, float height, float posX, float posY, float uvRight, float uvLeft, float uvTop, float uvBottom, int8_t texture) override;
        
        // Draw a solid colored quad
        void drawSolidColoredQuadImpl(float width, float height, float posX, float posY, float red, float green, float blue, float alpha) override;
        
        // Draw a sprite
        void drawSpriteImpl(const Sprite& sprite) override;
        
        // Stop drawing
        void endImpl() override;
        
        virtual ~Renderer2D() {};
        
    private:
        // The shader. A single render batch can only have one shader so...
        Shader m_shader;
        
        // The vertex array
        VertexArray m_vertexArray;
        
        // The vertex buffer
        VertexBuffer m_vertexBuffer;
        
        // The element buffer
        ElementBuffer m_elementBuffer;
        
        // The textures
        std::vector<Texture2D> m_textures;
        
        // The offset of the write thingy
        uint32_t m_bufferOffset;
        
        // The offset of the index buffer
        uint32_t m_indexBufferOffset;
        
        // Offset of the indices
        uint32_t m_indexOffset;
        
        // Vertex offset (used by the indices as well)
        uint32_t m_vertexOffset;
        
        // The projection matrix
        math::Matrix4<float> m_projectionMatrix;
    };
}

#endif /* A4B50858_1312_4958_929D_53A03F80D5C8 */
