#ifndef TOMACOMANDO_H
#define TOMACOMANDO_H
#include "Character.h"
#include "Item.h"
#include "Comando.h"
class TomaComando:public Comando{
    public:
        TomaComando(Character*);
        void ejecuta();
    private:
        Character* jugador;
};

#endif //TOMACOMANDO_H