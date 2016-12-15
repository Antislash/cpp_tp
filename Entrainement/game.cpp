//==============================================================================
//  Langage C++ - Apprentissage 4e annee Informatique Polytech Paris-Sud
//==============================================================================
#include "file.hpp"
#include "question.hpp"

#include <string>
#include <iostream>



int main(void)
{
  data_load("data.txt");

  char rep = '\0';
  int score = 0;
  int i = 0;

  while( rep != 'q'){
    std::cout << "score : " << score << std::endl;

    std::cout << give_question(i) << std::endl;
    std::cin >> rep;

    if(rep != 'q')
      score += result(i, rep);

    i++;
  }

  return 0;
}
