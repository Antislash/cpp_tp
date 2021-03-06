//==============================================================================
//  Langage C++ - Apprentissage 4e annee Informatique Polytech Paris-Sud
//
//                      TP 1 - Approche procedurale en C++
//
// Objectifs :
//  * Maitrise des types de bases de C++
//  * Maitrise des entrees/sorties
//  * Structuration des programmes
//
// Etape 1 : Entree/sorties fichiers
//  - utilisation de string/fstream/vector pour la lecture de fichier texte
//  - utilisation de copy pour les sorties
//
// Point Importants :
//  - gestion des ressources memoires par vector/string etc ...
//  - premiere intro a la notion d'Algorithme de la BSC++
//==============================================================================

#include "file.hpp"
#include "point.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

int main( int argc, char const** argv)
{

  std::cout << "Step 2 DEBUT" << std::endl << std::endl;
  //============================================================================
  // Recuperation des arguments de la ligne de commande dans un tableau de
  // chaines de caractere. On commence a argv+1 pour eliminer le nom de l'exe
  //============================================================================
  if(argc < 2)
  {
    std::cerr << "Pas de fichier en entree !\n";
  }
  // Ouverture du fichier
  std::ifstream file(argv[1]);

  //============================================================================
  // On lit le fichier line par line sous forme de std::string
  //============================================================================
  if(true)
  {

    std::string content = "";
    for (std::string line; std::getline(file, line); ) {
      content  += line + "\n";
    }
    
    point p = read_point(content);
    //============================================================================
    // Affichage des lignes lues
    //============================================================================

  }
  else
  {
    std::cerr << "Pas de fichier en entree !\n";
  }
}
