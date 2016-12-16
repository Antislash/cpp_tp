#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

#include "vector2D.hpp"

class Grille
{
private:
    struct Case
    {
        int val;
        bool wall[4];
    };
    std::vector<std::vector<Case> > tab;
    Vector2D size;

    std::vector<std::vector<Case*>* > ensemble;

    /** Graine **/
    Vector2D g_coor;
    std::string graine;

    void applicateGraine();
    void g_random();
    void g_default();

    /** -------------------- **/

    bool isGoodCoor(Vector2D coor);
    int getOposedWall(int val);
    void mergeEnsemble(Vector2D coor,Vector2D target);
public:
    Grille(Vector2D Size,std::string Graine);
    ~Grille();
    bool isEnd();
    void openDoor();
    std::string getString();
    void dispPC();
};


#endif // GRILLE_HPP_INCLUDED
