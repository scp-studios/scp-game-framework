#ifndef DB62E672_4026_45F9_BCDD_D5FB31A75EB5
#define DB62E672_4026_45F9_BCDD_D5FB31A75EB5

namespace scp::math
{
    template <typename T>
    class Vector4
    {
    public:
        // Constructor
        Vector4(): x(0), y(0), z(0), w(0)
        {
            
        }
        
        Vector4(T s): x(s), y(s), z(s), w(s)
        {
            
        }
        
        Vector4(T p_x, T p_y): x(p_x), y(p_y), z(p_x), w(p_y)
        {
            
        }
        
        Vector4(T p_x, T p_y, T p_z): x(p_x), y(p_y), z(p_z), w(0)
        {
            
        }
        
        Vector4(T p_x, T p_y, T p_z, T p_w): x(p_x), y(p_y), z(p_z), w(p_w)
        {
            
        }
        
        // More stuff coming soon
        // ...
        
        T x;
        T y;
        T z;
        T w;
    };
}

#endif /* DB62E672_4026_45F9_BCDD_D5FB31A75EB5 */
