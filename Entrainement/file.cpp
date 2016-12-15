#include "file.hpp"
#include "question.hpp"

#include <fstream>
#include <sstream>

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

void data_load(std::string const& file){

	std::vector<std::string> that = read_file(file);

	if(that.size() > 0)
	{
		Question q;
		for(std::string line : that)
		{
			std::stringstream ifs(line);

			if(ifs.rdstate() == ifs.goodbit)
			{
				std::string question;
				std::string y, n;

				while(std::getline(ifs,question, ',')){
					if(!std::getline(ifs,y,','))
						std::cerr << "Error yes" << "\n";
					if(!std::getline(ifs,n,';'))
						std::cerr << "Error no" << "\n";
				}

				q.question = question;
				q.yes = stoi(y);
				q.no = stoi(n);

				questions.push_back(q);

			}
		}

		//std::cout << "taille questions : " << questions.size() << std::endl;
	}
	else{
		std::cerr << "Erreur : fichier vide" << std::endl;
		exit (2);
	}

}
