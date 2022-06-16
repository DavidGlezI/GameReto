#include "Game.h"


// Esta clase fue hecha por David González y Fernando García
Game::Game(){
    creaElementos();
    creaComandos();
}

void Game::creaComandos(){
    ListaPalabras* comandos=parser.getComandos();
    comandos->agregaComando("desplaza", new DesplazaComando(personaje));
    comandos->agregaComando("toma", new TomaComando(personaje));
    comandos->agregaComando("ayuda", new AyudaComando(comandos));
    comandos->agregaComando("usa", new UsaComando(personaje));
    comandos->agregaComando("muestra", new MuestraComando(personaje));
    comandos->agregaComando("quita", new QuitaComando(personaje));
    comandos->agregaComando("salir", new SalirComando(personaje));
}

/*crea todos los elementos que están presentes en el juego 
y los configura (cuartos sus salidas y que objetos hay en cada room)*/
void Game::creaElementos(){
    personaje=new Character("Morbius", false);
    cuarto1=new Room("Primer habitacion!", "He despertado aqui!",false,0);
    cuarto2=new Room("Segundo cuarto!","Hay poca luz!", true, 1);
    cuarto3=new Room("Tercer cuarto!", "La cerradura se parece a la del primer cuarto!", true, 2);
    cuarto4=new Room("Ultimo cuarto!","Necesitamos escapar!", true, 1);
    cajon=new ItemEstatico("cajon", "Encontraste algo dentro!", true, false,0);
    alfombra=new ItemEstatico("alfombra", "Encontraste algo debajo!", true, false,0);
    cuadro1=new ItemEstatico("cuadro1", "Solo necesito 1 carnada", true, false,0);
    cuadro2=new ItemEstatico("cuadro2", "Desde hace 8 semanas me sigue un policia...", true, false,0);
    cuadro3=new ItemEstatico("cuadro3", "Yo soy responsable por las 9 victimas del periodico", true, false,0);
    cuadro4=new ItemEstatico("cuadro4", "El dia 0 esta cerca!", true, false,0);
    lampUv = new ItemRecogible("LamparaUv","Luz ultravioleta","Lamp",3,false);
    lampNormal = new ItemEstatico("Lampara","Haz encontrado una nueva Llave!",true,false,0);
    switchLuz = new ItemEstatico("switchLuz", "Puede haber algo dentro", true, true,0);
    ventana = new ItemEstatico("ventana", "Mira! un carro, es nuestra oportunidad de escapar. Me pregunto donde estaran las llaves", true, false,0);
    llave1 = new ItemRecogible("Llave1", "La primera llave!","Llave", 1, false);
    llave2 = new ItemRecogible("Llave2", "Llave del cuarto dos!","Llave", 2, false);
    carroLlave = new ItemRecogible("LlaveCarro","Llave del Carro", "Por fin! Salgamos de aqui", 4, false);
    candado = new ItemEstatico("Candado", "Una combinacion de 4 numeros! Los necesito para sobrevivir!", true, false,1);
    ventana=new ItemEstatico("ventana", "Mira un carro afuera! Necesitamos encontrar las llaves.", true, false,0);
    personaje->setPosicion(cuarto1);
    cuarto1->agregaItemE(cajon);    
    cuarto1->agregaItemE(alfombra);
    cuarto1->agregaItemE(cuadro1);
    cuarto2->agregaItemE(cuadro2);
    cuarto3->agregaItemE(cuadro3);    
    cuarto4->agregaItemE(cuadro4);
    cuarto4->agregaItemE(switchLuz);
    cuarto4->agregaItemR(carroLlave);
    cuarto1->agregaItemR(llave1);
    cuarto2->agregaItemR(llave2);
    cuarto1->agregaItemR(lampUv);
    cuarto2->agregaItemE(lampNormal);
    cuarto4->agregaItemE(candado);
    cuarto4->agregaItemE(ventana);


    cuarto1->setSalidas(nullptr, cuarto2, cuarto4, nullptr);
    cuarto2->setSalidas(cuarto1, nullptr, cuarto3, nullptr);
    cuarto3->setSalidas(cuarto4, nullptr, nullptr, cuarto2);
    cuarto4->setSalidas(nullptr, cuarto3, nullptr, cuarto1);
}

void Game::imprimeBienvenida(){
    std::cout<<"Acabas de despertar, pero oh sorpresa, estas en la cabaña del asesino!"<<std::endl;
    std::cout <<"No sabes cuando regresara, debes salir de aqui lo antes posible..."<<std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: ayuda" << std::endl;
}

 void Game::play()
    {
        imprimeBienvenida();
        int finished = 0;
        while (finished==0) {
            Comando* comando = parser.generaComando();
            try{ // Manejo de excepciones de Comandos
                if(comando==nullptr){
                    throw "Comando no valido";
                }
                finished = procesaComando(comando);
            }
            catch(const char* msg){
                std::cerr << msg << std::endl;
                std::cout << "Ingresa otro comando: ";
            }    
        }
        if(finished == 3){
            std::cout<<"Saliste del juego."<<std::endl;
            std::cout << "Gracias por jugar este juego de aventura" << std::endl;
        }
        else if(finished==2){
            std::cout<<"Ya no tienes tiempo! Acaba de volver a la casa."<<std::endl;
            std::cout << "Lo lamento, no escapaste! Gracias por jugar este juego de aventura" << std::endl;

        }
        else if(finished==1){
            std::cout<<"Enciendes el carro y manejas lo mas lejos posible."<<std::endl;
            std::cout << "Felicidades! Lograste escapar con vida! Gracias por jugar este juego de aventura" << std::endl;
        }

    }
    int Game::procesaComando(Comando* instr){
        int salio = 0;
        instr->ejecuta(); // se esta ejecutando polimorfismo
        if(personaje->getAbandonar()){ // Salir del juego, con comando salir
                salio = 3;
        }
        else if(personaje->getPosicion()==cuarto4){
            if(candado->getVez()>1){
                salio = 2;
            }
            else if(personaje->verificarItem("LlaveCarro") && candado->getEncendido()){
                salio = 1;
            }
            else if(personaje->verificarItem("LlaveCarro") && candado->getEncendido()==false){
                std::cout<<"----------------"<<std::endl;
                std::cout<<"Solo falta abrir el candado!"<<std::endl;
                std::cout<<"----------------"<<std::endl;
            }
        }
    return salio;  
    }
