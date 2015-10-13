#pragma once

#include "Vertice.h"

class Etiqueta
{
private:
	int valorAcomulado;
	Vertice verticeProcedente;
public:
	Etiqueta(void);
	Etiqueta(int valorAcomulado, Vertice verticeProcedente);
	virtual ~Etiqueta(void);

	//GETTERS AND SETTERS
	int getValorAcomulado() const;
	void setValorAcomulado(int valor);
	Vertice getVerticeProcedente();
	void setVerticeProcedente(Vertice vertice);
};

