#include "ItemRecogible.h"


ItemRecogible::ItemRecogible(){
    cuartoFunc = 0;
    descEspecializada = "";
    descubierto = false;

}

ItemRecogible::ItemRecogible(std::string desc, std::string descE, std::string type,int cf, bool yaDescubierto):Item(desc){
    cuartoFunc = cf;
    descEspecializada = descE;
    tipo = type;
    descubierto = yaDescubierto;
}

void ItemRecogible::setCuartoFunc(int cf){
    cuartoFunc  = cf;

}
void ItemRecogible::setDescubierto( bool decl){
    descubierto = decl;
}

bool ItemRecogible::getDescubierto() const{
    return descubierto;
}

void ItemRecogible::setDescEspecializada(std::string descE){
    descEspecializada = descE;
}

std::string ItemRecogible::getDescEspecializada() const{
    return descEspecializada;
}

void ItemRecogible::setTipo(std::string type){
    tipo = type;
}

std::string ItemRecogible::getTipo() const{
    return tipo;
}

int ItemRecogible::getCuartoFunc() const{
    return cuartoFunc;
}

std::ostream& operator << (std::ostream & salida, ItemRecogible* miItemR){
    salida << "Objeto: "<<miItemR->Item::getDescripcion()<<" Descripcion: "<<miItemR->descEspecializada;

    return salida;
}

void ItemRecogible::imprime(){
    if(descubierto){
        if(Item::getDescripcion()=="LamparaUv"){
            Item::imprime();
            std::cout <<"Descripcion: "<< descEspecializada<<" Puede ser util mas adelante."<<" Comando: toma"<<std::endl; 
        }
        else if(Item::getDescripcion()=="Llave2"){
            Item::imprime();
            std::cout <<"Descripcion: "<< descEspecializada<<" La encontramos usando la lampara!"<<" Comando: toma"<<std::endl; 
        }
        else if(Item::getDescripcion()=="Llave1"){
            Item::imprime();
            std::cout <<"Descripcion: "<< descEspecializada<<" Hay que salir de aqui!"<<" Comando: toma"<<std::endl; 
        }
        else{
            Item::imprime();
            std::cout <<"Descripcion: "<< descEspecializada<<" Funciona en el cuarto: "<< std::to_string(cuartoFunc)<<std::endl; // ver lo de las descripciones

        }
    }

}

