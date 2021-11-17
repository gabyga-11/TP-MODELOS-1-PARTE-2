#ifndef TP_MODELOS_1_PARTE_2_PRENDA_H
#define TP_MODELOS_1_PARTE_2_PRENDA_H


class Prenda {
private:
    int nroPrenda;
    Prenda** compatib; //Un vector de punteross //TODO: REVISAR
    int cantCompatib; //Cantidad de compatibilidades de la prenda
    int tiempoLavado;

public:
    Prenda();

    void agregarCompatibilidad(int prendaCompatible); //TODO: REVISAR

    void conexionar(Prenda* compatible); //Se agrega en el vector de prendas

    int getNroPrenda();

    void setNroPrenda();

    int getTiempoLavado();

    void setTiempoLavado();

    int getCantCompatib();

};


#endif //TP_MODELOS_1_PARTE_2_PRENDA_H
