#include "AyudaComando.h"

AyudaComando::AyudaComando(ListaPalabras* palabras):Comando("Ayuda", ""){
    validas=palabras;
}

void AyudaComando::ejecuta(){
    std::cout<< "Estas desamparado en esta casa lugubre y solitaria" << std::endl;
    std::cout << "No sabes que hacer, pero no te preocupes, recuerda...." << std::endl;
    std::cout << validas->todosLosComandos() << std::endl;
}