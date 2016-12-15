#include "rectangle.hpp"
#include <utility>

namespace geometry{

	Rectangle::Rectangle(){
	w = 0;
	h = 0;
	}

	Rectangle::Rectangle(int w, int h){
		this->w = w;
		this->h = h;
	}

	Rectangle::Rectangle(Rectangle const& rec){
		this->w = rec.w;
		this->h = rec.h;
	}

	Rectangle::~Rectangle(){}

	int Rectangle::getWidth() const {
		return w;
	}

	int Rectangle::getHeight()const{
		return h;
	}

	void Rectangle::setWidth(int w){
		this->w = w;
	}

	void Rectangle::setHeight(int h){
		this->h = h;
	}

	int Rectangle::rectArea() const{
		return w*h;
	}

	Rectangle& Rectangle::operator=(Rectangle const& rec)
	{
		w  = rec.w;
		h = rec.h;
		return *this;
	}

	void swap(Rectangle& r1, Rectangle& r2){
		int tmp = r1.getWidth();
		r1.setWidth(r2.getWidth());
		r2.setWidth(tmp);

		tmp = r1.getHeight();
		r1.setHeight(r2.getHeight());
		r2.setHeight(tmp);
	}

	std::ostream& operator<<(std::ostream& os, Rectangle const& rec){
	 	if(rec.getWidth() == rec.getHeight())
	 		os << "Le carre est de largeur " << rec.getWidth();
	 	else
	 		os << "Le rectangle est de largeur " << rec.getWidth();

	 	os << " et de longueur " << rec.getHeight() << std::endl;

	 	return os;
	 	
	 }
}