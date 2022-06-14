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
        Room* actual= jugador->getPosicion(); // guardo el cuarto en el que se encuentra el personaje
        int num=jugador->buscaItemR(cosa); //veo si está en el inventario (posicion dentro del vector)
        ItemRecogible* deJugador=jugador->getItemR(num);
        if (num!=-1){
            //std::cout<<"Recuerda: si quieres quitar una llave, sacaras la que hayas recogido primero!"<<std::endl;
            actual->agregaItemR(deJugador);
            jugador->sacaItemR(num);
            std::cout<<"----------------"<<std::endl;
            std::cout << "Haz soltado: "<< std::endl;
            deJugador->imprime();
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

