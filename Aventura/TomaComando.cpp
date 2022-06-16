#include "TomaComando.h"

// Esta clase fue hecha por David González y Fernando García

TomaComando::TomaComando(Character* personaje):Comando("Toma", ""){
    jugador=personaje;
}

void TomaComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"Que quieres tomar de la habitación?...\n" << "no puedo ayudarte si no me das toda la información..." << std::endl;
    }
    else{
        std::string cosa = getSegPalabra();
        Room* actual= jugador->getPosicion();
        int num=actual->buscaItemR(cosa); //veo si está en el cuarto (posicion dentro del vector)
        if (num!=-1){
            if(jugador->cabenItemR()){
                ItemRecogible* paraJugador=actual->getItemR(num);
                jugador->agregaItemR(paraJugador);
                actual->sacaItemR(num);
                std::cout<<"----------------"<<std::endl;
                std::cout << "Ahora tienes en tu poder: "<< std::endl;
                std::cout<<paraJugador<<std::endl; // Sobrecarga de operadores
                std::cout<<"----------------"<<std::endl;
            }
            else{
                std::cout<<"Inventario lleno. Solo puedes llevar dos objetos, suelta uno!"<<std::endl;
            }
        }
        else{
            std::cout<<"----------------"<<std::endl;
            std::cout<< "Ese objeto no se encuentra en esta habitacion..."<<std::endl;
            std::cout << "Recuerda tu estas aqui: " << std::endl;
            actual->descripcionLarga();
            std::cout<<"----------------"<<std::endl;
        }
    }
}