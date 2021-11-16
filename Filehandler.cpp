
#include "Filehandler.h"

Filehandler::Filehandler(string path) {
    archivo.open(path);
}

void Filehandler::procesar() {

}

Filehandler::~Filehandler() {
    archivo.close();
}