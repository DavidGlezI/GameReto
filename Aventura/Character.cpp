#include "Character.h"

Character::Character(){
    posicion=nullptr;
    nombre="Personaje";
    numItems=0;
}

Character::Character(std::string name){
    posicion=nullptr;
    nombre=name;
    numItems=0;
}

std::string Character::getNombre() const{
    return nombre;
}

void Character::setNombre(std::string name){
    nombre=name;
}

Room* Character::getPosicion() const{
    return posicion;
}

void Character::setPosicion(Room* nuevo){
    posicion=nuevo;
}
/*    
void Character::agregaItemR(ItemRecogible* item){
    if (numItems<2){
        inventario[numItems++]=item;
    }
    else{
        std::cout << "Solo puedes llevar dos objetos al mismo tiempo!..., deja algunos!"<<std::endl;
    }
}

void Character::sacaItemR(ItemRecogible* item){
    if (numItems>0){
        inventario[numItems--]=item;
    }
    else{
        std::cout << "No tienes objetos que dejar!"<<std::endl;
    }
}
*/
void Character::agregaItemR(ItemRecogible* cosita){ // Agrega un item al final del arreglo 
    obejtosPersona.push_back(cosita);
}

void Character::sacaItemR(int pos){
    obejtosPersona.erase(obejtosPersona.begin()+pos); //Borra el de la posicion pos del vector de cosas
}

int Character::buscaItemR(std::string cosa){  // Recorre el arreglo de cosas para buscar un objeto /string/. Si existe regresa el index del arreglo, si no un -1
    for(int i=0; i<obejtosPersona.size();i++){
        if(obejtosPersona[i]->getDescripcion()==cosa){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}

ItemRecogible* Character::getItemR(int num){
    if (num>=0 && num<obejtosPersona.size()){
        return obejtosPersona[num];
    }
    return nullptr;
    
}

bool Character::buscaItemRconID(std::string cosa, int id){
    for(int i=0; i<obejtosPersona.size(); i++){
        if (obejtosPersona[i]->getDescripcion()==cosa && obejtosPersona[i]->getCuartoFunc()==id){
            return true;
        }
    }
    return false;
}


bool Character::camina(std::string dir){
    Room* voyA=posicion->getSalida(dir); // asigna a voyA el cuarto al que quieres salir
    if (voyA!=nullptr && !voyA->getTieneLlave()){
        setPosicion(voyA);
        return true;
    }
    else if (voyA!=nullptr && voyA->getTieneLlave()){
        if (buscaItemRconID("Llave", voyA->getNumLlave())){
            voyA->setTieneLlave(false); // Quitamos que el cuarto necesite llave una vez abierto por primera vez
            setPosicion(voyA);
            return true;
        }
    }
    return false;
}

void Character::imprime(){
    std::cout << "Soy " << nombre <<std::endl;
    std::cout << "y llevo  "<< obejtosPersona.size() << " objeto(s): " << std::endl;
    for(int i=0; i<obejtosPersona.size(); i++){
        obejtosPersona[i]->imprime();
    }
}
