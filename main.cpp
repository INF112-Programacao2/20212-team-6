
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Pedido.h"
#include "Usuario.h"
#include "Db_sys.h"

int teste_db()
{
    //Exemplo de funcionamento da "database"


    const int size = 3;
    //Para encher espaco
    Usuario ni = Usuario("Ninguem", 0,0);

    //Usuarios a serem copiados
    Usuario admin = Usuario("Admin", 1234,1);
    Usuario jo = Usuario("Joao", 9223,2);
    Usuario ma = Usuario("Ma", 5782,3);

    
    Usuario lista_ini[size] = { admin,jo,ma };
    Usuario Lista_fin[size] = {ni,ni,ni};

    //Lista para valores temporarios
    std::string qx[size];
   
    

    std::string escrever = "";

    //Buffer


    char buf[sizeof(escrever)];
    char t = 't';
    


    //Para salvar os usuarios, suas informacoes sao primeiro transfroamdas para uma string, '|' delimita o nome e cpf, '%' delimita diferentes usuarios

    for (int c = 0;c < size;c++)
    {
        escrever += lista_ini[c].get_nome() + "|" + "1234" + "%";
    }

    Db_sys::salvar("users",escrever);
    

    std::string b = Db_sys::ler("users", sizeof(escrever));
    for (int d = 0;d < sizeof(b);d++)
    {
        buf[d] = b[d];
    }

    // A partir dai, existe um arquivo codifcado em binario com a string com as informacoes dos usuarios


    //Cria se uma ifstream para ler o arquivo
  
    char* tk;

    //Separar os usuarios contidos na string com a funcao strtok_s
    qx[0] = strtok_s(buf, "%", &tk);
    for (int c = 1;c < size;c++)
    {
        
        qx[c] = strtok_s(NULL, "%", &tk);
    }

    

    std::string nm = "";
    std::string cf = "";

    //Usando as informacoes das strings, e possivel recriar os usuarios
    char tem[100];
    for (int c = 0;c < size;c++)
    {
        

        qx[c].copy(tem,qx[c].size()+1);
        tem[qx[c].size()] = '\0';
        nm = strtok_s(tem, "|", &tk);
        cf = strtok_s(NULL, "|", &tk);
        Lista_fin[c] = Usuario(nm,std::stoi(cf),1);
        
    }


    std::cout << "Primeiro usuario: " << (std::string)lista_ini[0].get_nome() << std::endl;
    std::cout << "Segundo usuario: " << (std::string)lista_ini[1].get_nome() << std::endl;
    std::cout << "Terceiro usuario: " << (std::string)lista_ini[2].get_nome() << std::endl;


    std::cout << std::endl;
    
    std::cout << "Primeiro usuario: " << (std::string)Lista_fin[0].get_nome() << std::endl;
    std::cout << "Segundo usuario: " << (std::string)Lista_fin[1].get_nome() << std::endl;
    std::cout << "Terceiro usuario: " << (std::string)Lista_fin[2].get_nome() << std::endl;

    

    return 0;

}

int main()
{
    //Início do programa
    //chama a função de Menu Principal enquanto o login não for concedido.
    imprimeASCII();
    try{
        while(true){
            if(menuPrincipal())
                break;
        }
    }
    catch(std::invalid_argument &e){
        std::cout << e.what();
        return 1;
    }
    //Funcionamento geral do programa.
    std::string q;
    std::ifstream rf("users.dat", std::ios::out | std::ios::binary);
    if (!rf) {
        std::cout << "\x1b[s" << '\r';
        
        std::cout << "Registro de usuario nao encontrado, criando registro padrao" << std::endl;
        std::string df_user = "Admin|12345|0";
        Db_sys::salvar("users", df_user);
        
        system("PAUSE");
        std::cout << "\x1b[2J" << std::endl;
        std::cout << "\x1b[u";
        

    }
    rf.close();
    
    
    system("PAUSE");
    
    
   


    return 0;
}


