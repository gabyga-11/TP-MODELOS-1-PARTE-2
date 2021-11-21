#include "Ordenador.h"

Ordenador::Ordenador(Prenda** grafo, int cantPrendas, int cantIncompat) {
    this->grafo = grafo;
    this->cantPrendas = cantPrendas;
    for (int i = 0 ; i < cantPrendas ; i++){
        this->vectorPrimerPrenda.push_back(grafo[i]->getNroPrenda()); //Agrega al final de la lista
    }
    procesar();
}

void Ordenador::procesar() {
    ordenarPrimerPrendaLavado();
    ordenarCadaPrendaPorCompatibilidades();
}

void Ordenador::ordenarPrimerPrendaLavado() { //BubbleSort DE MENOR A MAYOR EN COMPATIBILIDADES
    bool intercambio = true;
    int aux,j=0;
    while (intercambio && j < cantPrendas){
        intercambio = false;
        j = 0;
        for (int i=1 ; i<cantPrendas-j ; i++){
            if (grafo[((vectorPrimerPrenda[i - 1]) - 1)]->getCantCompatib() > grafo[((vectorPrimerPrenda[i]) - 1)]->getCantCompatib() ){
                aux = vectorPrimerPrenda[i - 1];
                vectorPrimerPrenda[i - 1] = vectorPrimerPrenda[i];
                vectorPrimerPrenda[i] = aux;
                intercambio = true;
            }
        }
        j++;
    }
}
void Ordenador::ordenarCadaPrendaPorCompatibilidades() { //Se ordena el vector con las compatibilidades de mayor a menor
    for (int i = 0 ; i < cantPrendas ; i++){
        grafo[i]->ordenarCompatibilidades();
    }
}

Prenda ** Ordenador::getGrafo() {
    return grafo;
}
vector<int> Ordenador::getOrdenGrafo() {
    return this->vectorPrimerPrenda;
}

Ordenador::~Ordenador() {
    grafo = nullptr;
}