#include "triangle.h"
#include <iostream> 
#include <algorithm> 

using namespace std;

class Triangle
{
private:
    int a, b, c;
    double square;
public:
    Triangle();
    Triangle(const int first_side, const int second_side, const int third_side);
    bool operator>(const Triangle& triangle) const noexcept;
    bool operator<(const Triangle& triangle) const noexcept;
    bool operator==(const Triangle& triangle) const noexcept;
};

Triangle::Triangle(): a(0), b(0), c(0), square(0) {}

Triangle::Triangle(const int first_side, const int second_side, const int third_side): a(first_side), b(second_side), c(third_side), square(/*You must do it.*/) {}

bool Triangle::operator>(const Triangle& triangle) const noexcept
{
    return this->square > triangle.square;
}

bool Triangle::operator<(const Triangle& triangle) const noexcept
{
    return this->square < triangle.square;
}

bool Triangle::operator==(const Triangle& triangle) const noexcept
{
    return this->square == triangle.square;
}

template<typename T>
T Max(const T& t1, const T& t2, const T& t3)
{
    return std::max(std::max(t1, t2), t3);
}

int main()
{
    int a, b, c;
    scanf_s("%d %d %d", &a,&b,&c);
    triangle ttt(a,b,c);
    printf("%f",ttt.getP());
    

}