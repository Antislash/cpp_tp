#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "rectangle.hpp"

namespace geometry{
	class Square : public Rectangle
	{
		public:
		Square();
		Square(int w, int h);
		Square(Square const& s);
		void set_width(int w);
		void set_height(int h);

		Square& operator=(Square const& r);
	};
}
#endif