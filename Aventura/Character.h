#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Room.h"
#include <vector>

// Esta clase fue hecha por David González
class Character {
    public:
        Character();
        Character(std::string, bool);
        std::string getNombre() const;
        void setNombre(std::string);
        Room* getPosicion() const;
        void setPosicion(Room*);
        void agregaItemR(ItemRecogible*);
        bool cabenItemR();
        void sacaItemR(int);
        ItemRecogible* getItemR(int);
        void imprime();
        bool camina(std::string);
        int buscaItemR(std::string);
        int buscaItemRconID(std::string, int); // no se usa, error en quita comando
        bool verificarItemId(std::string, int);
        bool verificarItem(std::string);
        bool getAbandonar();
        void setAbandonar(bool);
    private:
        std::string nombre;
        Room* posicion;
        //ItemRecogible* inventario[2];
        std::vector<ItemRecogible*> objetosPersona;
        int numItems;
        bool abandonar;
};



#endif //CHARACTER_H