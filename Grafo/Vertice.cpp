#include "StdAfx.h"
#include "Vertice.h"

Vertice::Vertice(void){
	this->id = -1;
	this->nombre = "";
	this->visitado = false;
}

Vertice::Vertice(int id, string nombre){
	this->id = id;
	this->nombre = nombre;
	this->visitado = false;
}

Vertice::~Vertice(void){
}

//getters and setters
int Vertice::getId(void){
	return id;
}

void Vertice::setId(int id){
	this->id = id;
}

string Vertice::getNombre(void){
	return nombre;
}

void Vertice::setNombre(string nombre){
	this->nombre = nombre;
}

bool Vertice::getVisitado(void){
	return visitado;
}

void Vertice::setVisitado(bool visitado){
	this->visitado = visitado;
}