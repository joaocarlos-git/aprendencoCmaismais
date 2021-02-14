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
			cout << "Média geral dos alunos da graduação: " << soma/qtde << endl;
		}
		else{
			cout << "Média geral dos alunos da graduação: 0.0" << endl;
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
			cout << "Média geral dos alunos da pós-graduação: " << soma/qtde << endl;
		}
		else{
			cout << "Média geral dos alunos da pós-graduação: 0.0" << endl;
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

	//Aluno da graduação João
	graduacao::Aluno joao("João");
	/*
	float notas[2] = {10.0F, 8.5F}; //alocação estática (STACK)
	float *notas = new float[2]{10.0F, 8.5F}; //alocação dinâmica (HEAP)
	*/

	joao.setNotas(new float[2]{10.0F, 8.5F});
	u.adicionaAlunoGraduacao(joao); //Adiciona aluno à universidade

	//Aluno da graduação Maria
	graduacao::Aluno maria("Maria");
	maria.setNotas(new float[2]{7.0F, 8.5F});
	u.adicionaAlunoGraduacao(maria); //Adiciona aluno à universidade

	//Aluno da graduação Pedro
	graduacao::Aluno pedro("Pedro");
	pedro.setNotas(new float[2]{6.0F, 0.5F});
	u.adicionaAlunoGraduacao(pedro); //Adiciona aluno à universidade

	/********************************************************************/

	//Aluno da pós-graduação João
	posgraduacao::Aluno carlos("Carlos");
	carlos.setNotas(new float[2]{8.0F, 8.5F});
	u.adicionaAlunoPosGraduacao(carlos); //Adiciona aluno à universidade

	//Aluno da pós-graduação Renata
	posgraduacao::Aluno renata("Renata");
	renata.setNotas(new float[2]{7.0F, 8.5F});
	u.adicionaAlunoPosGraduacao(renata); //Adiciona aluno à universidade

	//Aluno da pós-graduação Pedro
	posgraduacao::Aluno jose("José");
	jose.setNotas(new float[2]{6.0F, 7.5F});
	u.adicionaAlunoPosGraduacao(jose); //Adiciona aluno à universidade

	/* Parâmetros:
	a referência para a função membro da classe
	e o endereço de memória do objeto o qual chama esta função */
	thread tGrad(&Universidade::calculaMediaGeralGraduacao, &u);
	thread tPos(&Universidade::calculaMediaGeralPosGraduacao, &u);

	tGrad.join();
	tPos.join();

	return 0;
}
