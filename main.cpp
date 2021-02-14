#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <locale.h>

#include "aluno.h"
#include "professor.h"
using namespace std;

class Universidade {

private:
	vector<graduacao::Aluno> alunosGraduacao;
	vector<posgraduacao::Aluno> alunosPosGraduacao;

public:
	void calculaMediaGeralGraduacao() {
		float soma = 0.0F;

		int qtde = 0;
		for(unsigned int i = 0; i < alunosGraduacao.size(); i++) {
			soma += alunosGraduacao[i].calculaMedia();
			qtde++;
		}

		if(qtde > 0){
			cout << "M�dia geral dos alunos da gradua��o: " << soma/qtde << endl;
		}
		else{
			cout << "M�dia geral dos alunos da gradua��o: 0.0" << endl;
		}
	}

	void calculaMediaGeralPosGraduacao() {
		float soma = 0.0F;

		int qtde = 0;
		for(unsigned int i = 0; i < alunosPosGraduacao.size(); i++) {
			soma += alunosPosGraduacao[i].calculaMedia();
			qtde++;
		}

		if(qtde > 0){
			cout << "M�dia geral dos alunos da p�s-gradua��o: " << soma/qtde << endl;
		}
		else{
			cout << "M�dia geral dos alunos da p�s-gradua��o: 0.0" << endl;
		}
	}

	void adicionaAlunoGraduacao(graduacao::Aluno a) {
		alunosGraduacao.push_back(a);
	}

	void adicionaAlunoPosGraduacao(posgraduacao::Aluno a) {
		alunosPosGraduacao.push_back(a);
	}
};


int main() {
    setlocale(LC_ALL,"portuguese");
	//Objeto universidade
	Universidade u;

	/********************************************************************/

	//Aluno da gradua��o Jo�o
	graduacao::Aluno joao("Jo�o");
	/*
	float notas[2] = {10.0F, 8.5F}; //aloca��o est�tica (STACK)
	float *notas = new float[2]{10.0F, 8.5F}; //aloca��o din�mica (HEAP)
	*/

	joao.setNotas(new float[2]{10.0F, 8.5F});
	u.adicionaAlunoGraduacao(joao); //Adiciona aluno � universidade

	//Aluno da gradua��o Maria
	graduacao::Aluno maria("Maria");
	maria.setNotas(new float[2]{7.0F, 8.5F});
	u.adicionaAlunoGraduacao(maria); //Adiciona aluno � universidade

	//Aluno da gradua��o Pedro
	graduacao::Aluno pedro("Pedro");
	pedro.setNotas(new float[2]{6.0F, 0.5F});
	u.adicionaAlunoGraduacao(pedro); //Adiciona aluno � universidade

	/********************************************************************/

	//Aluno da p�s-gradua��o Jo�o
	posgraduacao::Aluno carlos("Carlos");
	carlos.setNotas(new float[2]{8.0F, 8.5F});
	u.adicionaAlunoPosGraduacao(carlos); //Adiciona aluno � universidade

	//Aluno da p�s-gradua��o Renata
	posgraduacao::Aluno renata("Renata");
	renata.setNotas(new float[2]{7.0F, 8.5F});
	u.adicionaAlunoPosGraduacao(renata); //Adiciona aluno � universidade

	//Aluno da p�s-gradua��o Pedro
	posgraduacao::Aluno jose("Jos�");
	jose.setNotas(new float[2]{6.0F, 7.5F});
	u.adicionaAlunoPosGraduacao(jose); //Adiciona aluno � universidade

	/* Par�metros:
	a refer�ncia para a fun��o membro da classe
	e o endere�o de mem�ria do objeto o qual chama esta fun��o */
	thread tGrad(&Universidade::calculaMediaGeralGraduacao, &u);
	thread tPos(&Universidade::calculaMediaGeralPosGraduacao, &u);

	tGrad.join();
	tPos.join();

	return 0;
}
