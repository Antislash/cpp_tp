#ifndef RECTANGLE_HPP_INCLUDED
#define RECTANGLE_HPP_INCLUDED

#include <ostream>

namespace geometry{
    class Rectangle{

        public:

            /*****************
            ** Constructeur **
            *****************/
            Rectangle();
            Rectangle(Rectangle const& rs);
            Rectangle(int w, int h);

            virtual ~Rectangle();
            virtual int getWidth() const;
            virtual int getHeight() const;
            virtual void setWidth(int);
            virtual void setHeight(int);
            virtual int rectArea() const;

            Rectangle& operator=(Rectangle const& r);

            void swap(int& r1, int& r2);

        protected:
            int w;
            int h;
    };
    void swap(Rectangle& r1, Rectangle& r2);
    std::ostream& operator<<(std::ostream& os, Rectangle const& r);
}
#endif