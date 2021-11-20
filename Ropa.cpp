#include "Ropa.h"

Ropa::Ropa(Prenda **grafo, vector<int> grafoOrdenadoTiempos, int cantPrendas, int cantIncompatib) {
    this->grafo = grafo;
    this->grafoOrdenadoTiempos = grafoOrdenadoTiempos;
    this->cantPrendas = cantPrendas;
    this->cantIncompatib = cantIncompatib;
    visitados = new bool [cantPrendas];
    for (int i=1; i < cantPrendas ; i++){
        visitados[i] = false;
    }
    /*
    for (int i = 0; i<cantPrendas ; i++){
        cout << grafo[(grafoOrdenadoTiempos[i]-1)]->getNroPrenda() << " ";
    }*/
    procesar();
}

void Ropa::procesar() {
    int  nroPrendaActual, nroLavado = 0;
    while (!seVisitaronTodasLasPrendas()){
        nroLavado++;
        nroPrendaActual = buscarPrendaARevisar();
        vectorPrendasEnLavado.push_back(nroPrendaActual);
        busquedaPrendasEnLavado();




        //Ahora que tengo la prenda a revisar, la agarro y la agrego al lavado 1 [nroLavado, una variable],
        // con su tiempo como tiempoLavadoTotal
        //Guardo la prenda en un vector dinamico vectorPrendasEnLavado
        //Me fijo en su vector de punteros de la prenda recien agregada para ESTABLECES PROXIMA PRENDA
        //Sumo al lavado a la prenda no visitada de 0 a n (osea con mas compatibilidades)
        //Que A SU VEZ DEBERA SER COMPATIBLE CON TODAS LAS PRENDAS PREVIAS A LA ULTIMA AGREGADA
        //Para eso, reviso en el vector compatibilidades de la posible prenda nueva
        //Y verifico que esten todas las prendas del vector vectorPrendasEnLavado

        //SI ENCUENTRO UNA prenda q cumple, la sumo al vectorPrendasEnLavado;
        // y veo si su tiempo es el nuevo tiempoLavadoTotal

        //SI NO ENCUENTRO UNA PRENDA en la ultima prenda agregada, que cumpla las condiciones dichas,
        //Se da por terminado el lavado, lo que significa que
        //Debere recorrer el vectorPrendasEnLavado para agregar como atributos a cada una de dichas prendas
        //El nroLavado, que quedo fijo en esta iteracion
        //El tiempoLavado, que se fue actualizando cada vez que se agregaba una prenda al lavado
        vectorPrendasEnLavado.clear();
    }
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
    bool visitadoAlguno = false;
    int i = 0;
    while (!visitadoAlguno && i < cantPrendas){
        if (visitados[i]){
            visitadoAlguno = true;
        } else {
            i++;
        }
    }
    return (!visitadoAlguno);
}



Ropa::~Ropa() {
    for (int i=1; i < cantPrendas ; i++){
        delete grafo[i];
    }
    delete [] visitados;
    delete grafo;
}


