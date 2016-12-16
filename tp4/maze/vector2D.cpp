#include "vector2D.hpp"

Vector2D::Vector2D(int X,int Y)
{
    x=X;
    y=Y;
}

Vector2D::Vector2D()
{
    x=0;
    y=0;
}

Vector2D Vector2D::operator+(Vector2D const& v2)
{
    return Vector2D(x+v2.x,y+v2.y);
}
