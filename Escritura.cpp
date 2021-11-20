#include "Escritura.h"

using namespace std;

Escritura::Escritura(Prenda** grafo, int cantPrendas) {
    archivo.open("../solucion.txt", ios::out);
    if (!archivo) {
        cout << "ERROR: NO SE PUDO ABRIR EL ARCHIVO"<< endl;
        archivo.close();
    } else {
        this->grafo = grafo;
        this->cantPrendas = cantPrendas;
        procesar();
    }
}

void Escritura::procesar() {
    string linea;
    for (int i = 0 ; i < cantPrendas ; i++){
        linea = to_string(grafo[i]->getNroPrenda());
        linea += " ";
        linea += to_string(grafo[i]->getNroLavado());
        if (i != cantPrendas-1){
            linea += "\n";
        }
        archivo << linea;
    }

}

Escritura::~Escritura() {
    archivo.close();

    for (int i=1; i < cantPrendas ; i++){
        delete grafo[i];
    }
    delete grafo;
}
