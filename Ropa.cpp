#include "Ropa.h"

Ropa::Ropa(Prenda **grafo, vector<int> grafoOrdenadoTiempos, int cantPrendas, int cantIncompatib) {
    this->grafo = grafo;
    this->grafoOrdenadoTiempos = grafoOrdenadoTiempos;
    this->cantPrendas = cantPrendas;
    this->cantIncompatib = cantIncompatib;
    this->tiempoTotalPorLavado = 0;
    this->cantPrendasEnLavado = 0;
    this->nroLavado = 0;
    this->tiempoAcum = 0;
    visitados = new bool [cantPrendas];
    for (int i=1; i < cantPrendas ; i++){
        visitados[i] = false;
    }
    /*
    for (int i = 0; i<cantPrendas ; i++){
        cout << grafo[(grafoOrdenadoTiempos[i]-1)]->getNroPrenda() << " ";
    }*/
    procesar();
    presentarResultadoFinal();
}

void Ropa::procesar() {
    while (!seVisitaronTodasLasPrendas()){ //TODOS LOS LAVADOS
        nroLavado++;
        nroPrendaActual = buscarPrendaARevisar();
        vectorPrendasEnLavado.push_back(nroPrendaActual);
        cantPrendasEnLavado++;
        visitados[nroPrendaActual-1] = true;
        tiempoTotalPorLavado = grafo[nroPrendaActual - 1]->getTiempoLavado();
        //cout << "Se acepta la primer prenda del lavado " << nroLavado << endl;
        //cout << "Esa prenda es " << nroPrendaActual << endl;
        realizarUnLavado();

        //if (nroLavado == 2){
            //cin.ignore();
        //}



        //Ahora que tengo la prenda a revisar, la agarro y la agrego al lavado 1 [nroLavado, una variable],
        // con su tiempo como tiempoTotalPorLavado
        //Guardo la prenda en un vector dinamico vectorPrendasEnLavado


        //Me fijo en su vector de punteros de la prenda recien agregada para ESTABLECES PROXIMA PRENDA
        //Sumo al lavado a la prenda no visitada de 0 a n (osea con mas compatibilidades)
        //Que A SU VEZ DEBERA SER COMPATIBLE CON TODAS LAS PRENDAS PREVIAS A LA ULTIMA AGREGADA
        //Para eso, reviso en el vector compatibilidades de la posible prenda nueva
        //Y verifico que esten todas las prendas del vector vectorPrendasEnLavado


        //SI ENCUENTRO UNA prenda q cumple, la sumo al vectorPrendasEnLavado;
        // y veo si su tiempo es el nuevo tiempoTotalPorLavado

        //SI NO ENCUENTRO UNA PRENDA en la ultima prenda agregada, que cumpla las condiciones dichas,
        //Se da por terminado el lavado, lo que significa que
        //Debere recorrer el vectorPrendasEnLavado para agregar como atributos a cada una de dichas prendas
        //El nroLavado, que quedo fijo en esta iteracion
        //El tiempoLavado, que se fue actualizando cada vez que se agregaba una prenda al lavado


        /*if (nroLavado == 44){
            cout << " ";
        }

        cout << "Se visitaron todas las prendas? " << seVisitaronTodasLasPrendas() << endl;
        for (int h = 0 ; h < cantPrendas ; h++){
            cout << grafo[h]->getNroPrenda() << " = " << visitados[h] << endl;
        }*/


        tiempoAcum += tiempoTotalPorLavado;
    }
}

