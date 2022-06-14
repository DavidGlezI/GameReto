#ifndef AYUDACOMANDO_H
#define AYUDACOMANDO_H
#include "Comando.h"
#include "ListaPalabras.h"
class AyudaComando:public Comando{
    public:
        AyudaComando(ListaPalabras*);
        void ejecuta();
    private:
        ListaPalabras* validas;
};


#endif //AYUDACOMANDO_H