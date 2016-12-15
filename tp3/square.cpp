#include "square.hpp"
#include <cassert>

namespace geometry{
  Square::Square(): Rectangle(){}

  Square::Square(int w, int h)  : Rectangle(w,h){
    assert(w == h);
  }

  Square::Square(Square const& s) : Rectangle(s){
    assert(w == h);
  }

  void Square::set_width( int w)
  {
    assert(this->w == this->h);
    this->w  = w;
    this->h = w;
  }

  void Square::set_height(int h)
  {
    assert(this->w == this->h);
    this->w = h;
    this->h  = h;
  }



  Square& Square::operator=(Square const& square)
  {
    assert(square.w == square.h);
    w  = square.w;
    h = square.h;
    return *this;
  }
}