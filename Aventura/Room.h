#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "ItemRecogible.h"
#include "ItemEstatico.h"

class Room {
    public:
        Room();
        Room(std::string, std::string ,bool, int); // descripcion, si tiene o no llave, numero de la llave que abre
        std::string getDescripcion();
        void setQuote(std::string);
        std::string getQuote();
        int getNumLlave()const;
        void setNumLlave(int);
        Room* getSalida(std::string); // Devuelve la salida del cuarto al que se quiere ir n,s,e,o
        int numSalida(std::string); // Devuelve el entero del arreglo para la salida, 0 norte, 1 sur, 2 este, 3 oeste. Si no hay nada, devuielve un -1
        void setSalidas(Room*, Room*, Room*, Room*);
        ItemRecogible* getItemR(int);  // ed
        void sacaItemR(int); // ed
        ItemEstatico* getItemE(int);  // ed
        void sacaItemE(int); // ed
        void agregaItemR(ItemRecogible*); // ed
        void agregaItemE(ItemEstatico*); // ed
        int buscaItemR(std::string); // ed
        int buscaItemRconID(std::string, int);
        int buscaItemE(std::string); // ed
        void descripcionLarga();
        bool getTieneLlave();
        void setTieneLlave(bool);
    private:
        std::string descripcion;
        std::string quote;
        std::vector<ItemRecogible*> cosas;
        std::vector<ItemEstatico*> decoracion;
        Room* salidas[4];
        bool tieneLlave;
        int numLlave;
};

#endif //ROOM_H