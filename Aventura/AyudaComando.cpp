#include "AyudaComando.h"

AyudaComando::AyudaComando(ListaPalabras* palabras):Comando("Ayuda", ""){
    validas=palabras;
}

void AyudaComando::ejecuta(){
    std::cout<< "Tendras que salir por tu propia cuenta" << std::endl;
    std::cout << "Pero no te preocupes, recuerda...." << std::endl;
    std::cout<<"----------------"<<std::endl;
    std::cout << validas->todosLosComandos() << std::endl;
    std::cout<<"----------------"<<std::endl;
    std::cout<<"Ingresa las palabras tal cual se muestran en el menú!"<<std::endl;
    
}