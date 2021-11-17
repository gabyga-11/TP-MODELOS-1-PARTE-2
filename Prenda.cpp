#include "Prenda.h"
Prenda::Prenda() {
    nroPrenda;
    tiempoLavado = 0;
    cantCompatib = 0;
    compatib = nullptr;
    compatib = new Prenda*;
}

void Prenda::conexionar(Prenda *compatible) {
    if (!compatib){
        compatib = new Prenda* [1];
        cantCompatib++;
        compatib[0] = compatible;
    } else {
        //Toodo el tema de la reasignacion de vectores al agregar elementos
    }
}
