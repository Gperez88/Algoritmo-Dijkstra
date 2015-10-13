#pragma once
#include "Vertice.h"

class Arista
{
protected:
	Vertice origen;
	Vertice destino;
	int tiempo;
public:
	Arista(void);
	Arista(Vertice origen, Vertice destino);
	Arista(Vertice origen, Vertice destino, int tiempo);
	virtual ~Arista(void);

	//GETTERS AND SETTERS
	Vertice getOrigen(void);
	void setOrigen(Vertice origen);
	Vertice getDestino(void);
	void setDestino(Vertice destino);
	int getTiempo(void);
	void setTiempo(int tiempo);
};

