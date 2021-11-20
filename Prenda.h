#ifndef TP_MODELOS_1_PARTE_2_PRENDA_H
#define TP_MODELOS_1_PARTE_2_PRENDA_H
using namespace std;
#include <iostream>

class Prenda {
private:
    int nroPrenda;
    Prenda** compatib; //Un vector de punteross //TODO: REVISAR
    int cantCompatib; //Cantidad de compatibilidades de la prenda
    int tiempoLavado;
    int nroLavado;
    int tiempoLavadoTotal;
public:
    Prenda(int nroPrenda);

    void agregarCompatibilidad(int prendaCompatible); //TODO: REVISAR

    void conexionar(Prenda* compatible); //Se agrega en el vector de prendas

    void eliminarConexion(Prenda* incompatible);

    void ordenarCompatibilidades();

    int getNroPrenda();

    void setNroPrenda();

    void setTiempoLavado(int tiempoLavado);

    int getCantCompatib();

    int getTiempoLavado();

    Prenda** getVectorCompatib();

    bool esCompatibleCon(Prenda* prendaPosibleParaAgregar);

    void setTiempoTotalLavado(int tiempoLavadoTotal);

    void setNroLavado(int nroLavado);

    int getNroLavado();

    ~Prenda();
};


#endif //TP_MODELOS_1_PARTE_2_PRENDA_H
