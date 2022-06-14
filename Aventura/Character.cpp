#include "Character.h"

Character::Character(){
    posicion=nullptr;
    nombre="Personaje";
    numItems=0;
}

Character::Character(std::string name){
    posicion=nullptr;
    nombre=name;
    numItems=0;
}

std::string Character::getNombre() const{
    return nombre;
}

void Character::setNombre(std::string name){
    nombre=name;
}

Room* Character::getPosicion() const{
    return posicion;
}

void Character::setPosicion(Room* nuevo){
    posicion=nuevo;
}
        
void Character::agregaItemR(ItemRecogible* item){
    if (numItems<2){
        inventario[numItems++]=item;
    }
    else{
        std::cout << "Solo puedes llevar dos objetos al mismo tiempo!..., deja algunos!"<<std::endl;
    }
}

void Character::sacaItenR(ItemRecogible* item){
    if (numItems>0){
        inventario[numItems--]=item;
    }
    else{
        std::cout << "No tienes objetos que dejar!"<<std::endl;
    }
}


bool Character::buscaItemR(std::string cosa){
    for(int i=0; i<numItems; i++){
        if (inventario[i]->getDescripcion()==cosa){
            return true;
        }
    }
    return false;
}

bool Character::buscaItemRconID(std::string cosa, int id){
    for(int i=0; i<numItems; i++){
        if (inventario[i]->getDescripcion()==cosa && inventario[i]->getCuartoFunc()==id){
            return true;
        }
    }
    return false;
}


bool Character::camina(std::string dir){
    Room* voyA=posicion->getSalida(dir); // asigna a voyA el cuarto al que quieres salir
    if (voyA!=nullptr && !voyA->getTieneLlave()){
        setPosicion(voyA);
        return true;
    }
    else if (voyA!=nullptr && voyA->getTieneLlave()){
        if (buscaItemRconID("Llave", voyA->getNumLlave())){
            voyA->setTieneLlave(false); // Quitamos que el cuarto necesite llave una vez abierto por primera vez
            setPosicion(voyA);
            return true;
        }
    }
    return false;
}

void Character::imprime(){
    std::cout << "Soy " << nombre <<std::endl;
    std::cout << "y llevo  "<< numItems << " objeto(s): " << std::endl;
    for(int i=0; i<numItems; i++){
        inventario[i]->imprime();
    }
}
