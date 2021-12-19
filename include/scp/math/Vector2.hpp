#ifndef B9DA7D99_3006_4336_A745_BDC23E2A82CE
#define B9DA7D99_3006_4336_A745_BDC23E2A82CE
#ifndef A46370AF_0A1E_4016_8C0E_D78CE0806670
#define A46370AF_0A1E_4016_8C0E_D78CE0806670

namespace scp::math
{
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
        
        Vector2(T p_x, T p_y): m_x(p_x), m_y(p_y)
        {
            
        }
        
        // More stuff coming soon
        // ...
        
        T m_x;
        T m_y;
    };
}

#endif /* A46370AF_0A1E_4016_8C0E_D78CE0806670 */


#endif /* B9DA7D99_3006_4336_A745_BDC23E2A82CE */
