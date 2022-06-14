#ifndef COMANDO_H
#define COMANDO_H
#include <iostream>
class Comando{
    public:
        Comando();
        Comando(std::string, std::string);
        std::string getComando() const;
        std::string getSegPalabra() const;
        void setSegPalabra(std::string);
        bool desconocido();
        bool tieneSegPalabra();
        virtual void ejecuta() = 0;
    private:
        std::string comando;
        std::string segPalabra;
};


#endif //COMANDO_H