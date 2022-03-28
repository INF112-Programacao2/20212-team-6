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
            if (menuPrincipal(isAdmin))
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
        Administrador ad = Administrador("admin", 12, 0);
        ad.menuAdm();
    }
    else {
        std::string nome, endereco;
        long long int telefone = -1, cpf = -1;
        std::string cf="", tl = "";
        //Fornece as informacoes para criacao do cliente
        std::cout << "\tVamos completar o seu cadastro\n";
        std::cout << "\tPara comecar, digite seu nome completo:\n";
        std::cin.ignore();
        getline(std::cin, nome);
        while (cpf == -1)
        {
            std::cout << "\tDigite seu cpf: (somente numeros)\n";
            std::cin >> cf;
            try
            {
                cpf = std::stoll(cf);
            }
            catch (std::invalid_argument e)
            {
                std::cout << "Cpf invalido" << std::endl;
            }
            
            
        }
        std::cout << "\tDigite seu endereco e aperte 'enter' somente quando terminar: \n";
        std::cin.ignore();
        getline(std::cin, endereco);
        
        while (telefone == -1)
        {
            std::cout << "\tPara terminar, digite seu telefone: (somente numeros)\n";
            std::cin >> tl;
            try
            {
                telefone = std::stoll(tl);
            }
            catch (std::invalid_argument e)
            {
                std::cout << "Telefone invalido" << std::endl;
            }
        }

        Cliente ct = Cliente(nome, cpf, 0, endereco, telefone);
        //inicializa e le o estoque
        Estoque::Criar_arquivo_estoque();
        Estoque::Ler_arquivo_estoque();
        //Puxa o menu do cliente
        ct.menuDoCliente();
    }
    return 0;
}

