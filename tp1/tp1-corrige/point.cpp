//==============================================================================
//  Langage C++ - Apprentissage 3e annee Informatique Polytech Paris-Sud
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
#include <cassert>

//==============================================================================
// check_error ets une fonction locale verifiant les erreurs sur un flux
//==============================================================================
void check_errors(std::istringstream& ss, int i, int n, std::string const& line)
{
  // Y a t il eu ligne tronquee ?
  if( (ss.rdstate() == ss.eofbit) && (i < n-1) )
  {
    std::cerr << "Erreur: entree incomplete dans : " << line << "\n";
    return;
  }
  // Y a t il eu une donne de type incorrecte ?
  else if(ss.rdstate() == ss.failbit)
  {
    std::cerr << "Erreur: champ " << i
              << " est de type incorrect dans : "
              << line << "\n";
    return;
  }
  // Y a t il eu une autre erreur ?
  else if(ss.rdstate() == ss.badbit)
  {
    std::cerr << "Erreur: lecture du flux impossible dans : "
              << line << "\n";
    return;
  }
}

point read_point( std::string const& str )
{
  point that;
  float data[4] {0 , 0 , 0 , 0};
  std::string label_data = "";

  // Precondition : chaine non-vide
  if(str.size() > 0)
  {

  std::istringstream ss(str);

  // Si le flux est correctement construit, allons y
  if(ss.rdstate() == ss.goodbit)
  {
    for(int i=0;i<4;++i)
    {
      // Lisons le champ numero (i)
      ss >> data[i];
      check_errors(ss,i,4,str);
    }

    // Lisons le label
    ss >> label_data;
    check_errors(ss,3,4,str);
  }

    // Ici tout est OK, remplissons point
    that.x      = data[0];
    that.y      = data[1];
    that.z      = data[2];
    that.weight = data[3];
    that.label  = label_data;

    return that;

  }
  else {return  {0,0,0,0,""}; };

}
