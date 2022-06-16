#include "Comando.h"

Comando::Comando(){
    comando="";
    segPalabra="";
}

Comando::Comando(std::string com, std::string seg){
    comando=com;
    segPalabra=seg;
}

std::string Comando::getComando() const{
    return comando;
}

std::string Comando::getSegPalabra() const{
    return segPalabra;
}

void Comando::setSegPalabra(std::string seg){
    segPalabra=seg;
}


bool Comando::tieneSegPalabra(){
    return segPalabra!="";
}
