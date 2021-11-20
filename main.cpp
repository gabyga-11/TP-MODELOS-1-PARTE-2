#include <iostream>
#include <vector>
#include "Carga.h"
#include "Ordenador.h"
#include "Ropa.h"
#include "Escritura.h"

int main() {
    Carga* carga = new Carga();

    Ordenador* ordenador = new Ordenador(carga->getGrafo(),carga->getCantPrendas(),carga->getCantIncompat());

    Ropa* lavados = new Ropa(ordenador->getGrafo(),ordenador->getOrdenGrafo(),carga->getCantPrendas(),carga->getCantIncompat());

    Escritura* escritura = new Escritura(lavados->getGrafo(),carga->getCantPrendas());


    delete escritura;
    delete lavados;
    delete ordenador;
    delete carga;

    return 0;
}
