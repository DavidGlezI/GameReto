#include "Character.h"

Character::Character(){
    posicion=nullptr;
    nombre="Personaje";
    numItems=0;
    abandonar = false;
}

Character::Character(std::string name, bool out){
    posicion=nullptr;
    nombre=name;
    numItems=0;
    abandonar = out;
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
        objetosPersona.push_back(cosita);
    }


bool Character::cabenItemR(){
    if(objetosPersona.size()<2){
        return true;
    }
    else{
        return false;
    }
}

void Character::sacaItemR(int pos){
    if(objetosPersona.size()>0){
        objetosPersona.erase(objetosPersona.begin()+pos); //Borra el de la posicion pos del vector de cosas
    }
    else{
        std::cout << "No tienes objetos que dejar!"<<std::endl;
    }
}

int Character::buscaItemR(std::string cosa){  // Recorre el arreglo de cosas para buscar un objeto /string/. Si existe regresa el index del arreglo, si no un -1
    for(int i=0; i<objetosPersona.size();i++){
        if(objetosPersona[i]->getDescripcion()==cosa){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}

int Character::buscaItemRconID(std::string tipo, int id){ // usamos esta solo para las llaves
    for(int i=0; i<objetosPersona.size(); i++){
        if (objetosPersona[i]->getTipo()==tipo && objetosPersona[i]->getCuartoFunc()==id){
            return i;
        }
    }
    return -1;
}

bool Character::verificarItemId(std::string tipo, int id){ // usamos esta solo para las llaves
    for(int i=0; i<objetosPersona.size(); i++){
        if (objetosPersona[i]->getTipo()==tipo && objetosPersona[i]->getCuartoFunc()==id){
            return true;
        }
    }
    return false;
}

bool Character::verificarItem(std::string cosa){
    for(int i=0; i<objetosPersona.size(); i++){
        if (objetosPersona[i]->getDescripcion()==cosa){
            return true;
        }
    }
    return false;
}


ItemRecogible* Character::getItemR(int num){ // funciona con el indice de buscarItem
    if (num>=0 && num<objetosPersona.size()){
        return objetosPersona[num];
    }
    return nullptr;
    
}


bool Character::camina(std::string dir){
    Room* voyA=posicion->getSalida(dir); // asigna a voyA el cuarto al que quieres salir
    if (voyA!=nullptr && !voyA->getTieneLlave()){
        setPosicion(voyA);
        return true;
    }
    else if (voyA!=nullptr && voyA->getTieneLlave()){
        if (verificarItemId("Llave", voyA->getNumLlave())){
            voyA->setTieneLlave(false); // Quitamos que el cuarto necesite llave una vez abierto por primera vez
            setPosicion(voyA);
            return true;
        }
    }
    return false;
}

bool Character::getAbandonar(){
    return abandonar;
}

void Character::setAbandonar(bool out){
    abandonar = out;
}


void Character::imprime(){
    std::cout << "Soy " << nombre <<std::endl;
    std::cout << "y llevo  "<< objetosPersona.size() << " objeto(s): " << std::endl;
    for(int i=0; i<objetosPersona.size(); i++){
        objetosPersona[i]->imprime();
    }
}
