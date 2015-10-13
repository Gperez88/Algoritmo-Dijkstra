#include "StdAfx.h"
#include "Arista.h"

Arista::Arista(void){
}

Arista::Arista(Vertice origen, Vertice destino){
	this->origen = origen;
	this->destino = destino;
}

Arista::Arista(Vertice origen, Vertice destino,int tiempo){
	this->origen = origen;
	this->destino = destino;
	this->tiempo = tiempo;
}

Arista::~Arista(void){
}

//GETTERS AND SETTERS
Vertice Arista::getOrigen(){
	return origen;
}

void Arista::setOrigen(Vertice origen){
	this->origen = origen;
}

Vertice Arista::getDestino(){
	return destino;
}

void Arista::setDestino(Vertice destino){
	this->destino = destino;
}

int Arista::getTiempo(){
	return tiempo;
}

void Arista::setTiempo(int tiempo){
	this->tiempo = tiempo;
}


