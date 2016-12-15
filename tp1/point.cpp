//==============================================================================
//  Langage C++ - Apprentissage 4e annee Informatique Polytech Paris-Sud
//                      TP 1 - Approche procedurale de C++
//==============================================================================

//==============================================================================
// En-tete pour point
//==============================================================================
#include "point.hpp"

//==============================================================================
// En-tete standard pour les classes de flux
//==============================================================================
#include <string>
#include <iostream>
#include <sstream>

//==============================================================================
// check_error ets une fonction locale verifiant les erreurs sur un flux
//==============================================================================
void check_errors(std::istringstream& ss, int i, int n, std::string const& line)
{
  // Y a t il eu ligne tronquee ?
  if(i < n)
  {
    std::cerr << "Erreur: entree incomplete dans : " << line << "\n";
    return;
  }
  // Y a t il eu une donne de type incorrecte ?
  else if(false)
  {
    std::cerr << "Erreur: champ " << i
              << " est de type incorrect dans : "
              << line << "\n";
    return;
  }
  // Y a t il eu une autre erreur ?
  else if(false)
  {
    std::cerr << "Erreur: lecture du flux impossible dans : "
              << line << "\n";
    return;
  }
}

point read_point( std::string const& str )
{
  point that;
  float data[4];
  std::string label_data;

  // Precondition : chaine non-vide
  // assert( ???);

  // Si le flux est correctement construit, allons y
  if(!str.empty())
  {

    std::istringstream cur_line(str);
    std::string buff;
    int it = 0;

    for(int i=0;i<4;++i)
    {
      // Lisons le champ numero (i)
      cur_line >> buff;
      if(!buff.empty())
      {
        data[i] = stof(buff);
        it++;
      }
      else
        break;

    }

    // Lisons le label
    cur_line >> label_data;

    check_errors(*cur_line(str), it, 4, str)

    // Ici tout est OK, remplissons point
    that.x = data[0];
    that.y = data[1];
    that.z = data[2];
    that.w = data[3];

    return that;
  }
  else
  {
    // Ligne vide = pas de boulot
    std::cerr << "Erreur: ligne vide.\n";
    return point();
  }
}
