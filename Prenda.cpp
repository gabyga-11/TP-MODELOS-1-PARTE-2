#include "Prenda.h"
Prenda::Prenda(int nroPrenda) {
    this->nroPrenda = nroPrenda;
    tiempoLavado = 0;
    cantCompatib = 0;
    compatib = nullptr;
    nroLavado = 0;
    tiempoLavadoTotal = 0;
}

void Prenda::conexionar(Prenda *compatible) {
    if (!compatib){
        compatib = new Prenda* [1];
        cantCompatib++;
        compatib[0] = compatible;
    } else {
        Prenda** nuevoCompatib = new Prenda* [cantCompatib+1];
        for (int i = 0 ; i < cantCompatib ; i++){
            nuevoCompatib[i] = compatib[i];
        }
        nuevoCompatib[cantCompatib] = compatible;
        cantCompatib++;
        delete [] compatib;
        compatib = nuevoCompatib;
    }
}

void Prenda::eliminarConexion(Prenda *incompatible) {
    Prenda** nuevoCompatib = new Prenda* [cantCompatib-1];
    int prendaAEliminar = incompatible->getNroPrenda();
    int j = 0;
    for (int i = 0 ; i < cantCompatib ; i++){
        if (compatib[i]->getNroPrenda() != prendaAEliminar) {
            nuevoCompatib[j] = compatib[i];
            j++;
        }
    }
    cantCompatib--;
    delete [] compatib;
    compatib = nuevoCompatib;
}

void Prenda::ordenarCompatibilidades() {
    bool intercambio = true;
    int j=0;
    Prenda* aux;
    double ponderado1,ponderado2;
    double coefCompatib = 0.8;
    double coefTiempos = 0.2;
    while (intercambio && j < cantCompatib){
        intercambio = false;
        j = 0;
        for (int i=1 ; i<cantCompatib-j ; i++){
            ponderado1 = ((compatib[i-1]->cantCompatib) * coefCompatib ) +  ((compatib[i-1]->tiempoLavado) * coefTiempos ) ;
            ponderado2 = ((compatib[i]->cantCompatib) * coefCompatib ) + ((compatib[i]->tiempoLavado) * coefTiempos ) ;
            if (ponderado1 > ponderado2){
                aux = compatib[i-1];
                compatib[i-1] = compatib[i];
                compatib[i] = aux;
                intercambio = true;
            }
        }
        j++;
    }
}

int Prenda::getNroPrenda() {
    return nroPrenda;
}

void Prenda::setTiempoLavado(int tiempoLavado) {
    this->tiempoLavado = tiempoLavado;
}

int Prenda::getCantCompatib() {
    return cantCompatib;
}

int Prenda::getTiempoLavado() {
    return this->tiempoLavado;
}

Prenda ** Prenda::getVectorCompatib() {
    return this->compatib;
}

bool Prenda::esCompatibleCon(Prenda *prendaPosibleParaAgregar) {
    bool sePuedeAgregar = false;
    int i = 0;
    while (!sePuedeAgregar && i < cantCompatib){
        if (compatib[i]->getNroPrenda() == prendaPosibleParaAgregar->getNroPrenda() ){
            sePuedeAgregar = true;
        } else {
            i++;
        }
    }
    return sePuedeAgregar;
}

void Prenda::setTiempoTotalLavado(int tiempoLavadoTotal) {
    this->tiempoLavadoTotal = tiempoLavadoTotal;
}

void Prenda::setNroLavado(int nroLavado) {
    this->nroLavado = nroLavado;
}

int Prenda::getNroLavado() {
    return nroLavado;
}

Prenda::~Prenda() {
    for (int i = 0 ; i < cantCompatib; i++){
        compatib[i] = nullptr;
    }
    delete [] compatib;
}