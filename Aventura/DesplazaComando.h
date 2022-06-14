#ifndef DESPLAZACOMANDO_H
#define DESPLAZACOMANDO_H
#include <iostream>
#include "Character.h"
#include "Comando.h"

class DesplazaComando:public Comando{
    public:
        DesplazaComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};


#endif //DESPLAZACOMANDO_H