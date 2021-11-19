#include "Prenda.h"
Prenda::Prenda(int nroPrenda) {
    this->nroPrenda = nroPrenda;
    tiempoLavado = 0;
    cantCompatib = 0;
    compatib = nullptr;
    nroLavado = 0;
}

void Prenda::conexionar(Prenda *compatible) {
    if (!compatib){
        compatib = new Prenda* [1];
        cantCompatib++;
        compatib[0] = compatible;
        //cout << "compatib[" << 0 << "] = " << compatib[0]->getNroPrenda() << endl;
    } else {
        Prenda** nuevoCompatib = new Prenda* [cantCompatib+1];
        for (int i = 0 ; i < cantCompatib ; i++){
            nuevoCompatib[i] = compatib[i];
        }
        nuevoCompatib[cantCompatib] = compatible;
        cantCompatib++;
        delete [] compatib;
        compatib = nuevoCompatib;
        /*
        for (int i = 0 ; i < cantCompatib ; i++){
            cout << "compatib[" << i << "] = " << compatib[i]->getNroPrenda() << endl;
        }
         */
    }
}

void Prenda::eliminarConexion(Prenda *incompatible) {
    Prenda** nuevoCompatib = new Prenda* [cantCompatib-1];
    int prendaAEliminar = incompatible->getNroPrenda();
    int j = 0;
    for (int i = 0 ; i < cantCompatib ; i++){
        //cout << i << " distinto de " << incompatible->getNroPrenda() <<"? " << (i != incompatible->getNroPrenda()) << endl;
        if (compatib[i]->getNroPrenda() != prendaAEliminar) {
            nuevoCompatib[j] = compatib[i];
            j++;
        }
    }
    cantCompatib--;
    delete [] compatib;
    compatib = nuevoCompatib;
    //cout << endl;
    /*
    if (nroPrenda == 4) {
        cout << endl << 4 << " " << prendaAEliminar << endl;
    }
    for (int i = 0 ; i < cantCompatib ; i++){
        //cout << "compatib [" << i << "] = " << compatib[i]->getNroPrenda() << endl;

        if (nroPrenda == 4) {
            cout << "compatib [" << i << "] = " << compatib[i]->getNroPrenda() << endl;
        }
    }
     */

}

void Prenda::ordenarCompatibilidades() {
    bool intercambio = true;
    int j=0;
    Prenda* aux;
    while (intercambio && j < cantCompatib){
        intercambio = false;
        j = 0;
        for (int i=1 ; i<cantCompatib-j ; i++){
            if (compatib[i-1]->cantCompatib < compatib[i]->cantCompatib ){
                aux = compatib[i-1];
                compatib[i-1] = compatib[i];
                compatib[i] = aux;
                intercambio = true;
            }
        }
        j++;
    }
    /*
    cout << endl << "PRENDA NRO " << nroPrenda << endl;
    for (int j = 0 ; j < cantCompatib ; j++){
        cout << "compatib[" << j << "] => PRENDA " << compatib[j]->getNroPrenda() << " con compatibilidades quantity " << compatib[j]->getCantCompatib() << endl;
    }
    cout << "CANTIDAD DE COMPATIBILIDADES: " <<cantCompatib << endl;
     */ //TODO: Queda bien ordenado cada vector de punteros!!!!!!!!1
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

int Prenda::getLavado() {
    return this->tiempoLavado;
}

Prenda::~Prenda() {
    for (int i = 0 ; i < cantCompatib; i++){
        compatib[i] = nullptr;
    }
    delete [] compatib;
}