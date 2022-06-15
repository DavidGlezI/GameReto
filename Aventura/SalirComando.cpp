#include "SalirComando.h"

SalirComando::SalirComando(Character* personaje):Comando("Salir", ""){
    jugador = personaje;
}

void SalirComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"Si quieres abandonar el juego ingresa el comando salir seguido de la palabra juego"<< std::endl;
    }
    else{
        std::string cosa = getSegPalabra();
        if (cosa == "juego"){
            jugador->setAbandonar(true);
        }
    }
}