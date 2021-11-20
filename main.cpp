#include <iostream>
#include <vector>
#include "Carga.h"
#include "Ordenador.h"
#include "Ropa.h"

int main() {
    Carga* carga = new Carga();

    Ordenador* ordenador = new Ordenador(carga->getGrafo(),carga->getCantPrendas(),carga->getCantIncompat());

    Ropa* lavados = new Ropa(ordenador->getGrafo(),ordenador->getOrdenGrafo(),carga->getCantPrendas(),carga->getCantIncompat());



    delete lavados;
    delete ordenador;
    delete carga;
    return 0;
}
