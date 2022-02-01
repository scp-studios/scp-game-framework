#ifndef B9DA7D99_3006_4336_A745_BDC23E2A82CE
#define B9DA7D99_3006_4336_A745_BDC23E2A82CE
#ifndef A46370AF_0A1E_4016_8C0E_D78CE0806670
#define A46370AF_0A1E_4016_8C0E_D78CE0806670

namespace scp::math
{
    template<typename T>
    class Vector4;
    
    template <typename T>
    class Vector2
    {
    public:
        // Constructor
        Vector2(): x(0), y(0)
        {
            
        }
        
        Vector2(T s): x(s), y(s)
        {
            
        }
        
        Vector2(T p_x, T p_y): x(p_x), y(p_y)
        {
            
        }
        
        Vector2(Vector4<T> src): x(src.x), y(src.y)
        {
            
        }
        
        Vector2 operator+(Vector2& a)
        {
            return Vector2(x + a.x, y + a.y);
        }
        
        Vector2& operator+=(Vector2& a)
        {
            x += a.x;
            y += a.y;
            
            return *this;
        }
        
        Vector2 operator-(Vector2& a)
        {
            return Vector2(x - a.x, y - a.y);
        }
        
        Vector2 operator-=(Vector2& a)
        {
            y -= a.y;
            x -= a.x;
            
            return *this;
        }
        
        Vector2 operator*(T a)
        {
            return Vector2(x * a, y * a);
        }
        
        Vector2 operator*=(T a)
        {
            x *= a;
            y *= a;
            
            return *this;
        }
        
        T dot(Vector2& a)
        {
            return (x * a.x) + (y * a.y);
        }
        
        T* data()
        {
            return &x;
        }
        
        T x;
        T y;
    };
}

#endif /* A46370AF_0A1E_4016_8C0E_D78CE0806670 */


#endif /* B9DA7D99_3006_4336_A745_BDC23E2A82CE */
