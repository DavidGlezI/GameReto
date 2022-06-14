#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Room.h"
#include "DesplazaComando.h"
#include "AyudaComando.h"
#include "TomaComando.h"
#include "UsaComando.h"
#include "MuestraComando.h"
#include "QuitaComando.h"
#include "Parser.h"


class Game {
    public:
        Game();
        void creaElementos();
        void creaComandos();
        void play();
        bool procesaComando(Comando*);
        void imprimeBienvenida();
    private:
        Parser parser;
        Character* personaje;
        Room *cuarto1, *cuarto2, *cuarto3, *cuarto4;
        ItemRecogible *llave1, *llave2, *carroLlave, *lampUv;
        ItemEstatico *cajon, *alfombra, *cuadro1, *cuadro2, *cuadro3, *cuadro4, *switchLuz, *ventana, *lampNormal; 
    
};





#endif //GAME_H