#include "Ordenador.h"

Ordenador::Ordenador(Prenda** grafo, int cantPrendas, int cantIncompat) {
    this->grafo = grafo;
    this->cantPrendas = cantPrendas;
    for (int i = 0 ; i < cantPrendas ; i++){
        this->grafoOrdTiempos.push_back(grafo[i]->getNroPrenda()); //Agrega al final de la lista
    }
    /*
    for (int i = cantPrendas-1 ; i >= 0 ; i--){
        this->grafoOrdTiempos.push_back(grafo[i]->getNroPrenda()); //Agrega al final de la lista
    }
     */
    /*
    for (int i = 0 ; i < cantPrendas ; i++){
        cout << grafoOrdTiempos[i] << endl;
    }*/
    procesar();
}

void Ordenador::procesar() {
    ordenarGrafoPorTiempos();
    /*
    for (int i = 0 ; i < cantPrendas ; i++){
        cout << grafoOrdTiempos[i] << endl;
    }//TODO: Quedo bien ordenado!
     */
    ordenarCadaPrendaPorCompatibilidades();
}

void Ordenador::ordenarGrafoPorTiempos() { //BubbleSort DE MAYOR A MENOR TIEMPO
    bool intercambio = true;
    int aux,j=0;
    while (intercambio && j < cantPrendas){
        intercambio = false;
        j = 0;
        for (int i=1 ; i<cantPrendas-j ; i++){
            if (grafo[((grafoOrdTiempos[i - 1]) - 1)]->getTiempoLavado() < grafo[((grafoOrdTiempos[i]) - 1)]->getTiempoLavado() ){
                aux = grafoOrdTiempos[i-1];
                grafoOrdTiempos[i-1] = grafoOrdTiempos[i];
                grafoOrdTiempos[i] = aux;
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
    return this->grafoOrdTiempos;
}

Ordenador::~Ordenador() {
    grafo = nullptr;
}