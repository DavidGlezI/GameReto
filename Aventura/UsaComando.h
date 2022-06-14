#ifndef USACOMANDO_H
#define USACOMANDO_H
#include "Character.h"
#include "Item.h"
#include "Comando.h"
#include "Room.h"
class UsaComando:public Comando{
    public:
        UsaComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

#endif //USACOMANDO_H