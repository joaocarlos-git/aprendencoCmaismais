#include "aluno.h"

int graduacao::Aluno::proxCodigo = 1;
int posgraduacao::Aluno::proxCodigo = 1;

//Construtor parametrizado
graduacao::Aluno::Aluno(string nome) {
	this->codigo = getProxCodigo();
	this->setNome(nome);
	this->valorMensalidade = 0.0;

	//cout << "objeto criado" << endl;
}

//Construtor parametrizado
posgraduacao::Aluno::Aluno(string nome) {
	this->codigo = getProxCodigo();
	this->setNome(nome);
	this->valorMensalidade = 0.0;

	//cout << "objeto criado" << endl;
}

//Destrutor da classe
graduacao::Aluno::~Aluno() {
	//cout << "objeto destruído" << endl;
}

//Destrutor da classe
posgraduacao::Aluno::~Aluno() {
	//cout << "objeto destruído" << endl;
}

//GETTERS - accessor methods
int graduacao::Aluno::getCodigo() {
	return codigo;
}

int posgraduacao::Aluno::getCodigo() {
	return codigo;
}

string graduacao::Aluno::getNome() {
	return nome;
}

string posgraduacao::Aluno::getNome() {
	return nome;
}

float *graduacao::Aluno::getNotas() {
	return notas;
}

float *posgraduacao::Aluno::getNotas() {
	return notas;
}

//SETTERS - mutator methods
void graduacao::Aluno::setCodigo(int codigo) {
	if(codigo < 0) { //Se o valor de código for negativo
		this->codigo = (-1) * codigo; //O valor é convertido para positivo
	}
	else{
		this->codigo = codigo;
	}
}

void posgraduacao::Aluno::setCodigo(int codigo) {
	if(codigo < 0) { //Se o valor de código for negativo
		this->codigo = (-1) * codigo; //O valor é convertido para positivo
	}
	else{
		this->codigo = codigo;
	}
}

void graduacao::Aluno::setNome(string nome) {
	this->nome = nome;
}

void posgraduacao::Aluno::setNome(string nome) {
	this->nome = nome;
}

void graduacao::Aluno::setValorMensalidade(double valorMensalidade) {
	this->valorMensalidade = valorMensalidade;
}

void posgraduacao::Aluno::setValorMensalidade(double valorMensalidade) {
	this->valorMensalidade = valorMensalidade;
}

void graduacao::Aluno::setNotas(float notas[]) {
	this->notas[0] = notas[0];
	this->notas[1] = notas[1];
}

void posgraduacao::Aluno::setNotas(float notas[]) {
	this->notas[0] = notas[0];
	this->notas[1] = notas[1];
}

/*************************************************/

float graduacao::Aluno::calculaMedia() {
	float soma = 0.0f;
	int i = 0;

	for(i=0; i <= 1; i++) {
		soma = soma + notas[i];
	}

	return soma/i;
}

float posgraduacao::Aluno::calculaMedia() {
	float soma = 0.0f;
	int i = 0;

	for(i=0; i <= 1; i++) {
		soma = soma + notas[i];
	}

	return soma/i;
}

/*************************************************/

int graduacao::Aluno::getProxCodigo() {
	return proxCodigo++;
}

int posgraduacao::Aluno::getProxCodigo() {
	return proxCodigo++;
}

/*************************************************/

double graduacao::Aluno::calculaValorMensalidade() {
	return valorMensalidade;
}

double posgraduacao::Aluno::calculaValorMensalidade() {
	return valorMensalidade;
}


/*************************************************/

void graduacao::Aluno::imprimeSaudacao() {
	cout << "Olá eu sou o aluno da graduação " << getNome() << endl;
}

void posgraduacao::Aluno::imprimeSaudacao() {
	cout << "Olá eu sou o aluno da pós-graduação " << getNome() << endl;
}

/*************************************************/
/*************************************************/
/*************************************************/


//Construtor
graduacao::AlunoPesquisador::AlunoPesquisador(string nome) : Aluno(nome) {

}

//Destrutor
graduacao::AlunoPesquisador::~AlunoPesquisador(){

}

//Getters
double graduacao::AlunoPesquisador::getBolsa() {
	return bolsa;
}

string graduacao::AlunoPesquisador::getLinha() {
	return linha;
}

string graduacao::AlunoPesquisador::getOrientador() {
	return orientador;
}

//Setters
void graduacao::AlunoPesquisador::setBolsa(double bolsa) {
	this->bolsa = bolsa;
}

void graduacao::AlunoPesquisador::setLinha(string linha) {
	this->linha = linha;
}

void graduacao::AlunoPesquisador::setOrientador(string orientador) {
	this->orientador = orientador;
}

//SOBREPOSIÇÃO DE MÉTODOS
void graduacao::AlunoPesquisador::imprimeSaudacao() {
	cout << "Olá eu sou o aluno pesquisador " << getNome() << endl;
}

//SOBREPOSIÇÃO DE MÉTODOS
double graduacao::AlunoPesquisador::calculaValorMensalidade() {
	//valorMensalidade é um membro marcado como protegido na classe base (Aluno)
	return (valorMensalidade - (valorMensalidade * bolsa/100));
}

//SOBRECARGA DE MÉTODO
double graduacao::AlunoPesquisador::calculaValorMensalidade(double bonus) {
	return (valorMensalidade - (valorMensalidade * bolsa/100)) - bonus;
}
