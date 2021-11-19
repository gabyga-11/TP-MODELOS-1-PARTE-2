//
// Created by gaby on 16/11/21.
//

#ifndef TP_MODELOS_1_PARTE_2_CARGA_H
#define TP_MODELOS_1_PARTE_2_CARGA_H
#include <iostream>
#include <fstream>
#include "Prenda.h"
using namespace std;

class Carga {
private:
    ifstream archivo;
    Prenda** grafo;
    int cantIncompat;
    int cantPrendas;
public:
    Carga();

    string procesarPrimerasLineas();

    void procesar();

    string leerLinea();

    void obtenerCantPrendas(string primerLinea);

    void crearMatrizPrendas(string linea);

    void conexionarGrafo(int indiceUltimoElemento);

    void eliminarConexionesIncompatibles();

    void leerIncompatibilidades(int &prenda1, int &prenda2);

    void agregarTiempoLavados();

    void leerTiempo(int &prenda, int &tiempoLavado);

    Prenda** getGrafo();

    int getCantPrendas();

    int getCantIncompat();

    ~Carga();
};


#endif //TP_MODELOS_1_PARTE_2_CARGA_H
