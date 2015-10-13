// main.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"

#include "MapaTransito.h"

using namespace Archivo;

int opcion;
MapaTransito mapaTransito;

int menuPrincipal();
void agregarCalle();
void crearInterseccion();
void verRutaMasCorta();
void cargarCallesMapaTransito(MapaTransito* mapaTransito);

int _tmain(int argc, _TCHAR* argv[]) {
	return menuPrincipal();
}

int menuPrincipal(){
	const int AGREGAR_CALLE = 1;
	const int CREAR_INTERSECCION = 2;
	const int RUTA_MAS_CORTO = 3;
	const int SALIR = 4;

	int opcion;
	mapaTransito = MapaTransito();
	
	system("CLS");
	cout << "-- Algoritmo de Transito --" << endl
		<< "---------------------------" << endl 
		<< endl
		<< "Opciones:" << endl
		<< "1 - Agregar calle." << endl
		<< "2 - Crear interseccion." << endl
		<< "3 - Ver la ruta mas corto." << endl
		<< "4 - Salir." << endl;

	cin >> opcion;

	switch(opcion){
	case AGREGAR_CALLE:
		agregarCalle();
		break;
	case CREAR_INTERSECCION:
		crearInterseccion();
		break;
	case RUTA_MAS_CORTO:
		verRutaMasCorta();
		break;
	default:
		return EXIT_SUCCESS;
	}
}

void agregarCalle(){
	char continuar;
	vector<Calle> calles;
	int indiceCalle = 1;
	string nombre;

	if(_access(Archivo::CALLE,0)  == 0){
		mapaTransito.inicializar();
		indiceCalle = mapaTransito.getCalles().size() + 1;
	}
	
	system("CLS");
	cout << "-- Agregando calle --" << endl
			<< "---------------------" << endl 
			<< endl;

	do{
		cout << "Ingrese el nombre de una calle" << endl;
		cin >> nombre;

		cout << endl 
			 << "Desea continuar ingresando calles? [S=>Si|N=>No]";
		cin >> continuar;

		calles.push_back(Calle(indiceCalle,nombre));
		indiceCalle++;	

	}while(continuar == 'S' || continuar == 's');
			
	mapaTransito.grabarCalles(calles);
	
	system("PAUSE");
	menuPrincipal();
}

void crearInterseccion(){
	char continuar;
	vector<Interseccion> intersecciones;
	string nombreCalleOrigen;
	string nombreCalleDestino;
	int tiempo;

	system("CLS");
	cout << "-- Creando intersecciones --" << endl
			<< "----------------------------" << endl 
			<< endl;

	cargarCallesMapaTransito(&mapaTransito);

	do{
		cout << "Ingrese el nombre de la calle origen" << endl;
		cin >> nombreCalleOrigen;

		cout << "Ingrese el nombre de la calle de destino" << endl;
		cin >> nombreCalleDestino;

		cout << "Ingrese el tiempo que se toma desde el origen al destino" << endl;
		cin >> tiempo;

		cout << "Desea continuar creando intersecciones? [S=>Si|N=>No]";
		cin >> continuar;
				
		vector<Calle> calles = mapaTransito.getCalles();

		Calle origen = mapaTransito.obtenerVerticePorNombre(nombreCalleOrigen);
		Calle destino = mapaTransito.obtenerVerticePorNombre(nombreCalleDestino);

		intersecciones.push_back(Interseccion(origen,destino,tiempo));

	}while(continuar == 'S' || continuar == 's');

	mapaTransito.grabarIntersecciones(intersecciones);
	
	system("PAUSE");
	menuPrincipal();
}

void verRutaMasCorta(){
	string origen;
	string destino;
	int hora;

	bool archivoCalleExiste = false;
	bool archivoInterseccionExiste = false;

	if(_access(Archivo::CALLE,0)  == 0)
		archivoCalleExiste = true;

	if(_access(Archivo::INTERSECCION,0) == 0)
		archivoInterseccionExiste = true;

	system("CLS");
	if(!archivoCalleExiste){
		cout << "Aun no existe suficiente informacion para generar la ruta mas corta!!!" << endl << endl;
		system("PAUSE");
		agregarCalle();
	}

	if(!archivoInterseccionExiste){
		cout << "Aun no existe suficiente informacion para generar la ruta mas corta!!!" << endl << endl;
		system("PAUSE");
		crearInterseccion();
	}

	cout << "-- Ruta mas corto --" << endl
			<< "----------------------" << endl 
			<< endl;

	cargarCallesMapaTransito(&mapaTransito);

	cout << "Ingrese la calle de origen" << endl;
	cin >> origen;

	cout << "Ingrese la calle de destino" << endl;
	cin >> destino;

	cout << "Ingrese la hora en que se traslada del origen al destino" << endl;
	cin >> hora;

	system("CLS");
	mapaTransito.caminoMasCorto(origen,destino,hora);

	system("PAUSE");
	menuPrincipal();
}

void cargarCallesMapaTransito(MapaTransito* mapaTransito){
	mapaTransito->inicializar();
	vector<Calle> calles = mapaTransito->getCalles();
	vector<Interseccion> intersecciones = mapaTransito->getIntersecciones();

	cout << "Calles cargadas en el mapa de transito:" << endl;

	for(unsigned i = 0; i < calles.size(); i++){
		cout << "*- " << calles.at(i).getNombre();
		
		for(unsigned x = 0; x < intersecciones.size(); x++){
			if(intersecciones.at(x).getOrigen().getId() == calles.at(i).getId())
				cout << " > " << intersecciones.at(x).getDestino().getNombre();
		}

		cout << endl;
	}

	cout << "-----------------------------------------------------------------------" << endl
		 << "Nota: ingrese el nombre de la calle tal cual como lo ve en la pantalla." << endl
		 << "Los simbolos '>' indican las intersecciones." << endl
		 << endl;
}
