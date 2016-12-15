#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <vector>

int main()
{
	//Mot entré par l'utilisateur
	std::string user_word = ""; 

	std::cout << "Veuillez rentrer le mot que vous souhaitez rechercher" << std::endl ;
	std::cin >> user_word;

	//Mot de l'utilisateur avec les lettres triées par ordre alphabétique
	std::string sort_word = user_word;
	std::sort(sort_word.begin(), sort_word.end());

	// Ouverture du fichier
  	std::ifstream ifs("test.txt");

  	//Hatable contenant les mots du dictionnaire
  	std::unordered_map<std::string, std::vector<std::string>> words;

  	std::vector<std::string> new_word;
  	std::string word_non_sorted;

	// Ouverture correcte ?
	if(ifs.rdstate() == ifs.goodbit)
	{
		//Mot qui va servir de clef
		std::string line;
		
		while( std::getline(ifs, line) ) 
		{
			word_non_sorted = line;
			std::sort(line.begin(), line.end());

			//Si la clef existe déjà
			if(words.find(line) != words.end())
			{
				words[line].push_back(word_non_sorted);				
			}
			else
			{
				new_word.push_back(word_non_sorted);
				words.emplace(line, new_word);
				new_word.clear();
			}
		} 
	}
	else
	{
		std::cerr << "Erreur de lectur du fichier " << "\n";
	}

	//On affiche les résultats
	std::cout << "\nPour le mot " << user_word << " il y a la/les anagrammes suivante(s):" << std::endl;
	new_word = words[sort_word];
	for(unsigned int i = 0; i < words[sort_word].size(); i++)
	{
		std::cout << new_word[i] << std::endl;
	}

	return 0;
}