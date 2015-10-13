#pragma once
#include <string>
#include "Vertice.h"

class Calle :
	public Vertice
{
public:
	Calle(void);
	Calle(int id, string nombre);
	virtual ~Calle(void);
};

