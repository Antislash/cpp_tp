#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

#include "grille.hpp"

int main()
{
    Vector2D size;

    //Permet à l'utilisateur de choisir la taille, qui sera multiplié par 2
    std::cout << "x:";
    std::cin >> size.x;
    std::cout << "y:";
    std::cin >> size.y;

    srand(time(NULL));
    Grille labi(size,"default");

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    //Boucle de traitement
    while(!labi.isEnd())
    {
        labi.openDoor();
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_milliseconds = end-start;
 
    std::cout << "elapsed time: " << elapsed_milliseconds.count() << "s\n";

    //On affiche le labyrinth dans la console
    std::cout << labi.getString();

    //On enregistre le labyrinth dans un fichier
    std::ofstream file("labi.txt");
    file << labi.getString();
    file.close();

    return 0;
}
