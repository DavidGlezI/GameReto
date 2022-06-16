#include "MuestraComando.h"

// Esta clase fue hecha por David González y Fernando García

MuestraComando::MuestraComando(Character* personaje):Comando("Muestra", ""){
    jugador = personaje;
}

void MuestraComando::ejecuta(){
    std::string palabra = getSegPalabra();
    if(palabra == "inventario"){
        std::cout<<"----------------"<<std::endl;
        jugador->imprime();
        std::cout<<"----------------"<<std::endl;
    }
    else if(palabra == "objetos"){
        Room* actual= jugador->getPosicion();
        std::cout<<"----------------"<<std::endl;
        actual->descripcionLarga();
        std::cout<<"----------------"<<std::endl;
    }
    else{
        std::cout<<"Que quieres mostrar de la habitación?...\n" << "inventario o objetos ?" << std::endl;
    }
}