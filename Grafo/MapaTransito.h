#pragma once

#include <queue>
#include <map>
#include <sstream>
#include <fstream>
#include  <io.h>

#include "BaseGrafo.h"

namespace Archivo{
	const char CALLE[] = "calle.txt";
	const char INTERSECCION[] = "interseccion.txt";
}

using namespace std;

#define INF 1<<30

class MapaTransito :
	public BaseGrafo<Calle, Interseccion>
{
private:
	priority_queue<Etiqueta, vector<Etiqueta>, comparador> pq;
	map<string,string> anteriores;
public:
	MapaTransito(void);
	virtual ~MapaTransito(void);
	void inicializar() override;
	void inicializarValoreParaDijkstra() override;
	void actualizarEtiqueta(string origen, string destino, int peso) override;
	void imprimir(string destino) override;
	void caminoMasCorto(string origen, string destino, int hora);
	void grabarCalles(vector<Calle> calles);
	void grabarIntersecciones(vector<Interseccion> intersecciones);
	vector<string> leerArchivo(string rutaArchivo);
	vector<string> split(string str, char delimitador);
	Calle parsearCalle(string lineaArchivo);
	Interseccion parsearInterseccion(string lineaArchivo);

	//GETTER'S AND SETTER'S
	vector<Calle> getCalles(void);
	void setCalles(vector<Calle> calles);
	vector<Interseccion> getIntersecciones(void);
	void setIntersecciones(vector<Interseccion> intersecciones);
	vector<Etiqueta> getEtiquetas(void);
	void setEtiquetas(vector<Etiqueta> etiquetas);
};

