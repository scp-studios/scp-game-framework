#ifndef CD895C87_5211_435E_820F_54EDC3B94158
#define CD895C87_5211_435E_820F_54EDC3B94158

#include <scp/graphics/pch.hpp>

namespace scp::graphics::opengl
{
    class VertexBuffer
    {
    public:
        VertexBuffer() = default;
        
        // Construct an empty vertex buffer with the specified size
        VertexBuffer(uint32_t size);
        
        // Construct a vertex buffer from an arbitrary vector
        template<typename T>
        VertexBuffer(std::vector<T> p_data)
        {
            glGenBuffers(1, &m_handle);
            glBindBuffer(GL_ARRAY_BUFFER, m_handle);
            glBufferData(GL_ARRAY_BUFFER, p_data.size() * sizeof(T), p_data.data(), GL_STATIC_DRAW); // TODO: Might add a little optional thingy here
            
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
        
        // Copy constructor
        VertexBuffer(VertexBuffer& src);
        
        // Copy assignment operator
        VertexBuffer& operator=(VertexBuffer& src);
        
        // Move constructor
        VertexBuffer(VertexBuffer&& src);
        
        // Move assignment operator
        VertexBuffer& operator=(VertexBuffer&& src);
        
        // Bind the buffer
        void bind() const;
        
        // Unbind the buffer
        void unbind() const;
        
        // Set the data to an arbitrary vector
        template<typename T>
        void setData(std::vector<T> p_newData)
        {
            bind();
            glBufferData(GL_ARRAY_BUFFER, p_newData.size() * sizeof(T), p_newData.data(), GL_STATIC_DRAW);
            unbind();
        }
        
        // Swap two vertex buffers
        static void swap(VertexBuffer& a, VertexBuffer& b);
        
        // Set a subset of the buffer to a data specified
        template<typename T>
        void setSubData(std::vector<T> p_data, uint32_t p_offset)
        {
            bind();
            glBufferSubData(GL_ARRAY_BUFFER, p_offset, p_data.size() * sizeof(T), p_data.data());
            unbind();
        }
        
        // Destructor
        ~VertexBuffer();
        
    private:
        unsigned int m_handle;
        
        // Move ownership from another vertex buffer
        void moveFrom(VertexBuffer& src);
        
        // Destroy this buffer
        void destroy();
    };
}

#endif /* CD895C87_5211_435E_820F_54EDC3B94158 */
