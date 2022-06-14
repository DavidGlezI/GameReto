#include "ItemRecogible.h"


ItemRecogible::ItemRecogible(){
    cuartoFunc = 0;
    descEspecializada = "";
    descubierto = false;

}

ItemRecogible::ItemRecogible(std::string desc, std::string descE, int cf, bool yaDescubierto):Item(desc){
    cuartoFunc = cf;
    descEspecializada = descE;
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

int ItemRecogible::getCuartoFunc() const{
    return cuartoFunc;
}

void ItemRecogible::imprime(){
    if(descubierto){
        if(Item::getDescripcion()=="LamparaUv"){
            Item::imprime();
            std::cout << descEspecializada<<" Puede ser util mas adelante"<<std::endl; 
        }
        else if(Item::getDescripcion()=="Lampara"){
            Item::imprime();
            std::cout << descEspecializada<<" Con la lampara encontraste una llave!"<<std::endl; 
        }
        else{
            Item::imprime();
            std::cout << descEspecializada<<" Funciona en el cuarto: "<< std::to_string(cuartoFunc)<<std::endl; // ver lo de las descripciones

        }
    }

}

