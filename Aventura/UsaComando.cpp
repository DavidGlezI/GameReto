#include "UsaComando.h"

// Esta clase fue hecha por David González y Fernando García


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
            if(nombre == "cajon"){
                if(actual->getItemR(actual->buscaItemR("LamparaUv")) == nullptr){
                    std::cout<<"----------------"<<std::endl;
                    std::cout<<"Ya has abierto este cajon!"<<std::endl;
                    std::cout<<"----------------"<<std::endl;
                }
                else{
                    ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("LamparaUv")); //nullptr
                    objeto ->setDescubierto(true);
                    std::cout<<"----------------"<<std::endl;
                    usarItem->interactuar();
                    objeto ->imprime();
                    std::cout<<"----------------"<<std::endl;
                }
            }
            else if(nombre == "alfombra"){
                if(actual->getItemR(actual->buscaItemR("Llave1"))== nullptr){
                    std::cout<<"----------------"<<std::endl;
                    std::cout<<"Ya no hay nada debajo del alfombra"<<std::endl;
                    std::cout<<"----------------"<<std::endl;
                }
                else{
                    ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("Llave1"));
                    objeto ->setDescubierto(true);
                    std::cout<<"----------------"<<std::endl;
                    usarItem->interactuar();
                    objeto ->imprime();
                    std::cout<<"----------------"<<std::endl;
                }
            }
            else if(nombre == "switchLuz"){
                usarItem->interactuarSwitch();
                if(usarItem->getEncendido()==false && jugador->verificarItem("LamparaUv")){
                    ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("LlaveCarro"));
                    objeto ->setDescubierto(true);
                    std::cout<<"----------------"<<std::endl;
                    std::cout<<"Puedes ver las huellas con la luz apagada! Mira, las llaves del carro"<<std::endl;
                    objeto ->imprime();
                    std::cout<<"----------------"<<std::endl;
                }
            }
            else if(nombre == "Candado"){
                if(jugador->verificarItem("LlaveCarro")){
                    bool lock;
                    lock =usarItem->interactuarCandado();
                    if(lock==true){
                        usarItem->setEncendido(true);
                    }
                    else{
                        usarItem->incrementaVez();
                    }
                }
                else{
                    std::cout<<"No tienes la llave del carro! Pista: Usa la lampara ultravioleta con la luz apagada!"<<std::endl;
                }
                /*
                int combinacion;
                std::cout<<"----------------"<<std::endl;
                std::cout<<"Intento numero: "<<usarItem->getVez()<<std::endl;
                std::cout<<"Solo tienes dos intentos. Ingresa la combinacion del candado: "<<std::endl;
                std::cout<<"----------------"<<std::endl;
                std::cin>>combinacion;
                if(combinacion != 1890){
                    std::cout<<"No es esa!"<<std::endl;
                    usarItem->incrementaVez(); // si llega a 3 se acaba el juego y no logras escapar
                }
                else{
                    std::cout<<"Se abrio!"<<std::endl;
                    usarItem->setEncendido(true);
                }
                */
            }
            else if(nombre == "Lampara"){
                if(actual->getItemR(actual->buscaItemR("Llave2")) == nullptr){
                    std::cout<<"----------------"<<std::endl;
                    std::cout<<"Ya usaste la lampara!"<<std::endl;
                    std::cout<<"----------------"<<std::endl;
                }
                else{
                    ItemRecogible* objeto = actual->getItemR(actual->buscaItemR("Llave2"));
                    objeto ->setDescubierto(true);
                    std::cout<<"----------------"<<std::endl;
                    usarItem->interactuar();
                    objeto ->imprime();
                    std::cout<<"----------------"<<std::endl;
                }        
            }
            else{
                std::cout<<"----------------"<<std::endl;
                usarItem->interactuar();
                std::cout<<"----------------"<<std::endl;
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