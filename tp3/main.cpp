#include <iostream>
#include "rectangle.hpp"
#include "square.hpp"
#include <cassert>

using std::cout;
using std::endl;

void test_area(geometry::Rectangle r){

	int w = rand() % 100;
	int h = rand() % 100;
	r.setWidth(w);
	r.setHeight(h);

	assert(r.rectArea() == w*h);
}

int main(void){

	/******************
	** Série de test **
	******************/
	cout << "test" << endl;

	cout << "Instantiation d'objets Rectangles" << endl;
	geometry::Rectangle test1(), test2(2,1);

	cout << "Instantiation d'un rectangle à partir d'un autre avec : hauteur = " << test2.getHeight() << " et largeur = " << test2.getWidth() << endl;
	geometry::Rectangle test3(test2);
	cout << "Ce nouveau rectangle vaut hauteur = " << test3.getHeight() << " et largeur = " << test3.getWidth() << endl<< endl;  

	cout << "Instantiation d'un nouveau rectangle à l'aide l'opérateur égale avec le rectangle créé précédemment" << endl;
	geometry::Rectangle test4 = test2;
	cout << "Ce nouveau rectangle vaut hauteur = " << test4.getHeight() << " et largeur = " << test4.getWidth() << endl << endl;  

	cout << "On change les valeurs du nouveau rectangle créé en mettant 5 en largeur et 4 en hauteur" << endl;
	test4.setWidth(5);
	test4.setHeight(4);
	cout << "Ce nouveau rectangle vaut hauteur = " << test4.getHeight() << " et largeur = " << test4.getWidth() << endl << endl;

	cout << "On swap test4 : hauteur = " << test4.getHeight() << " et largeur = " << test4.getWidth() << " et test2 hauteur = " << test2.getHeight() << " et largeur = " << test2.getWidth() << endl;
	swap(test2,test4);
	cout << "Maintenant test4 : hauteur = " << test4.getHeight() << " et largeur = " << test4.getWidth() << " et test2 hauteur = " << test2.getHeight() << " et largeur = " << test2.getWidth() << endl;

	geometry::Square test6(4,4);

	cout << "Instantiation d'un carré à partir d'un autre avec : hauteur = " << test6.getHeight() << " et largeur = " << test6.getWidth() << endl;
	geometry::Square test7(test6);
	cout << "Ce nouveau rectangle vaut hauteur = " << test7.getHeight() << " et largeur = " << test7.getWidth() << endl<< endl; 

	cout << "Instantiation d'un nouveau rectangle à l'aide l'opérateur égale avec le rectangle créé précédemment" << endl;
	geometry::Square test8 = test7;
	cout << "Ce nouveau rectangle vaut hauteur = " << test8.getHeight() << " et largeur = " << test8.getWidth() << endl << endl;  

	cout << "On swap test8 : hauteur = " << test8.getHeight() << " et largeur = " << test6.getWidth() << " et test2 hauteur = " << test6.getHeight() << " et largeur = " << test6.getWidth() << endl;
	swap(test6,test8);
	cout << "Maintenant test8 : hauteur = " << test8.getHeight() << " et largeur = " << test8.getWidth() << " et test6 hauteur = " << test6.getHeight() << " et largeur = " << test6.getWidth() << endl;

	test_area(test4);

	return 0;
}