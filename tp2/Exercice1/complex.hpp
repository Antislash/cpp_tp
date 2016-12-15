//==============================================================================
//  Langage C++ - Apprentissage 4e annee Informatique Polytech Paris-Sud
//                      TP 1 - Approche procedurale de C++
//==============================================================================
#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

#include <math.h>
#include <iostream>
#include <vector>

template<typename T>
class Complex
{	
	public:

		T re;
		T img;

		/******************
		** Constructeurs **
		*******************/
		Complex(){
			re = 0;
			img = 0;
		}

		Complex(T ree){
			re = ree;
			img = 0;
		}

		Complex(T ree, T img1){
			re = ree;
			img = img1;
		}

		/***************
		** Opérateurs **
		***************/
		void operator=(T const& a)
		{
		    re = a;
		}

		//Arithmétiques
		void operator+=(Complex<T> const& a)
		{
			re += a.re;
			img += a.img;
		}

		void operator-=(Complex<T> const& a)
		{
			re -= a.re;
			img -= a.img;
		}

		void operator*=(Complex<T> const& a)
		{
			re = re * a.re - img * a.img;
			img = re * a.img + img * a.re;
		}

		void operator/=(Complex<T> const& a)
		{
			re = re * a.re + img * a.img / (a.re*a.re + a.img * a.img);
			img = (img*a.re - re * a.img) / (a.re * a.re + a.img * a.img);
		}

		   



};

/************************
** Surcharge operateurs**
************************/

//Addition
template <typename T> Complex<T>  
operator+(Complex<T> const& a, Complex<T> const& b){
	return Complex<T>(a.re + b.re, a.img + b.img);
}

template <typename T> Complex<T>  
operator+(Complex<T> const& a, T const& b){
	return Complex<T>(a.re + b, a.img);
}

template <typename T> Complex<T>  
operator+(T const& a, Complex<T> const& b){
	return Complex<T>(a + b.re, b.img);
}


//Soustraction
template <typename T> Complex<T>  
operator-(Complex<T> const& a, Complex<T> const& b){
	return Complex<T>(a.re - b.re, a.img - b.img);
}

template <typename T> Complex<T>  
operator-(T const& a, Complex<T> const& b){
	return Complex<T>(a - b.re, b.img);
}

template <typename T> Complex<T>  
operator-(Complex<T> const& a, T const& b){
	return Complex<T>(a.re - b, a.img);
}


//Multiplication
template <typename T> Complex<T>  
operator*(Complex<T> const& a, Complex<T> const& b){
	return Complex<T>(a.re * b.re - a.img* b.img, a.re * b.img + a.img * b.re);
}

template <typename T> Complex<T>  
operator*(T const& a, Complex<T> const& b){
	return Complex<T>(a*b.re, a*b.img);
}

template <typename T> Complex<T>  
operator*(Complex<T> const& a, T const& b){
	return Complex<T>(b * a.re, b * a.img);
}


//Division
template <typename T> Complex<T>  
operator/(Complex<T> const& a, Complex<T> const& b){
	return Complex<T>((a.re* b.re + a.img * b.img)/(b.re*b.re + b.img * b.img), (a.img*b.re - a.re * b.img) / (b.re * b.re + b.img * b.img));
}

template <typename T> Complex<T>  
operator/(T const& a, Complex<T> const& b){
	return Complex<T>((a * b.re)/(a*a), (a * b.img) / (a*a));
}

template <typename T> Complex<T>  
operator/(Complex<T> const& a, T const& b){
	return Complex<T>((b * a.re)/(b*b), (b * a.img) / (b*b));
}

//Opérateur unaire
template <typename T> Complex<T> 
operator-( const Complex<T>& a ){
	return Complex<T>(-a.re, -a.img );
}

//Opérateur de flux
template <typename T>
std::ostream &operator<<(std::ostream& flux, Complex<T> const& a){
	flux << a.re << "+" << a.img << "i";
	return flux;
}

template <typename T>
void operator>>(std::istream& flux, Complex<T>& a){
	flux >> a.re;
	flux >> a.img;
}

/********************************
** Operation sur les complexes **
********************************/
template<typename T>
Complex<T> exp(Complex<T> const& c)
{
    return Complex<T>(exp(c.re) * cos(c.img), exp(c.re) * sin(c.img));
}
        
template<typename T>
Complex<T> cos(Complex<T> const& c)
{
    return (Complex<T>(0,1) * c +Complex<T>(0,-1) * c)/2;
}
   
template<typename T>
Complex<T> sin(Complex<T> const& c)
{
    return (Complex<T>(0,1) * c +Complex<T>(0,-1) * c)/Complex<T>(0,2) ;
}

// template <typename T>
// bool operator==(Complex<T> const& a, Complex<T> const& b)
// {
// 	return b.re == a.re && b.img == a.img;
// }

/************************************
** Transformée de Fourier Discrete **
************************************/
template<typename T>
std::vector< Complex<T> > dft( std::vector< Complex<T> > const& signal )
{

	//On créé le vector de retour
	std::vector<Complex<T>> s2;

	//On l'initialise à 0
	for (unsigned int i = 0; i < signal.size(); i++)
		s2.push_back(Complex<T>(0,0));

	for (unsigned int i = 0; i < signal.size(); i++)
	{
		for (unsigned int j = 0; j < signal.size();j++ )
		{
			s2[i] += signal[j]*exp(Complex<T>(0,-2*M_PI*static_cast<signed int>(i)*static_cast<signed int>(j)/static_cast<signed int>(signal.size())));
		}
	}

	//On affiche les valeurs
	for (unsigned int i = 0; i < signal.size(); i++)
		std::cout << s2[i] << std::endl;

	return s2;
}

//Transformé de Fourier inverse
template<typename T>
std::vector< Complex<T> > inverse_dft( std::vector< Complex<T> > const& d )
{
	//On créé le vector de retour
	std::vector<Complex<T>> s2;

	//On l'initialise à 0
	for (unsigned int i = 0; i < d.size(); i++)
		s2.push_back(Complex<T>(0,0));
	
	for (unsigned int i = 0; i < d.size(); i++)
	{
		for (unsigned int j = 0; j < d.size();j++ )
		{
			s2[i] += d[j]*exp(Complex<T>(0,-2*M_PI*static_cast<signed int>(i)*static_cast<signed int>(j)/static_cast<signed int>(d.size())));
		}

		//Représente le 1/N de la formule 
		s2[i] = s2[i] / static_cast<T>(d.size());
	}

	//On affiche les valeurs
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << s2[i] << std::endl;

	return s2;
}


Complex<float> const img_pure(0,1);

#endif
