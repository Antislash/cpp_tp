#include "question.hpp"

std::string give_question(int index){
	return questions[index].question;
}

int result(int index , char rep){
	if(rep == 'y')
		return questions[index].yes;
	else
		return questions[index].no;
}