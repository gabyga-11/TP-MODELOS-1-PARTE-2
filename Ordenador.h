#ifndef TP_MODELOS_1_PARTE_2_ORDENADOR_H
#define TP_MODELOS_1_PARTE_2_ORDENADOR_H
#include "Prenda.h"
#include <vector>
class Ordenador {
private:
    Prenda** grafo;
    int cantPrendas;
    vector<int> vectorPrimerLavado;

public:
    Ordenador(Prenda** grafo, int cantPrendas, int cantIncompat);

    void procesar();

    void ordenarPrimerLavado(); //Ordena de mayor a menor los grafos por tiempos

    void ordenarCadaPrendaPorCompatibilidades();

    Prenda** getGrafo();

    vector<int> getOrdenGrafo();

    ~Ordenador();
};


#endif //TP_MODELOS_1_PARTE_2_ORDENADOR_H
