//
// Created by gaby on 16/11/21.
//

#ifndef TP_MODELOS_1_PARTE_2_FILEHANDLER_H
#define TP_MODELOS_1_PARTE_2_FILEHANDLER_H
#include <iostream>
#include <fstream>
using namespace std;

class Filehandler {
private:
    ifstream archivo;
public:
    Filehandler(string path);

    void procesar();

    ~Filehandler();
};


#endif //TP_MODELOS_1_PARTE_2_FILEHANDLER_H
