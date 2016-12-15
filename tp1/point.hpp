//==============================================================================
//  Langage C++ - Apprentissage 4e annee Informatique Polytech Paris-Sud
//                      TP 1 - Approche procedurale de C++
//==============================================================================
#ifndef POINTS_HPP_INCLUDED
#define POINTS_HPP_INCLUDED

//==============================================================================
// En-tete standard pour la predefinition des classes de flux
//==============================================================================
#include <iosfwd>

//==============================================================================
// En-tete standard pour std::string
//==============================================================================
#include <string>

//==============================================================================
/**!
 * @brief Structure de point 3D avec poids et label texte
 *
 * @note struct en C++ definit un type, pas besoin de typedef !
 **/
//==============================================================================

struct point {
	float x;
	float y;
	float z;
	float w;

	std::string label;
};
//==============================================================================
/**!
 * @brief Construction d'un point via une chaine de caractere
 *
 * @param str Chaine de caractere contenant les valeurs initiale du point
 * @return une structure point remplie des donnees extraits de str
 **/
//==============================================================================
point read_point( std::string const& str );
void check_errors(std::istringstream& ss, int i, int n, std::string const& line);

#endif
