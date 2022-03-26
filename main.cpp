#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include "includes.h"
#include "Administrador.h"
#include "Cliente.h"
#include <locale.h>


int main()
{
   
    std::cout << "\x1b[1;7m" << '\r';
    system("clear");
    bool isAdmin = false;
    //Início do programa
    //chama a função de Menu Principal enquanto o login não for concedido.
    imprimeASCII();
    try {
        while (true) {
            if (menuPrincipal(isAdmin));
                break;
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        return 1;
    }
    if (isAdmin) {
        
        Estoque::Criar_arquivo_estoque();
        Estoque::Ler_arquivo_estoque();
        Administrador ad = Administrador("admin",12,0);
        ad.menuAdm();
    }
    else {
        Cliente ct = Cliente("cliente",12,0,"",1);
        Estoque::Criar_arquivo_estoque();
        Estoque::Ler_arquivo_estoque();
        ct.menuDoCliente();
    }
    return 0;
}


