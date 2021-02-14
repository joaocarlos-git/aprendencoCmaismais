
#include "professor.h"

//Construtor parametrizado
Professor::Professor(int codigo, string nome) {
	this->setCodigo(codigo);
	this->setNome(nome);

	cout << "objeto criado" << endl;
}

//Construtor de cópia
Professor::Professor(const Professor &p) {
	this->codigo = p.codigo;
	this->nome = p.nome;

	cout << "objeto copiado" << endl;
}

//Destrutor da classe
Professor::~Professor() {
	cout << "objeto destruído" << endl;
}

//GETTERS - accessor methods
int Professor::getCodigo() {
	return codigo;
}

string Professor::getNome() {
	return nome;
}

//SETTERS - mutator methods
void Professor::setCodigo(int codigo) {
	if(codigo < 0) { //Se o valor de código for negativo
		this->codigo = (-1) * codigo; //O valor é convertido para positivo
	}
	else{
		this->codigo = codigo;
	}
}

void Professor::setNome(string nome) {
	this->nome = nome;
}

void Professor::alteraNotaAlunoGraduacao(graduacao::Aluno &a, float n1, float n2) {

	if( n1 < 0 || n1 > 10 || n2 < 0 || n2 > 10)	{
		throw "Valores fora do intervalo de 0 a 10";
	}

	a.notas[0] = n1;
	a.notas[1] = n2;
}

void Professor::alteraNotaAlunoPosGraduacao(posgraduacao::Aluno &a, float n1, float n2) {

	if( n1 < 0 || n1 > 10 || n2 < 0 || n2 > 10)	{
		throw "Valores fora do intervalo de 0 a 10";
	}

	a.notas[0] = n1;
	a.notas[1] = n2;
}
