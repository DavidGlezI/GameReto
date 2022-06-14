#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Room.h"
#include <vector>

class Character {
    public:
        Character();
        Character(std::string);
        std::string getNombre() const;
        void setNombre(std::string);
        Room* getPosicion() const;
        void setPosicion(Room*);
        void agregaItemR(ItemRecogible*);
        void sacaItemR(int);
        ItemRecogible* getItemR(int pos);
        void imprime();
        bool camina(std::string);
        int buscaItemR(std::string);
        bool buscaItemRconID(std::string, int);
    private:
        std::string nombre;
        Room* posicion;
        //ItemRecogible* inventario[2];
        std::vector<ItemRecogible*> obejtosPersona;
        int numItems;
};



#endif //CHARACTER_H