void Ropa::realizarUnLavado() {
    bool terminoLavado = false, seConsiguioUnaPrendaNueva;
    int i, cantCompatib;
    Prenda** compatibilidades;
    while (!terminoLavado){ //Ciclo de un lavado
        seConsiguioUnaPrendaNueva = false;
        compatibilidades = grafo[nroPrendaActual-1]->getVectorCompatib();
        cantCompatib = grafo[nroPrendaActual-1]->getCantCompatib();
        //cout << "La prenda actual, la nro " << nroPrendaActual << " tiene " << cantCompatib << " compatibilidades:\n[";
        //for (int k=0 ; k< cantCompatib ; k++){
            //cout << compatibilidades[k]->getNroPrenda() << " ";
        //}cout << " ]\n";

        i = 0;
        while (i < cantCompatib && !seConsiguioUnaPrendaNueva){ //Ciclo de una prenda en el lavado

            //Si no se visito la prenda y es compatible con todas las otras prendas del lavado

            //cout << "Verificacion del IF -----------" << endl;
            //cout << "Se visito la prenda " << compatibilidades[i]->getNroPrenda() <<
            //" ? " <<visitados[compatibilidades[i]->getNroPrenda()-1] << endl;
            if (!(visitados[compatibilidades[i]->getNroPrenda()-1]) &&
            compatibleConLasOtrasPrendasDelLavado(compatibilidades[i]) ){

                seConsiguioUnaPrendaNueva = true;

                /*
                cout << "La prenda nro. " << compatibilidades[i]->getNroPrenda() << " es agregada al lavado " <<
                " por ser compatible con las prendas: ";
                for (int i = 0 ; i < cantPrendasEnLavado ; i++){
                    cout << vectorPrendasEnLavado[i] << " ";
                } cout << endl;
                */

                //Se agrega la prenda al lavado
                this->vectorPrendasEnLavado.push_back(compatibilidades[i]->getNroPrenda());
                cantPrendasEnLavado++;

                //cout << "Se agrego la prenda " << vectorPrendasEnLavado[cantPrendasEnLavado-1] << " al vectorPrendasLavado\n[";
                //for (int k=0 ; k< cantPrendasEnLavado ; k++){
                    //cout << vectorPrendasEnLavado[k] << " ";
                //}cout << " ]\n";

                //Actualizacion de duracion del lavado
                if (compatibilidades[i]->getTiempoLavado() > tiempoTotalPorLavado){
                    tiempoTotalPorLavado = compatibilidades[i]->getTiempoLavado();
                    //cout << "Se actualizo el tiempo de lavado!" << endl;
                }

                //cout << "El tiempo de lavado en mins es de " << tiempoTotalPorLavado << endl;

                //Se agrega dicha prenda en el vector de visitados
                visitados[compatibilidades[i]->getNroPrenda()-1] = true;

                //ActualizarNroPrenda
                nroPrendaActual = compatibilidades[i]->getNroPrenda();

                //cout << "La nueva prenda actual es " << nroPrendaActual << endl;
                //cout << "---------------------fin ciclo de prenda agregada" << endl;
            }
            i++;
            if (i == cantCompatib) {
                terminoLavado = true;

                //TODO: SE PROCESAN TODAS LAS PRENDAS!!! EUREKAAAAAA
                cout << "Se termino el lavado nro " << nroLavado << endl;
                cout << "Con un tiempo de minutos " << tiempoTotalPorLavado << endl;
                cout << "Que tiene a las prendas: [ ";
                for (int i = 0 ; i < cantPrendasEnLavado ; i++){
                    cout << vectorPrendasEnLavado[i] << " ";
                } cout << " ]\n";
            }
        }
    }
    terminarLavado();

}




int Ropa::buscarPrendaARevisar() {
    int indiceGrafoOrdenadoTiempos = 0, nroPrendaActual = -1;
    bool encontrado = false;
    while (!encontrado) {
        nroPrendaActual = this->grafoOrdenadoTiempos[indiceGrafoOrdenadoTiempos];
        if (! visitados[nroPrendaActual - 1]) {
            encontrado = true;
        } else {
            indiceGrafoOrdenadoTiempos++;
        }

    }
    return nroPrendaActual;
}

bool Ropa::seVisitaronTodasLasPrendas() {
    bool unoNoVisitado = false;
    bool visitadosTodos = false;
    int i = 0;
    while (!unoNoVisitado && i < cantPrendas){
        if (! visitados[i]){
            unoNoVisitado = true;
        } else {
            i++;
            if (i == cantPrendas){
                visitadosTodos = true;
            }
        }
    }
    return (visitadosTodos);
}

bool Ropa::compatibleConLasOtrasPrendasDelLavado(Prenda* prendaPosibleParaAgregar) {
    bool esCompatible = true; //variable bandera
    int i = 0;
    while (esCompatible && i < cantPrendasEnLavado){
        if (! grafo[vectorPrendasEnLavado[i]-1]->esCompatibleCon(prendaPosibleParaAgregar)){
            esCompatible = false;
            //cout << "El vector no es compatible con una de las prendas" << endl;
            //cout << "En particular, la prenda nro. " << vectorPrendasEnLavado[i] << endl;
        } else {
            i++;
            if (i == cantPrendasEnLavado){
                esCompatible = true;
                //cout << "El vector es compatible con todas las prendas" << endl;
            }
        }
    }
    return esCompatible;
}

void Ropa::terminarLavado() {
    for (int i = 0 ; i < cantPrendasEnLavado ; i++){
        grafo[vectorPrendasEnLavado[i]-1]->setTiempoTotalLavado(tiempoTotalPorLavado);
        grafo[vectorPrendasEnLavado[i]-1]->setNroLavado(nroLavado);
    }
    cantPrendasEnLavado = 0;
    vectorPrendasEnLavado.clear();
}

void Ropa::presentarResultadoFinal() {
    cout << "El tiempo total fue de " << tiempoAcum << " minutos." << endl;
    cout << "Realizandose un total de " << nroLavado << " lavados." << endl;
}

Prenda ** Ropa::getGrafo() {
    return grafo;
}


Ropa::~Ropa() {
    for (int i=1; i < cantPrendas ; i++){
        delete grafo[i];
    }
    delete [] visitados;
    delete grafo;
    vectorPrendasEnLavado.clear();
}


