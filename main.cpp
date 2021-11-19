#include <iostream>
#include "Carga.h"
#include "Ordenador.h"

int main() {
    Carga* carga = new Carga();

    Ordenador* ordenador = new Ordenador(carga->getGrafo(),carga->getCantPrendas(),carga->getCantIncompat());

    

    delete ordenador;
    delete carga;
    return 0;
}
