#include "ItemEstatico.h"

ItemEstatico::ItemEstatico(){
    primerUso = true;
    frase = "";
    encendido = true;
}

ItemEstatico::ItemEstatico(std::string desc,std::string info, bool state, bool power):Item(desc){
    primerUso = state;
    frase = info;
    encendido = power;
}
void ItemEstatico::interactuar(){
    std::cout<<frase<<std::endl;
    primerUso= false;

}

void ItemEstatico::interactuarSwitch(){
    if(encendido){
        std::cout<<"El Switch ahora esta apagado! No hay luz!"<<std::endl;
        encendido = false;
    }
    if(encendido == false){
        std::cout<<"El Switch esta prendido! Hay Luz!"<<std::endl;
        encendido = true;
    }

}

bool ItemEstatico::getEncendido(){
    return encendido;
}

void ItemEstatico::setEncendido(bool power){
    encendido = power;
}

bool ItemEstatico::getPrimerUso() const{
    return primerUso;
}

void ItemEstatico::setPrimerUso(bool state){
    primerUso = state;
}

void ItemEstatico::setFrase(std::string info){
    frase = info;
}

std::string ItemEstatico::getFrase(){
    return frase;
}



void ItemEstatico::imprime(){
    Item::imprime();
    if(primerUso){
        std::cout << "No has interactuado con este item!"<<std::endl;  
    }
    else{
        std::cout << "Ya has interactuado con este item anteriormente!"<<std::endl;

    }
}


