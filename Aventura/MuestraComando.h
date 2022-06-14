#ifndef MUESTRACOMANDO_H
#define MUESTRACOMANDO_H
#include "Character.h"
#include "Item.h"
#include "Comando.h"
#include "Room.h"
class MuestraComando:public Comando{
    public:
        MuestraComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

#endif //USACOMANDO_H