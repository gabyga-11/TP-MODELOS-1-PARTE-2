
#ifndef TP_MODELOS_1_PARTE_2_ROPA_H
#define TP_MODELOS_1_PARTE_2_ROPA_H
#include "Prenda.h"
#include <vector>
class Ropa {
private:
    Prenda** grafo;
    vector<int> grafoOrdenadoTiempos;
    int cantPrendas,cantIncompatib,nroPrendaActual;
    bool* visitados;
    int tiempoTotalPorLavado; //Esta variable cambia su valor to-do el tiempo, en ejecucion
    int  nroLavado;
    vector<int> vectorPrendasEnLavado;
    int cantPrendasEnLavado;
    int tiempoAcum;

public:
    Ropa(Prenda** grafo,vector<int> grafoOrdenadoTiempos,int cantPrendas,int cantIncompatib);

    void procesar();

    void realizarUnLavado();

    int buscarPrendaARevisar(); //PARTE QUE BUSCA LA PRENDA PARA REVISAR: Si no se visito y es la mas grande en vector

    bool seVisitaronTodasLasPrendas();

    bool compatibleConLasOtrasPrendasDelLavado(Prenda* prendaPosibleParaAgregar);

    void terminarLavado();

    void presentarResultadoFinal();

    Prenda** getGrafo();

    ~Ropa();
};


#endif //TP_MODELOS_1_PARTE_2_ROPA_H
