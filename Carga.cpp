
#include "Carga.h"
#include <sstream>
using namespace std;

Carga::Carga() {
    archivo.open("../datos.txt", ios::in);
    if (!archivo) {
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO"<< endl;
        archivo.close();
    } else {
        procesar();
    }
}

void Carga::procesar() {
    string linea = procesarPrimerasLineas();
    crearMatrizPrendas(linea);
    //eliminarConexionesIncompatibles(); //En base a lo que lee quita los linkeos
}

string Carga::procesarPrimerasLineas() {
    string linea;
    getline(archivo, linea);
    while (linea[0] == 'c'){
        getline(archivo, linea);
    }
    cout << linea;
    return linea;
}

string Carga::leerLinea() {
    string linea;
    getline(archivo, linea);
    return linea;
}

void Carga::obtenerCantPrendas(string primerLinea){
    string input;
    istringstream primeraLinea(primerLinea);
    primeraLinea >> input;
    primeraLinea >> input;
    primeraLinea >> input;
    primeraLinea >> input;
    cantPrendas = stoi(input);
    primeraLinea >> input;
    cantIncompat = stoi(input);
}

void Carga::crearMatrizPrendas(string linea) {
    string input;
    obtenerCantPrendas(linea);
    grafo = new Prenda* [cantPrendas]; //grafo[1] sera la prenda 2
    grafo[0] = new Prenda; // Lo agrego para evitar que me conexione consigo mismo el primer elemento
    for (int i=1; i < cantPrendas ; i++){
        grafo[i] = new Prenda;
        conexionarGrafo(i); //Agregar los linkeos con todos los puntos de la red
    }
}

void Carga::conexionarGrafo(int indiceUltimoElemento) {
    for (int j = 0; j < indiceUltimoElemento-1 ; j++){
        grafo[indiceUltimoElemento]->conexionar(grafo[j]);
        grafo[j]->conexionar(grafo[indiceUltimoElemento]);
    }
}

Carga::~Carga() {
    archivo.close();
    delete grafo; //TODO SACAR DE ACA
}