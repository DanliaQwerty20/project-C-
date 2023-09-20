#pragma once
#include <cmath> 

class triangle
{
private:
    int a, b, c;
    double square;
    float p;
public:
    triangle() { a = b = c = 0; square = 0; }
    triangle(int A, int B, int C) { a = A; b = B; c = C; 
    p = (float)(a + b + c) / 2; square = pow((p * (p - a) * (p - b) * (p - c)), 0.5); }

    float getP() {
        return p;
    }
    bool operator>(triangle ob);
    bool operator==(triangle ob);
    bool operator<(triangle ob);
};

class Square
{
private:
    int a;
    int square;
public:
    Square() { a = 0; square = 0; }
    Square(int A) { a = A; square = a * a * 6; }
    bool operator>(Square ob);
    bool operator==(Square ob);
    bool operator<(Square ob);
};

template <class X> X max(X x, X y);

template <class X> void max(X x, X y, X z);