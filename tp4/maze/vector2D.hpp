#ifndef VECTOR2D_HPP_INCLUDED
#define VECTOR2D_HPP_INCLUDED

class Vector2D
{
public:
    int x,y;
    Vector2D(int X,int Y);
    Vector2D();
    Vector2D operator+(Vector2D const& v2);
};

#endif // VECTOR2D_HPP_INCLUDED
