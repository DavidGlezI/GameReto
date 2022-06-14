#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Room.h"

class Character {
    public:
        Character();
        Character(std::string);
        std::string getNombre() const;
        void setNombre(std::string);
        Room* getPosicion() const;
        void setPosicion(Room*);
        void agregaItemR(ItemRecogible*);
        void sacaItenR(ItemRecogible*);
        ItemRecogible* consultaItemR(int pos) const;
        void imprime();
        bool camina(std::string);
        bool buscaItemR(std::string);
        bool buscaItemRconID(std::string, int);
    private:
        std::string nombre;
        Room* posicion;
        ItemRecogible* inventario[2];
        int numItems;
};



#endif //CHARACTER_H