#include "StdAfx.h"
#include "Horario.h"

Horario::Horario(void){
}

Horario::Horario(int hora, int nivelCongestionamiento){
	this->hora = hora;
	this->nivelCongestionamiento = nivelCongestionamiento;
}

Horario::~Horario(void){
}

//getters and setters
int Horario::getHora(){
	return hora;
}

void Horario::setHora(int hora){
	this->hora = hora;
};

int Horario::getNivelCongestionamiento(){
	return nivelCongestionamiento;
}

void Horario::setNivelCongestionamianto(int nivelCongestionamiento){
	this->nivelCongestionamiento = nivelCongestionamiento;
}

