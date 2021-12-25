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
        
    };
}

#endif /* A4B50858_1312_4958_929D_53A03F80D5C8 */
