#include "StdAfx.h"
#include "Etiqueta.h"


Etiqueta::Etiqueta(void){
	this->valorAcomulado = 0;
	this->verticeProcedente = Vertice();
}

Etiqueta::Etiqueta(int valorAcomulado, Vertice verticeProcedente){
	this->valorAcomulado = valorAcomulado;
	this->verticeProcedente = verticeProcedente;
}

Etiqueta::~Etiqueta(void){
}

//getters and setters
int Etiqueta::getValorAcomulado(void) const{
	return valorAcomulado;
}

void Etiqueta::setValorAcomulado(int valorAcomulado){
	this->valorAcomulado = valorAcomulado;
}

Vertice Etiqueta::getVerticeProcedente(void){
	return verticeProcedente;
}

void Etiqueta::setVerticeProcedente(Vertice verticeProcedente){
	this->verticeProcedente = verticeProcedente;
}
