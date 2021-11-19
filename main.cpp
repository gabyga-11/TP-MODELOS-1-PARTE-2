#include <iostream>
#include "Carga.h"
#include "Ordenador.h"

int main() {
    Carga* carga = new Carga();

    Ordenador ordenador = Ordenador(carga->getGrafo(),carga->getCantPrendas(),carga->getCantIncompat());

    delete carga;
    return 0;
}
