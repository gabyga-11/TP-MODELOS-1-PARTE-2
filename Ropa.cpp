#include "Ropa.h"

Ropa::Ropa(Prenda **grafo, vector<int> grafoOrdenadoTiempos, int cantPrendas, int cantIncompatib) {
    this->grafo = grafo;
    this->grafoOrdenadoTiempos = grafoOrdenadoTiempos;
    this->cantPrendas = cantPrendas;
    this->cantIncompatib = cantIncompatib;
    this->tiempoTotalPorLavado = 0;
    this->cantPrendasEnLavado = 0;
    this->nroLavado = 0;
    this->tiempoAcum = 0;
    visitados = new bool [cantPrendas];
    for (int i=1; i < cantPrendas ; i++){
        visitados[i] = false;
    }
    procesar();
    presentarResultadoFinal();
}

void Ropa::procesar() {
    while (!seVisitaronTodasLasPrendas()){ //TODOS LOS LAVADOS
        nroLavado++;
        nroPrendaActual = buscarPrendaARevisar();
        vectorPrendasEnLavado.push_back(nroPrendaActual);
        cantPrendasEnLavado++;
        visitados[nroPrendaActual-1] = true;
        tiempoTotalPorLavado = grafo[nroPrendaActual - 1]->getTiempoLavado();
        realizarUnLavado();

        tiempoAcum += tiempoTotalPorLavado;
    }
}

void Ropa::realizarUnLavado() {
    bool terminoLavado = false, seConsiguioUnaPrendaNueva;
    int i, cantCompatib;
    Prenda** compatibilidades;
    while (!terminoLavado){ //Ciclo de un lavado
        seConsiguioUnaPrendaNueva = false;
        compatibilidades = grafo[nroPrendaActual-1]->getVectorCompatib();
        cantCompatib = grafo[nroPrendaActual-1]->getCantCompatib();

        i = 0;
        while (i < cantCompatib && !seConsiguioUnaPrendaNueva){ //Ciclo de una prenda en el lavado

            //Si no se visito la prenda y es compatible con todas las otras prendas del lavado
            if (!(visitados[compatibilidades[i]->getNroPrenda()-1]) &&
            compatibleConLasOtrasPrendasDelLavado(compatibilidades[i]) ){

                seConsiguioUnaPrendaNueva = true;

                //Se agrega la prenda al lavado
                this->vectorPrendasEnLavado.push_back(compatibilidades[i]->getNroPrenda());
                cantPrendasEnLavado++;

                //Actualizacion de duracion del lavado
                if (compatibilidades[i]->getTiempoLavado() > tiempoTotalPorLavado){
                    tiempoTotalPorLavado = compatibilidades[i]->getTiempoLavado();
                }

                //Se agrega dicha prenda en el vector de visitados
                visitados[compatibilidades[i]->getNroPrenda()-1] = true;

                //ActualizarNroPrenda
                nroPrendaActual = compatibilidades[i]->getNroPrenda();
            }
            i++;
            if (i == cantCompatib) {
                terminoLavado = true;
            }
        }
    }
    terminarLavado();

}




int Ropa::buscarPrendaARevisar() {
    int indiceGrafoOrdenadoTiempos = 0, nroPrendaActual = -1;
    bool encontrado = false;
    while (!encontrado) {
        nroPrendaActual = this->grafoOrdenadoTiempos[indiceGrafoOrdenadoTiempos];
        if (! visitados[nroPrendaActual - 1]) {
            encontrado = true;
        } else {
            indiceGrafoOrdenadoTiempos++;
        }

    }
    return nroPrendaActual;
}

bool Ropa::seVisitaronTodasLasPrendas() {
    bool unoNoVisitado = false;
    bool visitadosTodos = false;
    int i = 0;
    while (!unoNoVisitado && i < cantPrendas){
        if (! visitados[i]){
            unoNoVisitado = true;
        } else {
            i++;
            if (i == cantPrendas){
                visitadosTodos = true;
            }
        }
    }
    return (visitadosTodos);
}

bool Ropa::compatibleConLasOtrasPrendasDelLavado(Prenda* prendaPosibleParaAgregar) {
    bool esCompatible = true; //variable bandera
    int i = 0;
    while (esCompatible && i < cantPrendasEnLavado){
        if (! grafo[vectorPrendasEnLavado[i]-1]->esCompatibleCon(prendaPosibleParaAgregar)){
            esCompatible = false;
        } else {
            i++;
            if (i == cantPrendasEnLavado){
                esCompatible = true;
            }
        }
    }
    return esCompatible;
}

void Ropa::terminarLavado() {
    for (int i = 0 ; i < cantPrendasEnLavado ; i++){
        grafo[vectorPrendasEnLavado[i]-1]->setTiempoTotalLavado(tiempoTotalPorLavado);
        grafo[vectorPrendasEnLavado[i]-1]->setNroLavado(nroLavado);
    }
    cantPrendasEnLavado = 0;
    vectorPrendasEnLavado.clear();
}

void Ropa::presentarResultadoFinal() {
    cout << "El tiempo total fue de " << tiempoAcum << " minutos." << endl;
    cout << "Realizandose un total de " << nroLavado << " lavados." << endl;
}

Prenda ** Ropa::getGrafo() {
    return grafo;
}


Ropa::~Ropa() {
    delete [] visitados;
    grafo = nullptr;
    vectorPrendasEnLavado.clear();
}


