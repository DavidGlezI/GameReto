#include "Item.h"

Item::Item(){
    descripcion="Este es una cosita bonita";
}

Item::Item(std::string desc){
    descripcion = desc;

}


std::string Item::getDescripcion(){
    return descripcion;
}

void Item::setDescripcion(std::string descp){
    descripcion=descp;
}

void Item::imprime(){
    std::cout << "Objeto: "<< descripcion <<std::endl;
}