#include "StdAfx.h"
#include "BaseGrafo.h"

template<class V, class A> 
BaseGrafo<V,A>::BaseGrafo(void){
}

template<class V, class A> 
BaseGrafo<V,A>::~BaseGrafo(void){
}

template<class V, class A> 
void BaseGrafo<V,A>::agregarVertice(V vertice){
	vertices.push_back(vertice);
}

template<class V, class A> 
void BaseGrafo<V,A>::clearVertices(void){
	vertices.clear();
}

template<class V, class A> 
void BaseGrafo<V,A>::agregarArista(A arista){
	aristas.push_back(arista);
}

template<class V, class A> 
void BaseGrafo<V,A>::clearAristas(void){
	aristas.clear();
}

/**
* Obtiene un vertice por su id.
* @param id id del vertice.
* @return el vertice.
*/
template<class V, class A> 
V BaseGrafo<V,A>::obtenerVerticePorId(int id){
	V vertice;
	for(unsigned i=0; i<vertices.size(); i++){
		if(vertices.at(i).getId() == id){
			vertice = vertices.at(i);
		}
	}
	return vertice;
}

/**
* Obtiene un vertice por su nombre.
* @param nombre nombre del vertice.
* @return el vertice.
*/
template<class V, class A> 
V BaseGrafo<V,A>::obtenerVerticePorNombre(string nombre){
	V vertice;
	for(unsigned i=0; i<vertices.size(); i++){
		if(vertices.at(i).getNombre() == nombre){
			vertice = vertices.at(i);
		}
	}
	return vertice;
}

/**
* Obtiene un vector de las arista de un vertice.
* @param origen vertice origen de las arista
* @return un vector con las arista.
*/
template<class V, class A> 
vector<A> BaseGrafo<V,A>::obtenerAristaPorOrigen(string origen){
	vector<A> intersecciones;
	for(unsigned i=0; i<aristas.size(); i++){
		if(aristas.at(i).getOrigen().getNombre() == origen){
			intersecciones.push_back(aristas.at(i));
		}
	}
	return intersecciones;
}

/**
* Obtiene una etiqueta de una calle.
* @param nombre nombre de la calle
* @return un etiqueta.
*/
template<class V, class A>
Etiqueta BaseGrafo<V,A>::obtenerEtiquetaPorVertice(string nombre){
	Etiqueta etiqueta;
	for(unsigned i=0; i<etiquetas.size(); i++){
		if(etiquetas.at(i).getVerticeProcedente().getNombre() == nombre){
			etiqueta = etiquetas.at(i);
		}
	}
	return etiqueta;
}

/**
* Remplaza una etiqueta por otra.
* @param etiqueta la etiqueta que remplazara
*/
template<class V, class A>
void BaseGrafo<V,A>::remplazarEtiqueta(Etiqueta etiqueta){
	for(unsigned i=0;i<etiquetas.size(); i++){
		if(etiqueta.getVerticeProcedente().getNombre() == etiquetas.at(i).getVerticeProcedente().getNombre()){
			etiquetas[i] = etiqueta;
		}
	}
}

// explicit instantiations
template class BaseGrafo<Vertice,Arista>;
template class BaseGrafo<Calle,Interseccion>;