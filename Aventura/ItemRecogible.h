#ifndef ITEMRECOGIBLE_H
#define ITEMRECOGIBLE_H
#include <string>
#include <iostream>
#include "Item.h"

class ItemRecogible:public Item{
    public:
        ItemRecogible();
        ItemRecogible(std::string, std::string, int, bool);
        void setCuartoFunc(int);
        void setDescEspecializada(std::string);
        std::string getDescEspecializada() const;
        int getCuartoFunc() const;
        bool getDescubierto() const;
        void setDescubierto(bool);
        void imprime();
    private:
        std::string descEspecializada;
        int cuartoFunc;
        bool descubierto;
};





#endif 
