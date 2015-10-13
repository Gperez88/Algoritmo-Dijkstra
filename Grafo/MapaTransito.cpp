#include "StdAfx.h"
#include "MapaTransito.h"
#include "Horario.h"

using namespace Archivo;

MapaTransito::MapaTransito(void) {
}

MapaTransito::~MapaTransito(void){
}

/**
* Inicializa el grafo del mapa de transito.
*/
void MapaTransito::inicializar(){
	vector<string> archivoVertice = leerArchivo(Archivo::CALLE);
	vector<string> archivoArista = leerArchivo(Archivo::INTERSECCION);

	clearVertices();
	clearAristas();
	
	for(unsigned i = 0; i < archivoVertice.size(); i++){
		agregarVertice(parsearCalle(archivoVertice.at(i)));
	}

	for(unsigned i = 0; i < archivoArista.size(); i++){
		agregarArista(parsearInterseccion(archivoArista.at(i)));
	}
}

void MapaTransito::inicializarValoreParaDijkstra(){
	for(unsigned i=0; i<vertices.size(); i++){
		etiquetas.push_back(Etiqueta(INF, vertices.at(i)));	
		anteriores[vertices.at(i).getNombre()] = "";
	}
}

/**
* Actualiza la etiqueta destino o adyacente, esto siempre y cuando el valor acomulado de la etiqueta origen + el peso 
* sea menor al valor acomulado de la etiqueta destino o adyacente.
* @param origen calle o vertice origen
* @param destino calle o vertice destino
* @param peso tiempo o peso de la interseccion o arista.
*/
void MapaTransito::actualizarEtiqueta(string origen, string destino, int peso){
	Etiqueta etiquetaOrigen = obtenerEtiquetaPorVertice(origen);
	Etiqueta etiquetaDestino = obtenerEtiquetaPorVertice(destino);
	
	if(etiquetaOrigen.getValorAcomulado() + peso < etiquetaDestino.getValorAcomulado()){
		etiquetaDestino.setValorAcomulado(etiquetaOrigen.getValorAcomulado() + peso);
		remplazarEtiqueta(etiquetaDestino);
		anteriores[etiquetaDestino.getVerticeProcedente().getNombre()] = etiquetaOrigen.getVerticeProcedente().getNombre();
		pq.push(etiquetaDestino);
	}
}

/**
* Imprime la serie de pasos del camino mas corto asia un destino.
* @param destino punto de destino.
*/
void MapaTransito::imprimir(string destino){
	if(anteriores[destino] != "") {
		imprimir(anteriores[destino]);
	}
	cout << "*- " << destino << endl;
}

//Algoritmo de Dijkstra.
void MapaTransito::caminoMasCorto(string origen, string destino, int hora){
	//inicializo todo para implementar el Algoritmo de Dijkstra.
	inicializarValoreParaDijkstra();
	//obtengo el punto de partida.
	Calle calleOrigen = obtenerVerticePorNombre(origen);

	// inserto en la cola de prioridad la etiqueta del vertice origen y la pongo en valor 0
	// ya que es el punto de partida y por ende el primer vertice visitado.
	Etiqueta etiqueta = obtenerEtiquetaPorVertice(calleOrigen.getNombre());
	etiqueta.setValorAcomulado(0);
	pq.push(etiqueta);
	// remplazo la etiqueta con los valores actualizados.
	remplazarEtiqueta(etiqueta);

	Vertice actual;
	Vertice adyacente;
	int peso;

	while(!pq.empty()){
		actual = pq.top().getVerticeProcedente();
		pq.pop();

		if(actual.getVisitado()) continue;
		actual.setVisitado(true);

		vector<Interseccion> intersecciones = obtenerAristaPorOrigen(actual.getNombre());
		for(unsigned i = 0 ; i < intersecciones.size() ; ++i ){
			adyacente = intersecciones.at(i).getDestino();
			peso = intersecciones.at(i).getTiempo() + intersecciones.at(i).obtenerNivelDeCongestionamientoPorHora(hora);

			if(!adyacente.getVisitado()){
				actualizarEtiqueta(actual.getNombre(), adyacente.getNombre(), peso);
			}
		}
	}

	cout << "************* El camino mas corto *************" << endl;
	imprimir(destino);

	cout << "---------------------------------------------" << endl
		 << "El tiempo total en recorres el camino mas corte fue de: " 
		 << obtenerEtiquetaPorVertice(destino).getValorAcomulado() << endl 
		 << endl;
}

