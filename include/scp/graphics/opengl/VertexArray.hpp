#ifndef C2D1568D_0C6A_4C71_99DE_AD81C89BF23F
#define C2D1568D_0C6A_4C71_99DE_AD81C89BF23F

#include <scp/graphics/VertexLayout.hpp>
#include <scp/graphics/opengl/VertexBuffer.hpp>

#include "../pch.hpp"

namespace scp::graphics::opengl
{
    class VertexArray
    {
    public:
        VertexArray();
        
        // Vertex arrays are considered part of the pipeline, therefore 
        // they are not really copiable
        VertexArray(VertexArray&) = delete;
        VertexArray& operator=(VertexArray&) = delete;
        
        // Move constructor
        VertexArray(VertexArray&& src);
        
        // Move assignment operator
        VertexArray& operator=(VertexArray&& rhs);
        
        // Add a vertex attribute
        void addAttribute(uint8_t index, VertexBuffer& buffer, VertexLayout& layout);
        
        // Bind
        void bind() const;
        
        // Unbind
        void unbind() const;
        
        // Destructor
        ~VertexArray();
    private:
        // The actual handle
        unsigned int m_handle;
        
        // Move ownership over here from another VertexArray
        void moveFrom(VertexArray& src);
    };
}

#endif /* C2D1568D_0C6A_4C71_99DE_AD81C89BF23F */
