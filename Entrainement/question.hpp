//==============================================================================
//  Langage C++ - Apprentissage 3e annee Informatique Polytech Paris-Sud
//                      TP 1 - Approche procedurale de C++
//==============================================================================
#ifndef QUESTION_HPP_INCLUDED
#define QUESTION_HPP_INCLUDED

//==============================================================================
// En-tete standard pour la predefinition des classes de flux
//==============================================================================
#include <iosfwd>

//==============================================================================
// En-tete standard pour std::string
//==============================================================================
#include <string>
#include <vector>

//==============================================================================
/**!
 * @brief Structure de point 3D avec poids et label texte
 *
 * @note struct en C++ definit un type, pas besoin de typedef !
 **/
//==============================================================================
struct Question
{
  std::string question;
  int yes;
  int no;
};

std::vector<Question> questions;
std::string give_question(int);
int result(int index , char rep);

#endif
