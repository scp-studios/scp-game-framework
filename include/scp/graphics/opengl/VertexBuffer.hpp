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
        VertexBuffer(uint32_t size, unsigned int usage);
        
        // Construct a vertex buffer from an arbitrary vector
        template<typename T>
        VertexBuffer(std::vector<T> p_data, unsigned int usage = GL_STATIC_DRAW): m_usage(usage)
        {
            glGenBuffers(1, &m_handle);
            glBindBuffer(GL_ARRAY_BUFFER, m_handle);
            glBufferData(GL_ARRAY_BUFFER, p_data.size() * sizeof(T), p_data.data(), usage); // TODO: Might add a little optional thingy here
            
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
        void setData(std::vector<T> p_newData, unsigned int p_usage = GL_STATIC_DRAW)
        {
            bind();
            glBufferData(GL_ARRAY_BUFFER, p_newData.size() * sizeof(T), p_newData.data(), p_usage);
        }
        
        // Clear the buffer and allocate some space for new data
        void clearBuffer(uint32_t size, unsigned int usage = GL_STATIC_DRAW);
        
        // Swap two vertex buffers
        static void swap(VertexBuffer& a, VertexBuffer& b);
        
        // Set a subset of the buffer to a data specified
        template<typename T>
        void setSubData(std::vector<T> p_data, uint32_t p_offset)
        {
            bind();
            glBufferSubData(GL_ARRAY_BUFFER, p_offset, p_data.size() * sizeof(T), p_data.data());
        }
        
        // Destructor
        ~VertexBuffer();
        
    private:
        unsigned int m_handle;
        
        // How the buffer is going to be used
        unsigned int m_usage;
        
        // Move ownership from another vertex buffer
        void moveFrom(VertexBuffer& src);
        
        // Destroy this buffer
        void destroy();
    };
}

#endif /* CD895C87_5211_435E_820F_54EDC3B94158 */
