#include <iostream>
#include <array>

constexpr int add(const int a, const int b)
{
    return a+b;
}

constexpr int pow(const int base, const int exp)
{
    return (exp == 0 ? 1 : base * pow(base, exp-1));
}

/*constexpr int pow1(const int base, const int exp)
{
    auto res =1;
    
    for(int i = 0; i < exp; ++i) res *= base;
    
    return res;
}*/

class Point
{
    public:
    constexpr Point(const int x, const int y):x_{x},y_{y}{}
    constexpr int GetX(){return x_;};
    constexpr int GetY(){return y_;};
     constexpr void SetX( int x) noexcept{x_ = x;}
     constexpr void SetY( int y) noexcept{y_ = y;}
    private:
    int x_;
    int y_;
    
};

constexpr Point Reflection(const Point& p) noexcept
{

    return p;
}

int main()
{
    //int x;
    //x =20;
    //constexpr int xp =10;
    constexpr Point p1(1,2);
    
    constexpr auto mid = Reflection(p1);
    //p1.SetX(p1.GetX());
    
    //std::cout<<add(a,b)<<std::endl;
    
    //std::array<int,p1.GetX()> arr_;
    
    return 0;
}
