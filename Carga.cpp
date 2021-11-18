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
    eliminarConexionesIncompatibles(); //En base a lo que lee quita los linkeos
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
    cantPrendas = stoi(input);
    primeraLinea >> input;
    cantIncompat = stoi(input);
}

void Carga::crearMatrizPrendas(string linea) {
    string input;
    obtenerCantPrendas(linea);
    grafo = new Prenda* [cantPrendas]; //grafo[1] sera la prenda 2
    grafo[0] = new Prenda(1); // Lo agrego para evitar que me conexione consigo mismo el primer elemento
    //cout << "Agrego prenda 1" << endl;
    for (int i=1; i < cantPrendas ; i++){
        grafo[i] = new Prenda(i+1);
        conexionarGrafo(i); //Agregar los linkeos con todos los puntos de la red
        //cout << "Agrego prenda "<< i+1 << endl;
    }
}

void Carga::conexionarGrafo(int indiceUltimoElemento) {
    for (int j = 0; j < indiceUltimoElemento ; j++) {
        //cout << "grafo[" << indiceUltimoElemento << "]->conexionar(grafo[" << j << "])" << endl;
        grafo[indiceUltimoElemento]->conexionar(grafo[j]);
        //cout << "grafo[" << j << "]->conexionar(grafo[" << indiceUltimoElemento << "])" << endl;
        grafo[j]->conexionar(grafo[indiceUltimoElemento]);
        //TODO: Conexionado desde carga OK
    }
    //cin.ignore();
}

void Carga::eliminarConexionesIncompatibles() {
    int prenda1, prenda2;
    for (int i = 0 ; i < cantIncompat ; i++) {
        devolverIncompatibilidades(prenda1,prenda2);
        //cout << "grafo[" << prenda1-1 << "]->eliminarConexion(grafo[" << prenda2-1 << "])";
        //TODO: Se llaman a todas las eliminaciones correspondientes
        grafo[prenda1-1]->eliminarConexion(grafo[prenda2-1]);
    }
}

void Carga::devolverIncompatibilidades(int &prenda1, int &prenda2) {
    string linea,input;
    getline(archivo, linea);
    istringstream lineaIncompatibilidades(linea);
    lineaIncompatibilidades >> input;
    lineaIncompatibilidades >> input;
    prenda1 = stoi(input);
    lineaIncompatibilidades >> input;
    prenda2 = stoi(input);
    //cout << prenda1 << " " << prenda2; //SE PROCESA CORRECTAMENTE. Estan procesados todos!
}

Carga::~Carga() {
    archivo.close();
    for (int i=1; i < cantPrendas ; i++){
        delete grafo[i];
    }
    delete grafo; //TODO SACAR DE ACA
}