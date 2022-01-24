#include "Matrix4.hpp"

namespace scp::math
{
    namespace projections
    {
        template<typename T>
        Matrix4<T> orthgraphic(T right, T left, T top, T bottom, T far, T near)
        {
            Matrix4<T> result(1.0);
            
            result.m_data[0][0] = 2 / (right - left);
            result.m_data[0][1] = 0;
            result.m_data[0][2] = 0;
            result.m_data[0][3] = -((right + left) / (right - left));
            
            result.m_data[1][0] = 0;
            result.m_data[1][1] = 2 / (top - bottom);
            result.m_data[1][2] = 0;
            result.m_data[1][3] = -((top + bottom) / (top - bottom));
            
            result.m_data[2][0] = 0;
            result.m_data[2][1] = 0;
            result.m_data[2][2] = -2 / (far - near);
            result.m_data[2][3] = -((far + near) / (far - near));
            
            result.m_data[3][0] = 0;
            result.m_data[3][1] = 0;
            result.m_data[3][2] = 0;
            result.m_data[3][3] = 1;
            
            return result;
        }
    }
}