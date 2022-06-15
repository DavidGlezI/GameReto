#include "ItemEstatico.h"

ItemEstatico::ItemEstatico(){
    primerUso = true;
    frase = "";
    encendido = true;
}

ItemEstatico::ItemEstatico(std::string desc,std::string info, bool state, bool power, int numVez):Item(desc){
    primerUso = state;
    frase = info;
    encendido = power;
    vez = numVez;
}
void ItemEstatico::interactuar(){
    std::cout<<frase<<std::endl;
    std::cout<<"Mira los objetos del cuarto! Comando: muestra objetos"<<std::endl;
    primerUso= false;
}

int ItemEstatico::getVez(){
    return vez;
}

void ItemEstatico::incrementaVez(){
    vez=vez+1;
}

void ItemEstatico::interactuarSwitch(){
    if(encendido){
        encendido = false;
        std::cout<<"El Switch ahora esta apagado! No hay luz!"<<std::endl;
    }
    else if(encendido == false){
        encendido = true;
        std::cout<<"El Switch esta prendido! Hay Luz!"<<std::endl;

    }

}

bool ItemEstatico::interactuarCandado(){
    int combinacion;
    bool abierto = false;
    std::cout<<"----------------"<<std::endl;
    std::cout<<"Solo tienes 1 intento. Ingresa la combinacion del candado: "<<std::endl;
    std::cout<<"----------------"<<std::endl;
    std::cin>>combinacion;
    if(combinacion != 1890){
        std::cout<<"No es esa!"<<std::endl;
        abierto = false;

    }
    else{
        std::cout<<"Se abrio!"<<std::endl;
        abierto = true;
    }
    return abierto;

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
    if(Item::getDescripcion()=="switchLuz"){
        if(encendido){
            std::cout<<"Luz prendida"<<std::endl;
        }
        else{
            std::cout<<"Luz apagada"<<std::endl;
        }
    }
    else if(Item::getDescripcion()=="Candado"){
        std::cout<<"Combinacion de 4 numeros! Solo podemos intentarlo una vez!" <<std::endl;
        std::cout<<"Asegurate de tener las llaves del carro antes de usar el candado!"<<std::endl;
    }
    else{
        if(primerUso){
            std::cout << "No has interactuado con este item!"<<" Comando: usa"<<std::endl;  
        }
        else{
        std::cout << "Ya has interactuado con este item anteriormente!"<<std::endl;
        }
    }
}


