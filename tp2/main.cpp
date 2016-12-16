#include <iostream>
#include "complex.hpp"
#include <complex.h>

int main(void){


	/**************************************
	*** Série de test sur les Complexes ***
	**************************************/
	Complex <float>test1(2,3), test2(1), test3;


	std::cout << "Série de test" << std::endl;

	std::cout << "Voici l'imaginaire pure : " << img_pure << std::endl;

	std::cout << "Le premier complex vaut : " << test1 << std::endl;

	std::cout << "Veuillez saisir un deuxieme complex : " << std::endl;
	std::cin >> test2;
	std::cout << "Celui ci vaut " << test2 << std::endl;

	std::cout << "On affecte les valeurs du 1er complex à un 3éme complex" << std::endl;
	test3 = test1;
	std::cout << "Voici les valeurs du 3ème complex " << test3 << std::endl;
	std::cout << std::endl;

	std::cout << "Test des opérations de bases" << std::endl;
	std::cout << "On additionne test1 : " << test1 << " et test2 : " << test2 << " dans le 3eme complex" << std::endl;
	test3 = test1 + test2;
	std::cout << "La valeur de cette addition donne " << test3 << std::endl;

	std::cout << "On soustrait test1 : " << test1 << " et test2 : " << test2 << " dans le 3eme complex" << std::endl;
	test3 = test1 - test2;
	std::cout << "Les valeurs de cette soustraction donne " << test3 << std::endl;

	std::cout << "On mutliplie test1 : " << test1 << " et test2 : " << test2 << " dans le 3eme complex" << std::endl;
	test3 = test1 * test2;
	std::cout << "Les valeurs de cette multiplication donne " << test3 << std::endl;

	std::cout << "On divise test1 : " << test1 << " et test2 : " << test2 << " dans le 3eme complex" << std::endl;
	test3 = test1 / test2;
	std::cout << "Les valeurs de cette division donne " << test3 << std::endl << std::endl;

	std::cout << "Test des opérateurs d'affections" << std::endl;

	std::cout << test3 << " += "  << test1 << " = ";
	test3 += test1;
	std::cout << test3 << std::endl;

	std::cout << test3 << " -= "  << test1 << " = ";
	test3 -= test1;
	std::cout << test3 << std::endl;

	std::cout << test3 << " *= "  << test1 << " = ";
	test3 *= test1;
	std::cout << test3 << std::endl;

	std::cout << test3 << " /= "  << test1 << " = ";
	test3 /= test1;
	std::cout << test3 << std::endl << std::endl;

	std::complex<float> test4(1,2);
	Complex<float> test5(1,2);

	std::cout << "Comparaison de l'exponentiel avec la librairie standard" << std::endl;
	std::cout << "Standard : " << std::exp(test4) << " et " <<  "Implémenté : " << exp(test4) << std::endl << std::endl;

	std::cout << "Comparaison du sinus avec la librairie standard" << std::endl;
	std::cout << "Standard : " << std::sin(test4) << " et " <<  "Implémenté : " << sin(test4) << std::endl << std::endl;

	std::cout << "Comparaison du cosinus avec la librairie standard" << std::endl;
	std::cout << "Standard : " << std::cos(test4) << " et " <<  "Implémenté : " << cos(test4) << std::endl << std::endl;

	/*************************************************
	*** Série de test sur la transformé de Fourier ***
	*************************************************/
	std::cout << "Test de la transformé de Fourier " << std::endl;

	std::vector< Complex<float> > vecteur;
	std::vector< Complex<float> > copie_vecteur;
	vecteur.push_back(test1);
	vecteur.push_back(test2);
	vecteur.push_back(test3);

	std::cout << "Voici la liste des valeurs envoyés" << std::endl;
	for (unsigned int i = 0; i < vecteur.size(); i++)
		std::cout << vecteur[i] << std::endl;
		

	std::cout << std::endl;

	std::cout << "Transformé de Fourier " << std::endl;

	vecteur = dft(vecteur);

	std::cout << "Test de la transformé inverse de Fourier " << std::endl;
	inverse_dft(vecteur);

	return 0;
}