#include "StdAfx.h"
#include "Interseccion.h"

Interseccion::Interseccion(void){
}

Interseccion::Interseccion(Vertice origen, Vertice destino, int tiempo){
	this->origen = origen;
	this->destino = destino;
	this->tiempo = tiempo;

	generarHorarios();
}

Interseccion::~Interseccion(void){
}

void Interseccion::generarHorarios(){
	//cargo un vector con las horas de transito.
	vector<int> horas;
	horas.push_back(Hora::SIETE_AM);
	horas.push_back(Hora::DIEZ_AM);
	horas.push_back(Hora::UNA_PM);
	horas.push_back(Hora::TRES_PM);
	horas.push_back(Hora::CINCO_PM);
	horas.push_back(Hora::OCHO_PM);

	//cargo el horario de forma aleatoria con rango de 0 a 60 minutos de nivel de congestinomiento.
	for(unsigned i=0; i<horas.size(); i++){
		int hora = horas.at(i);
		int congestion = rand()%MAX_RANDOM;

		horarios.push_back(Horario(hora, congestion));
	}
}

int Interseccion::obtenerNivelDeCongestionamientoPorHora(int hora){
	for(unsigned i=0; i<getHorarios().size(); i++){
		if(getHorarios().at(i).getHora() == hora)
			return getHorarios().at(i).getNivelCongestionamiento();
	}
	return 0;
}

//GETTERS AND SETTERS
vector<Horario> Interseccion::getHorarios(){
	return horarios;
}

void Interseccion::setHorarios(vector<Horario> horarios){
	this->horarios = horarios;
}
