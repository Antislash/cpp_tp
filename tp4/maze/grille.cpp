#include "grille.hpp"

char charWall=219;

Grille::Grille(Vector2D Size,std::string Graine)
{
    graine=Graine;
    size.x=Size.x;
    size.y=Size.y;
    tab=std::vector<std::vector<Case> >(size.y,std::vector<Case>(size.x));
    ensemble=std::vector<std::vector<Case*>* >(size.y*size.x);
    for(int i=0 ; i<size.y ; i++)
    {
        for(int j=0 ; j<size.x ; j++)
        {
            tab[i][j].val=(i*size.x)+j;
            tab[i][j].wall[0]=true;
            tab[i][j].wall[1]=true;
            tab[i][j].wall[2]=true;
            tab[i][j].wall[3]=true;
            std::vector<Case*>* temp=new std::vector<Case*> (1);
            (*temp)[0]=&tab[i][j];
            ensemble[(i*size.x)+j]=temp;
        }
    }
}

Grille::~Grille()
{
    for(unsigned int i=0 ; i<ensemble.size() ; i++)
    {
        if(ensemble[i]!=NULL)
        {
            delete ensemble[i];
        }
    }
}

bool Grille::isGoodCoor(Vector2D coor)
{
    if(coor.x>=0 && coor.x<size.x && coor.y>=0 && coor.y<size.y)
    {
        return true;
    }
    return false;
}

bool Grille::isEnd()
{
    if((g_coor.y*size.x)+g_coor.x==(size.x*size.y)-1)
    {
        return true;
    }
    return false;
}

int Grille::getOposedWall(int val)
{
    return (val+2)%4;
}


//Fonction principale qui enlève les murs
void Grille::openDoor()
{
    Vector2D coor=g_coor,target;
    bool did_a_wall_has_been_opened=false;
    while(!did_a_wall_has_been_opened)
    {
        int wallSelected=rand()%4;
        if(wallSelected==0)
        {
            target=Vector2D(coor.x,coor.y-1);
        }
        if(wallSelected==1)
        {
            target=Vector2D(coor.x+1,coor.y);
        }
        if(wallSelected==2)
        {
            target=Vector2D(coor.x,coor.y+1);
        }
        if(wallSelected==3)
        {
            target=Vector2D(coor.x-1,coor.y);
        }

        //On vérifie que la case est bien contenu dans le tableau
        if(isGoodCoor(target))
        {
            //On vérifie que nous avons bien des valeurs différentes pour la cible est la case d'origine
            if(tab[coor.y][coor.x].val!=tab[target.y][target.x].val)
            {
                did_a_wall_has_been_opened=true;
                tab[coor.y][coor.x].wall[wallSelected]=false;
                tab[target.y][target.x].wall[getOposedWall(wallSelected)]=false;
                mergeEnsemble(coor,target);
            }
        }
    }
    applicateGraine();
}

void Grille::mergeEnsemble(Vector2D coor,Vector2D target)
{
    int adr1=tab[coor.y][coor.x].val, adr2=tab[target.y][target.x].val;
    if((*ensemble[adr1]).size()>=(*ensemble[adr2]).size())
    {
        for(int i=(*ensemble[adr2]).size()-1 ; i>=0 ; i--)
        {
            (*ensemble[adr2])[i]->val=adr1;
            (*ensemble[adr1]).push_back((*ensemble[adr2])[i]);
            (*ensemble[adr2]).pop_back();
        }
        delete ensemble[adr2];
        ensemble[adr2]=NULL;
    }
    else
    {
        for(int i=(*ensemble[adr1]).size()-1 ; i>=0 ; i--)
        {
            (*ensemble[adr1])[i]->val=adr2;
            (*ensemble[adr2]).push_back((*ensemble[adr1])[i]);
            (*ensemble[adr1]).pop_back();
        }
        delete ensemble[adr1];
        ensemble[adr1]=NULL;
    }
}

std::string Grille::getString()
{
    //Booleans servant à créer une entrée et une sortie
    bool entre=false, sortie = false;

    std::string labiInString;
    for(int i=0 ; i<2*size.x+1 ; i++)
    {
        if(!entre && !tab[1][i].wall[3] && !tab[1][i].wall[2]){
            labiInString += " ";
            entre = true;
        }
        else
            labiInString+=charWall;
    }
    labiInString+= "\n";
    for(int i=0 ; i<size.y ; i++)
    {
        for(int k=0 ; k<2 ; k++)
        {
            for(int j=0 ; j<size.x ; j++)
            {
                if(k==0)
                {
                    if(tab[i][j].wall[3])
                    {
                        labiInString+=charWall;
                    }
                    else
                    {
                        labiInString+= " ";
                    }
                    labiInString+= " " ;
                }
                else
                {
                    labiInString+=charWall;
                    if(tab[i][j].wall[2])
                    {
                        labiInString+=charWall;
                    }
                    else
                    {
                        labiInString+= " " ;
                    }
                }
            }

            if(!sortie && !tab[1][i].wall[3] && !tab[1][i].wall[2]){
                labiInString += " ";
                sortie = true;
            }
            else
                labiInString+=charWall;

            labiInString+="\n";
        }
    }
    return labiInString;
}

void Grille::applicateGraine()
{
    if(graine=="default")
    {
        g_default();
    }
    if(graine=="random")
    {
        g_random();
    }
}

void Grille::g_random()
{
    g_coor=Vector2D(rand()%size.x,rand()%size.y);
}

void Grille::g_default()
{
    if(g_coor.x<size.x-1)
    {
        g_coor.x++;
    }
    else
    {
        g_coor.y++;
        g_coor.x=0;
    }
}

void Grille::dispPC()
{
    float curX=g_coor.x,curY=g_coor.y,X=size.x,Y=size.y;
    float pc=((curX+1+(curY*X))/(Y*X))*100;
    std::cout << pc << "%\n";
}
