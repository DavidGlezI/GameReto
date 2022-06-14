#ifndef QUITACOMANDO_H
#define QUITACOMANDO_H
#include "Character.h"
#include "Item.h"
#include "Comando.h"
#include "Room.h"
class QuitaComando:public Comando{
    public:
        QuitaComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

#endif 