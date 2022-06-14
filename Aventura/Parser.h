#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "ListaPalabras.h"
#include <sstream>

class Parser {
    public:
        Parser();
        Parser(ListaPalabras*);
        ListaPalabras* getComandos();
        Comando* generaComando();
    private:
        ListaPalabras* comandos;
};


#endif //PARSER_H