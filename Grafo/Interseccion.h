#pragma once
#include <vector>
#include "Arista.h"
#include "Horario.h"

//maximo del random, teniendo como unidad de tiempo minuto.
#define MAX_RANDOM 61;

class Interseccion :
	public Arista
{
private:
	vector<Horario> horarios;
public:
	Interseccion(void);
	Interseccion(Vertice origen, Vertice destino, int tiempo);
	virtual ~Interseccion(void);
	void generarHorarios();
	int obtenerNivelDeCongestionamientoPorHora(int hora);

	//GETTERS AND SETTERS
	vector<Horario> getHorarios(void);
	void setHorarios(vector<Horario> horarios);
};

