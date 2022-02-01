#ifndef B75DB157_5D6D_4EAF_9D64_7CD1F1307D4F
#define B75DB157_5D6D_4EAF_9D64_7CD1F1307D4F

#include <scp/math.hpp>

namespace scp::math
{
    namespace transformations
    {
        template<typename T>
        Matrix4<T> scale(Matrix4<T> m, Vector3<T> v)
        {
            Matrix4<T> scaleMatrix(1.0);
            scaleMatrix.m_data[0][0] = v.x;
            scaleMatrix.m_data[1][1] = v.y;
            scaleMatrix.m_data[2][2] = v.z;
            
            return scaleMatrix * m;
        }
        
        template<typename T>
        Matrix4<T> scale(Matrix4<T> m, Vector2<T> v)
        {
            Matrix4<T> scaleMatrix(1.0);
            scaleMatrix.m_data[0][0] = v.x;
            scaleMatrix.m_data[1][1] = v.y;
            
            return scaleMatrix * m;
        }
        
        template<typename T>
        Matrix4<T> translate(Matrix4<T> m, Vector3<T> v)
        {
            Matrix4<T> translateMatrix(1.0);
            translateMatrix.m_data[0][3] = v.x;
            translateMatrix.m_data[1][3] = v.y;
            translateMatrix.m_data[2][3] = v.z;
            
            return translateMatrix * m;
        }
        
        template<typename T>
        Matrix4<T> translate(Matrix4<T> m, Vector2<T> v)
        {
            Matrix4<T> translateMatrix(1.0);
            translateMatrix.m_data[0][3] = v.x;
            translateMatrix.m_data[1][3] = v.y;
            
            return translateMatrix * m;
        }
    }
}

#endif /* B75DB157_5D6D_4EAF_9D64_7CD1F1307D4F */
