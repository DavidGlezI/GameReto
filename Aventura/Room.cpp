#include "Room.h"

Room::Room(){
    descripcion="Es una habitacion sin nombre";
    for (int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    tieneLlave= true;
}
Room::Room(std::string desc, std::string frase,bool cerrado, int num){
    descripcion=desc;
    quote = frase;
    for (int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    tieneLlave=cerrado;
    numLlave = num;
}

int Room::getNumLlave() const{
    return numLlave;
}

void Room::setNumLlave(int num){
    numLlave = num;
}

Room* Room::getSalida(std::string dir){ // Transforma el texto de norte, sur , este oeste con la funcion de numsalida y guardamos el entero. Devuelve la salida en ese index del arreglo de saldias
    int num=numSalida(dir);
    if(num>=0){
        return salidas[num];
    }
    return nullptr;
}

void Room::setSalidas(Room* n, Room* s, Room* e, Room* o){
    salidas[0]=n;
    salidas[1]=s;
    salidas[2]=e;
    salidas[3]=o;
}

std::string Room::getDescripcion(){
    return descripcion;
}

std::string Room::getQuote(){
    return quote;
}

void Room::setQuote(std::string frase){
    quote = frase;
}

ItemRecogible* Room::getItemR(int num){ // Devuelve el item que se encuentra en ese index si existe, si no regresa un null pointer
    if (num>=0 && num<cosas.size()){
        return cosas[num];
    }
    return nullptr;
}

ItemEstatico* Room::getItemE(int num){ // Devuelve el item que se encuentra en ese index si existe, si no regresa un null pointer
    if (num>=0 && num<decoracion.size()){
        return decoracion[num];
    }
    return nullptr;
}


bool Room::getTieneLlave(){ // tieneLlave es False
    return tieneLlave;
}

void Room::setTieneLlave(bool llave){
    tieneLlave = llave;
}

void Room::agregaItemR(ItemRecogible* cosita){ // Agrega un item al final del arreglo 
    cosas.push_back(cosita);
}

void Room::agregaItemE(ItemEstatico* dec){ // Agrega un item al final del arreglo 
    decoracion.push_back(dec);
}

int Room::buscaItemR(std::string que){  // Recorre el arreglo de cosas para buscar un objeto /string/. Si existe regresa el index del arreglo, si no un -1
    for(int i=0; i<cosas.size();i++){
        if(cosas[i]->getDescripcion()==que){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}
int Room::buscaItemRconID(std::string que, int id){
    for(int i=0; i<cosas.size(); i++){
        if (cosas[i]->getDescripcion()==que && cosas[i]->getCuartoFunc()==id){
            return i;
        }
    }
    return -1;
}

int Room::buscaItemE(std::string que){  // Recorre el arreglo de decoracion para buscar un objeto /string/. Si existe regresa el index del arreglo, si no un -1
    for(int i=0; i<decoracion.size();i++){
        if(decoracion[i]->getDescripcion()==que){
            return i; //devuelve la posición donde está ese objeto
        }
    }
    return -1; //regresa -1 si no encontró ese item
}

void Room::sacaItemR(int pos){
    cosas.erase(cosas.begin()+pos); //Borra el de la posicion pos del vector de cosas
}

void Room::sacaItemE(int pos){
    decoracion.erase(decoracion.begin()+pos); //Borra el de la posicion pos del vector de decoracion
}

void Room::descripcionLarga(){ // Recorre el arreglo del cuarto para ver que objetos hay en la habitacion
    std::cout << descripcion << std::endl;
    std::cout << "Dentro de este cuarto hay: " << std::endl;
    for (int i=0; i<cosas.size(); i++){
        cosas[i]->imprime();
    }
    for (int i=0; i<decoracion.size(); i++){
        decoracion[i]->imprime(); // polimorfismo
    }
}

int Room::numSalida(std::string dir){
    if (dir=="norte"){
        return 0;
    }
    if (dir=="sur"){
        return 1;
    }
    if (dir=="este"){
        return 2;
    }
    if (dir=="oeste"){
        return 3;
    }
    return -1;
}