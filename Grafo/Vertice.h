#pragma once
#include <string>
#include <iostream>

using namespace std;

class Vertice
{
protected:
	int id;
	string nombre;
	bool visitado;
public:
	Vertice(void);
	Vertice(int id, string nombre);
	virtual ~Vertice(void);

	//GETTERS AND SETTERS
	int getId(void);
	void setId(int id);
	string getNombre(void);
	void setNombre(string nombre);
	bool getVisitado(void);
	void setVisitado(bool visitado);
};

