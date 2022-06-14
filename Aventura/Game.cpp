#include "Game.h"

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
}

/*crea todos los elementos que están presentes en el juego 
y los configura (cuartos sus salidas y que objetos hay en cada room)*/
void Game::creaElementos(){
    personaje=new Character("Morbius");
    cuarto1=new Room("Primer habitacion!", false,0);
    cuarto2=new Room("Este cuarto esta oscuro! Nunca encontraremos la llave!", true, 1);
    cuarto3=new Room("Tercer cuarto! No encuentro la llave pero la cerradura se parece a la del primer cuarto!", true, 2);
    cuarto4=new Room("Sera el ultimo cuarto?", true, 1);
    cajon=new ItemEstatico("cajon", "Encontraste algo dentro!", true, false);
    alfombra=new ItemEstatico("alfombra", "Encontraste algo debajo!", true, false);
    cuadro1=new ItemEstatico("cuadro1", "1923 5", true, false);
    cuadro2=new ItemEstatico("cuadro2", "1954 3", true, false);
    cuadro3=new ItemEstatico("cuadro3", "1973 7", true, false);
    cuadro4=new ItemEstatico("cuadro4", "1994 8", true, false);
    lampUv = new ItemRecogible("LamparaUv", "Luz ultravioleta",3,false);
    lampNormal = new ItemEstatico("Lampara", "Haz encontrado una nueva Llave!",true,false);
    switchLuz = new ItemEstatico("switchluz", "Puede haber algo dentro", true, true);
    ventana = new ItemEstatico("ventana", "Mira! un carro, es nuestra oportunidad de escapar. Me pregunto donde estaran las llaves", true, false);
    llave1 = new ItemRecogible("Llave1", "La primera llave!", 1, false);
    llave2 = new ItemRecogible("Llave2", "Otra llave!", 2, false);
    carroLlave = new ItemRecogible("Llave carro", "Por fin! Salgamos de aqui", 0, false);
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



    cuarto1->setSalidas(nullptr, cuarto2, cuarto4, nullptr);
    cuarto2->setSalidas(cuarto1, nullptr, cuarto3, nullptr);
    cuarto3->setSalidas(cuarto4, nullptr, nullptr, cuarto2);
    cuarto4->setSalidas(nullptr, cuarto3, nullptr, cuarto1);
}

void Game::imprimeBienvenida(){
    std::cout<<"Acabas de despertar, pero oh sorpresa, estas en una casa siniestra"<<std::endl;
    std::cout <<"La casa se ve oscura, da escalofrios, debes salir de aqui..."<<std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: ayuda" << std::endl;
}

 void Game::play()
    {
        imprimeBienvenida();
        bool finished = false;
        while (!finished) {
            Comando* comando = parser.generaComando();
            finished = procesaComando(comando);
        }
        
        std::cout << "Gracias por jugar este juego de aventura" << std::endl;
    }

    bool Game::procesaComando(Comando* instr){
        bool salio = false;
        instr->ejecuta(); // se esta ejecutando polimorfismo

        // Si el personaje esta en el C3, que se abra la otra puerta, agregar maybe?
        // Editar lo de abajo para que tenga el codigo y llaves del carro y salga
        // Checar lo de llaves para cada cuarto  token
        // Checar comando de puerta con llave para hacer funcion del codigo 
           
        if(personaje->getPosicion()==cuarto4){
            if(personaje->buscaItemR("Llave carro")){
                salio = true;
            }
            else{
                personaje->setPosicion(cuarto4);
            }
        }
     return salio;
    }
