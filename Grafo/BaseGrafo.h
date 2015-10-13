#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Vertice.h"
#include "Arista.h"
#include "Calle.h"
#include "Interseccion.h"
#include "Etiqueta.h"

using namespace std;

//La cola de prioridad de C++ por default es un max-Heap (elemento de mayor valor en el tope)
//por ello es necesario realizar nuestro comparador para que sea un min-Heap
struct comparador {
	bool operator() (const Etiqueta& a ,const Etiqueta& b) const {
		return a.getValorAcomulado() < b.getValorAcomulado();
	}
};

template<class V, class A>
class BaseGrafo
{
protected:
	vector<V> vertices;
	vector<A> aristas;
	vector<Etiqueta> etiquetas;
public:
	BaseGrafo(void);
	virtual ~BaseGrafo(void);
	virtual void agregarVertice(V vertice);
	virtual void clearVertices(void);
	virtual void agregarArista(A arista);
	virtual void clearAristas(void);
	virtual V obtenerVerticePorId(int id);
	virtual V obtenerVerticePorNombre(string nombre);
	virtual vector<A> obtenerAristaPorOrigen(string origen);
	virtual Etiqueta obtenerEtiquetaPorVertice(string nombre);
	virtual void remplazarEtiqueta(Etiqueta etiqueta);

	//METODOS ABSTRACTOS
	virtual void inicializar(void) = 0;
	virtual void inicializarValoreParaDijkstra(void) = 0;
	virtual void actualizarEtiqueta(string origen, string destino, int peso) = 0;
	virtual void imprimir(string destino) = 0;
};
