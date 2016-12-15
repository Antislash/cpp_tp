//==============================================================================
//  Langage C++ - Apprentissage 3e annee Informatique Polytech Paris-Sud
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

// Incrémente chaque valeur du point de 1 et recalcule son poids
point incr_point( point p) { return {p.x +1 , p.y +1, p.z +1, (p.x + p.y + p.z + 3 )/3  , p.label}; }

int main( int argc, char const** argv)
{
  //============================================================================
  // Recuperation des arguments de la ligne de commande dans un tableau de
  // chaines de caractere. On commence a argv+1 pour eliminer le nom de l'exe
  //============================================================================
  std::vector<std::string> arguments(argv+1, argv+argc);

  //============================================================================
  // On lit le fichier line par line sous forme de std::string
  //============================================================================
  if(arguments.size())
  {
    std::vector<std::string> data = read_file(arguments[0]);

    //============================================================================
    // Affichage des lignes lues
    //============================================================================
    std::cout << arguments[0] << " contient " << data.size() << " lignes.\n";

    std::ostream_iterator<std::string> os( std::cout, "\n" );
    std::copy( data.begin(), data.end(), os );

    std::vector<point> p(data.size());
    std::vector<point> p1(data.size());
    for(std::size_t i = 0 ; i < data.size() ; ++i)
    {
      p[i] = read_point(data[i]);
    }

    for(auto &i : p)
    {
      std::cout << i.x << " " << i.y << " " << i.z << " " << i.weight << " " << i.label << std::endl;
    }

    // Applique la fonction incr_point à chaque élément de p et stocke le résultat dans p1;
    std::transform(p.begin() , p.end() , p1.begin() , incr_point);

    std::cout << "--------------------------------" << std::endl;

    for(auto &i : p1)
    {
      std::cout << i.x << " " << i.y << " " << i.z << " " << i.weight << " " << i.label << std::endl;
    }

  }
  else
  {
    std::cerr << "Pas de fichier en entree !\n";
  }
}
