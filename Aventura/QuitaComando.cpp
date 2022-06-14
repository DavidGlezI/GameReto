#include "QuitaComando.h"

QuitaComando::QuitaComando(Character* personaje):Comando("Quita", ""){
    jugador=personaje;
}

void QuitaComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"Que quieres quitar de tu inventario?...\n" << "no puedo ayudarte si no me das toda la información..." << std::endl;
    }
    else{
        std::string cosa = getSegPalabra();
        Room* actual= jugador->getPosicion();
        int num=jugador->buscaItemR(cosa); //veo si está en el cuarto (posicion dentro del vector)
        if (num!=-1){
            ItemRecogible* paraJugador=actual->getItemR(num);
            jugador->sacaItenR(paraJugador);
            actual->agregaItemR(paraJugador);
            std::cout<<"----------------"<<std::endl;
            std::cout << "Haz soltado: "<< std::endl;
            paraJugador->getDescEspecializada();
            std::cout<<"----------------"<<std::endl;
        }
        else{
            std::cout<<"----------------"<<std::endl;
            std::cout<< "Ese objeto no se encuentra en tu inventario..."<<std::endl;
            std::cout << "Recuerda que tienes: " << std::endl;
            jugador->imprime(); // cambiar esto
            std::cout<<"----------------"<<std::endl;
        }
    }
}