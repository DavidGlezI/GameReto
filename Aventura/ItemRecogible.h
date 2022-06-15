#ifndef ITEMRECOGIBLE_H
#define ITEMRECOGIBLE_H
#include <string>
#include <iostream>
#include "Item.h"

class ItemRecogible:public Item{
    public:
        ItemRecogible();
        ItemRecogible(std::string, std::string,std::string, int, bool);
        void setCuartoFunc(int);
        void setDescEspecializada(std::string);
        std::string getDescEspecializada() const;
        void setTipo(std::string);
        std::string getTipo() const;
        int getCuartoFunc() const;
        bool getDescubierto() const;
        void setDescubierto(bool);
        friend std::ostream& operator <<(std::ostream&, ItemRecogible*);
        void imprime();
    private:
        std::string descEspecializada;
        std::string tipo; // para que funcione camina
        int cuartoFunc;
        bool descubierto;
};





#endif 
