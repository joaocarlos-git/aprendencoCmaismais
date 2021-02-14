
#ifndef ALUNO_H_
#define ALUNO_H_

#include <iostream>
#include <string>
#include "professor.h"
using namespace std;

namespace posgraduacao {

	class Aluno {
	private:
		int codigo;
		string nome;

		float notas[2] = {0.0, 0.0};

		static int proxCodigo;

	protected:
		double valorMensalidade;

	public:
		//Construtor parametrizado
		Aluno(string nome);
		//Destrutor da classe
		~Aluno();

		//GETTERS - accessor methods
		int getCodigo();
		string getNome();
		float *getNotas();

		//SETTERS - mutator methods
		void setCodigo(int codigo);
		void setNome(string nome);
		void setValorMensalidade(double valorMensalidade);
		void setNotas(float notas[]);
		float calculaMedia();

		//Função amiga declarada na classe Professor
		friend void Professor::alteraNotaAlunoPosGraduacao(Aluno &a, float n1, float n2);

		//Função estática
		static int getProxCodigo();

		double calculaValorMensalidade();

		//Função virtual
		virtual void imprimeSaudacao();
	};
}

/***********************************************/

namespace graduacao {

	class Aluno {

	private:
		int codigo;
		string nome;

		float notas[2] = {0.0, 0.0};

		static int proxCodigo;

	protected:
		double valorMensalidade;

	public:
		//Construtor parametrizado
		Aluno(string nome);
		//Destrutor da classe
		~Aluno();

		//GETTERS - accessor methods
		int getCodigo();
		string getNome();
		float *getNotas();

		//SETTERS - mutator methods
		void setCodigo(int codigo);
		void setNome(string nome);
		void setValorMensalidade(double valorMensalidade);
		void setNotas(float notas[]);
		float calculaMedia();

		//Função amiga declarada na classe Professor
		friend void Professor::alteraNotaAlunoGraduacao(Aluno &a, float n1, float n2);

		//Função estática
		static int getProxCodigo();

		double calculaValorMensalidade();

		//Função virtual
		virtual void imprimeSaudacao();
	};

	class AlunoPesquisador : public Aluno {

	private:
		string orientador;
		string linha;
		double bolsa;

	public:
		//Construtor
		AlunoPesquisador(string nome);
		//Destrutor
		~AlunoPesquisador();

		//Getters
		double getBolsa();
		string getLinha();
		string getOrientador();

		//Setters
		void setBolsa(double bolsa);
		void setLinha(string linha);
		void setOrientador(string orientador);

		//SOBREPOSIÇÃO DE MÉTODOS
		void imprimeSaudacao();

		//SOBREPOSIÇÃO DE MÉTODOS
		double calculaValorMensalidade();

		//SOBRECARGA DE MÉTODO
		double calculaValorMensalidade(double bonus);
	};

}

#endif /* ALUNO_H_ */
