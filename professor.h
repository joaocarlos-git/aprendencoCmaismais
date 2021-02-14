
#include "aluno.h"

#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <iostream>
#include <string>
using namespace std;

//Forward declaration class
namespace graduacao {
	class Aluno;
}

//Forward declaration class
namespace posgraduacao {
	class Aluno;
}

class Professor {

private:
	int codigo;
	string nome;

public:
	//Construtor default
	Professor();
	//Construtor parametrizado
	Professor(int codigo, string nome);
	//Construtor de cópida
	Professor(const Professor &p);
	//Destrutor da classe
	~Professor();

	//GETTERS - accessor methods
	int getCodigo();
	string getNome();

	//SETTERS - mutator methods
	void setCodigo(int codigo);
	void setNome(string nome);

	void alteraNotaAlunoGraduacao(graduacao::Aluno &a, float n1, float n2);
	void alteraNotaAlunoPosGraduacao(posgraduacao::Aluno &a, float n1, float n2);
};


#endif /* PROFESSOR_H_ */
