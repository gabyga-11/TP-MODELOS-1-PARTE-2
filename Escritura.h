

#ifndef TP_MODELOS_1_PARTE_2_ESCRITURA_H
#define TP_MODELOS_1_PARTE_2_ESCRITURA_H
#include "Prenda.h"
#include <iostream>
#include <fstream>
class Escritura {
private:
    ofstream archivo;
    Prenda** grafo;
    int cantPrendas;
public:
    Escritura(Prenda** grafo , int cantPrendas);

    void procesar();

    ~Escritura();
};


#endif //TP_MODELOS_1_PARTE_2_ESCRITURA_H
