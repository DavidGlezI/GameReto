#include "UsaComando.h"

UsaComando::UsaComando(Character* personaje):Comando("Usa", ""){
    jugador = personaje;
}

void UsaComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"Que quieres usar de la habitación?...\n" << "no puedo ayudarte si no me das toda la información..." << std::endl;
    }
    else{
        std::string cosa = getSegPalabra();
        Room* actual= jugador->getPosicion(); // Da el cuarto en el que esta el jugador
        int num=actual->buscaItemE(cosa); //veo si está en el cuarto (posicion dentro del vector)
        if (num!=-1){ // Si no es -1 entonces si esta en la habitacion
            ItemEstatico* usarItem=actual->getItemE(num); // Da el item que se buscaba
            std::string nombre = usarItem->getDescripcion(); // Pasa el nombre del item que se buscaba
            if(nombre == "switchluz"){
                usarItem->interactuarSwitch();
            }
            else if(nombre == "cajon"){
                ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("LamparaUv"));
                objeto ->setDescubierto(true);
                std::cout<<"----------------"<<std::endl;
                usarItem->interactuar();
                std::cout<<"----------------"<<std::endl;
            }
            else if(nombre == "alfombra"){
                ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("Llave1"));
                objeto ->setDescubierto(true);
                std::cout<<"----------------"<<std::endl;
                usarItem->interactuar();
                std::cout<<"----------------"<<std::endl;
            }
            else if(nombre == "Lampara"){
                ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("Llave2"));
                objeto ->setDescubierto(true);
                std::cout<<"----------------"<<std::endl;
                usarItem->interactuar();
                std::cout<<"----------------"<<std::endl;
            }
            else{
                std::cout<<"----------------"<<std::endl;
                usarItem->interactuar();
                std::cout<<"----------------"<<std::endl;
            }
        }
        else{
            std::cout<< "Ese objeto no se encuentra en esta habitacion..."<<std::endl;
            std::cout << "Recuerda tu estas aqui: " << std::endl;
            actual->descripcionLarga();
        }
    }
}