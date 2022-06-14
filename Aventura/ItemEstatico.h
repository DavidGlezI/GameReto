#ifndef ITEMESTATICO_H
#define ITEMESTATICO_H
#include <string>
#include <iostream>
#include "Item.h"

class ItemEstatico:public Item{
    public:
        ItemEstatico();
        ItemEstatico(std::string, std::string, bool, bool);
        void interactuar();
        void interactuarSwitch();
        bool getPrimerUso() const;
        void setPrimerUso(bool);
        bool getEncendido();
        void setEncendido(bool);
        void setFrase(std::string);
        std::string getFrase();
        void imprime();
    private:
        bool primerUso;
        std::string frase;
        bool encendido;
};





#endif 
