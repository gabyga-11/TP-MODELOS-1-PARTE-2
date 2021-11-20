
#ifndef TP_MODELOS_1_PARTE_2_ROPA_H
#define TP_MODELOS_1_PARTE_2_ROPA_H
#include "Prenda.h"
#include <vector>
class Ropa {
private:
    Prenda** grafo;
    vector<int> grafoOrdenadoTiempos;
    int cantPrendas,cantIncompatib;
    bool* visitados;
    int tiempoLavadoTotal; //Esta variable cambia su valor to-do el tiempo, en ejecucion
public:
    Ropa(Prenda** grafo,vector<int> grafoOrdenadoTiempos,int cantPrendas,int cantIncompatib);

    void procesar();

    int buscarPrendaARevisar(); //PARTE QUE BUSCA LA PRENDA PARA REVISAR: Si no se visito y es la mas grande en vector

    bool seVisitaronTodasLasPrendas();

    ~Ropa();
};


#endif //TP_MODELOS_1_PARTE_2_ROPA_H
