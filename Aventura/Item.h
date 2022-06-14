#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>


class Item {
    public:
        Item();
        Item(std::string);
        std::string getDescripcion();
        void setDescripcion(std::string);
        virtual void imprime();
        
    private:
        std::string descripcion;
};


#endif //ITEM_H