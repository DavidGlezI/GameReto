#ifndef SALIRCOMANDO_H
#define SALIRCOMANDO_H
#include "Character.h"
#include "Item.h"
#include "Comando.h"
#include "Room.h"
class SalirComando:public Comando{
    public:
        SalirComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

#endif //SALIRCOMANDO_H