/**
* Hace un split de un string y lo pasa a un vector.
* @param str string a separar.
* @param delimitador delimitador de separacion.
* @return vector con los elementos separados.
*/
vector<string> MapaTransito::split(string str, char delimitador) {
  vector<string> vector;
  stringstream ss(str);
  string tok;
  
  while(getline(ss, tok, delimitador)) {
    vector.push_back(tok);
  }
  
  return vector;
}

void MapaTransito::grabarCalles(vector<Calle> calles){
	ofstream outFile = ofstream();
	outFile.open(Archivo::CALLE, ios::app);

	for(unsigned i = 0; i < calles.size(); i++){
		int id = calles.at(i).getId();
		string nombre = calles.at(i).getNombre();

		outFile << id << "|" << nombre << endl;
	}

	outFile.close();
}

void MapaTransito::grabarIntersecciones(vector<Interseccion> intesecciones){
	ofstream outFile = ofstream();
	outFile.open(Archivo::INTERSECCION, ios::app);

	for(unsigned i = 0; i < intesecciones.size(); i++){
		int idOrigen = intesecciones.at(i).getOrigen().getId();
		int idDestino = intesecciones.at(i).getDestino().getId();
		int tiempo = intesecciones.at(i).getTiempo();

		outFile << idOrigen << "|" << idDestino << "|" << tiempo << endl;
	}

	outFile.close();
}

/**
* Lee un archivo line por linea y las mete en un vector.
* @param rutaArchivo ruta donde se encuentra el archivo.
* @return vector con las lineas.
*/
vector<string> MapaTransito::leerArchivo(string rutaArchivo){
	ifstream inputFile = ifstream();
	inputFile.open(rutaArchivo);

	vector<string> lineas;
	string linea;

	while(inputFile.good()){
		getline(inputFile,linea);
		remove(linea.begin(), linea.end(),' ');
		
		if(linea != "")
			lineas.push_back(linea);
	}

	return lineas;
}

/**
* Parsea un string y transforma en una calle.
* @param lineaArchivo linea a parsear.
* @return una Calle.
*/
Calle MapaTransito::parsearCalle(string lineaArchivo){
	Calle calle;
	vector<string> elementos = split(lineaArchivo,'|');
	
	if(elementos.size() == 2){
		int id = atoi(elementos.at(0).c_str());
		string nombre = elementos.at(1);

		calle = Calle(id,nombre);
	}

	return calle;
}

/**
* Parsea un string y transforma en una interseccion.
* @param lineaArchivo linea a parsear.
* @return una Interseccion.
*/
Interseccion MapaTransito::parsearInterseccion(string lineaArchivo){
	Interseccion interseccion;
	vector<string> elementos = split(lineaArchivo,'|');

	if(elementos.size() == 3){
		Calle origen = obtenerVerticePorId(atoi(elementos.at(0).c_str()));
		Calle destino = obtenerVerticePorId(atoi(elementos.at(1).c_str()));
		int peso = atoi(elementos.at(2).c_str());

		interseccion = Interseccion(origen,destino,peso);
	}

	return interseccion;
}

//GETTER'S AND SETTER'S
vector<Calle> MapaTransito::getCalles(){
	return vertices;
}

void MapaTransito::setCalles(vector<Calle> calles){
	this->vertices = calles;
}

vector<Interseccion> MapaTransito::getIntersecciones(){
	return aristas;
}

void MapaTransito::setIntersecciones(vector<Interseccion> intersecciones){
	this->aristas = intersecciones;
}

vector<Etiqueta> MapaTransito::getEtiquetas(){
	return etiquetas;
}

void MapaTransito::setEtiquetas(vector<Etiqueta> etiquetas){
	this->etiquetas = etiquetas;
}

