#ifndef FE657AE1_59F8_49BF_BC8F_ABC8C7A2A269
#define FE657AE1_59F8_49BF_BC8F_ABC8C7A2A269

// Macro for multiplying a specific row and colomn of this matrix.
#define SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(r, c, m1, m2) (m1[r][0] * m2[0][c]) + (m1[r][1] * m2[1][c]) + (m1[r][2] * m2[2][c]) + (m1[r][3] * m2[3][c])

namespace scp::math
{
    template<typename T>
    class Matrix4
    {
    public:
        // Default constructor
        Matrix4() = default;
        
        // Create an identity matrix
        Matrix4(T v)
        {
            m_data[0][0] = v;
            m_data[1][1] = v;
            m_data[2][2] = v;
            m_data[3][3] = v;
        }
        
        // Addition
        Matrix4 operator+(Matrix4& b)
        {
            Matrix4<T> result;
            result.m_data[0][0] = m_data[0][0] + b.m_data[0][0];
            result.m_data[0][1] = m_data[0][1] + b.m_data[0][1];
            result.m_data[0][2] = m_data[0][2] + b.m_data[0][2];
            result.m_data[0][3] = m_data[0][3] + b.m_data[0][3];
            
            result.m_data[1][0] = m_data[1][0] + b.m_data[1][0];
            result.m_data[1][1] = m_data[1][1] + b.m_data[1][1];
            result.m_data[1][2] = m_data[1][2] + b.m_data[1][2];
            result.m_data[1][3] = m_data[1][3] + b.m_data[1][3];
            
            result.m_data[2][0] = m_data[2][0] + b.m_data[2][0];
            result.m_data[2][1] = m_data[2][1] + b.m_data[2][1];
            result.m_data[2][2] = m_data[2][2] + b.m_data[2][2];
            result.m_data[2][3] = m_data[2][3] + b.m_data[2][3];
            
            result.m_data[3][0] = m_data[3][0] + b.m_data[3][0];
            result.m_data[3][1] = m_data[3][1] + b.m_data[3][1];
            result.m_data[3][2] = m_data[3][2] + b.m_data[3][2];
            result.m_data[3][3] = m_data[3][3] + b.m_data[3][3];
            
            return result;
        }
        
        // Subtraction
        Matrix4 operator-(Matrix4& b)
        {
            Matrix4<T> result;
            result.m_data[0][0] = m_data[0][0] - b.m_data[0][0];
            result.m_data[0][1] = m_data[0][1] - b.m_data[0][1];
            result.m_data[0][2] = m_data[0][2] - b.m_data[0][2];
            result.m_data[0][3] = m_data[0][3] - b.m_data[0][3];
            
            result.m_data[1][0] = m_data[1][0] - b.m_data[1][0];
            result.m_data[1][1] = m_data[1][1] - b.m_data[1][1];
            result.m_data[1][2] = m_data[1][2] - b.m_data[1][2];
            result.m_data[1][3] = m_data[1][3] - b.m_data[1][3];
            
            result.m_data[2][0] = m_data[2][0] - b.m_data[2][0];
            result.m_data[2][1] = m_data[2][1] - b.m_data[2][1];
            result.m_data[2][2] = m_data[2][2] - b.m_data[2][2];
            result.m_data[2][3] = m_data[2][3] - b.m_data[2][3];
            
            result.m_data[3][0] = m_data[3][0] - b.m_data[3][0];
            result.m_data[3][1] = m_data[3][1] - b.m_data[3][1];
            result.m_data[3][2] = m_data[3][2] - b.m_data[3][2];
            result.m_data[3][3] = m_data[3][3] - b.m_data[3][3];
            
            return result;
        }
        
        // Multiplication
        Matrix4 operator*(Matrix4& b)
        {
            Matrix4<T> result;
            result.m_data[0][0] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(0, 0, m_data, b.m_data);
            result.m_data[0][1] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(0, 1, m_data, b.m_data);
            result.m_data[0][2] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(0, 2, m_data, b.m_data);
            result.m_data[0][3] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(0, 3, m_data, b.m_data);
                        
            result.m_data[1][0] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(1, 0, m_data, b.m_data);
            result.m_data[1][1] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(1, 1, m_data, b.m_data);
            result.m_data[1][2] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(1, 2, m_data, b.m_data);
            result.m_data[1][3] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(1, 3, m_data, b.m_data);
                        
            result.m_data[2][0] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(2, 0, m_data, b.m_data);
            result.m_data[2][1] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(2, 1, m_data, b.m_data);
            result.m_data[2][2] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(2, 2, m_data, b.m_data);
            result.m_data[2][3] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(2, 3, m_data, b.m_data);
                        
            result.m_data[3][0] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(3, 0, m_data, b.m_data);
            result.m_data[3][1] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(3, 1, m_data, b.m_data);
            result.m_data[3][2] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(3, 2, m_data, b.m_data);
            result.m_data[3][3] = SCP_MATH_MULTIPLY_MATRIX_4_ROW_COLOMN(3, 3, m_data, b.m_data);
            
            return result;
        }
        
        // Addition again
        Matrix4& operator+=(Matrix4& b)
        {
            (*this) = (*this) + b;
            return *this;
        }
        
        // Subtraction again
        Matrix4& operator-=(Matrix4& b)
        {
            (*this) = (*this) - b;
            return *this;
        }
        
        // Multiplication again
        Matrix4& operator*=(Matrix4& b)
        {
            (*this) = (*this) * b;
            return *this;
        }
        
        // Get the raw matrix itself (for OpenGL)
        T* data()
        {
            return reinterpret_cast<T*>(m_data);
        }
        
    private:
        T m_data[4][4];
    };
}

#endif /* FE657AE1_59F8_49BF_BC8F_ABC8C7A2A269 */
