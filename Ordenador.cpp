#include "Ordenador.h"

Ordenador::Ordenador(Prenda** grafo, int cantPrendas, int cantIncompat) {
    this->grafo = grafo;
    this->cantPrendas = cantPrendas;
    for (int i = 0 ; i < cantPrendas ; i++){
        this->grafoOrdTiempos.push_back(grafo[i]->getNroPrenda()); //Agrega al final de la lista
    }
    procesar();
}

void Ordenador::procesar() {
    ordenarGrafoPorTiempos();
    ordenarCadaPrendaPorCompatibilidades();
}

void Ordenador::ordenarGrafoPorTiempos() { //BubbleSort DE MAYOR A MENOR TIEMPO
    bool intercambio = true;
    int aux,j=0;
    double ponderado1,ponderado2;
    double coefCompatib = 0.8;
    double coefTiempos = 0.2;
    while (intercambio && j < cantPrendas){
        intercambio = false;
        j = 0;
        for (int i=1 ; i<cantPrendas-j ; i++){
            ponderado1 = grafo[((grafoOrdTiempos[i - 1]) - 1)]->getCantCompatib() * coefCompatib +
                    grafo[((grafoOrdTiempos[i - 1]) - 1)]->getTiempoLavado() * coefTiempos ;
            ponderado2 = grafo[((grafoOrdTiempos[i]) - 1)]->getCantCompatib() * coefCompatib +
                        grafo[((grafoOrdTiempos[i]) - 1)]->getTiempoLavado() * coefTiempos ;

            if (ponderado1 > ponderado2 ){
                aux = grafoOrdTiempos[i-1];
                grafoOrdTiempos[i-1] = grafoOrdTiempos[i];
                grafoOrdTiempos[i] = aux;
                intercambio = true;
            }
        }
        j++;
    }
}
void Ordenador::ordenarCadaPrendaPorCompatibilidades() { //Se ordena el vector con las compatibilidades de menor a mayor
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