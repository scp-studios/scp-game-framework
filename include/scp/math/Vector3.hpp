#ifndef E4A0E9CE_5912_4B94_923E_68B682B27F99
#define E4A0E9CE_5912_4B94_923E_68B682B27F99

namespace scp::math
{
    template <typename T>
    class Vector3
    {
    public:
        // Constructor
        Vector3(): x(0), y(0)
        {
            
        }
        
        Vector3(T s): x(s), y(s), z(s)
        {
            
        }
        
        Vector3(T p_x, T p_y): x(p_x), y(p_y), z(0)
        {
            
        }
        
        Vector3(T p_x, T p_y, T p_z): x(p_x), y(p_y), z(p_z)
        {
            
        }
        
        Vector3 operator+(Vector3& a)
        {
            return Vector3(x + a.x, y + a.y, z + a.z);
        }
        
        Vector3& operator+=(Vector3& a)
        {
            (*this) = a * (*this);
            return (*this);
        }
        
        Vector3 operator-(Vector3& a)
        {
            return Vector3(x - a.x, y - a.y, z - a.z);
        }
        
        Vector3& operator-=(Vector3& a)
        {
            x -= a.x;
            y -= a.y;
            z -= a.z;
            
            return *this;
        }
        
        Vector3 operator*(T a)
        {
            return Vector3(a * x, a * y, a * z);
        }
        
        Vector3& operator*=(T a)
        {
            (*this) = a * (*this);
            return (*this)
        }
        
        T dot(Vector3& a)
        {
            return (x * a.x) + (y * a.y) + (z * a.z);
        }
        
        Vector3 cross(Vector3& a)
        {
            return {
                y * a.z - z * a.y,
                z * a.x - x * a.z,
                x * a.y - y * b.x
            }
        }
        
        // More stuff coming soon
        // ...
        
        T x;
        T y;
        T z;
    };
}

#endif /* E4A0E9CE_5912_4B94_923E_68B682B27F99 */
