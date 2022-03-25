#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include "includes.h"

int main()
{
    bool isAdmin = false;
    //Início do programa
    //chama a função de Menu Principal enquanto o login não for concedido.
    imprimeASCII();
    try{
        while(true){
            if(menuPrincipal(isAdmin))
                break;
        }
    }
    catch(std::invalid_argument &e){
        std::cout << e.what();
        return 1;
    }
    if(isAdmin){
        //std::cout << "Inclua as funções do admin aqui.\n";
    }
    else{
        //std::cout << "Somente um usuario normal.\n";
    }
    return 0;
}


