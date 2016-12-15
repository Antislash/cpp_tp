//==============================================================================
//  Langage C++ - Apprentissage 3e annee Informatique Polytech Paris-Sud
//                      TP 1 - Approche procedurale de C++
//==============================================================================

//==============================================================================
// En-tete pour read_file
//==============================================================================
#include "file.hpp"
#include <fstream>
#include <iostream>

//==============================================================================
/**!
 *  @brief lecture ligne par ligne d'un fichier texte
 *
 *  @param file Chemin du fichier a lire
 *  @return a vecteur de chaine de caractere ou chaque elements du vecteur
 *  correspond a une ligne du fichier texte.
 **/
//==============================================================================
std::vector<std::string> read_file( std::string const& file )
{
  // Tableau de retour
  std::vector<std::string> that;

  // Ouverture du fichier
  std::ifstream ifs( file.c_str() );

  // Ouverture correcte ?
  if(ifs.rdstate() == ifs.goodbit)
  {
    std::string line;
    while( std::getline(ifs, line) ) that.push_back(line);
  }
  else
  {
    std::cerr << "Erreur de lectur du fichier " << file << "\n";
  }

  return that;
}
