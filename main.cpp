#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Pedido.h"
#include "Usuario.h"



int teste_db()
{
    //Exemplo de funcionamento da "database"


    const int size = 3;
    //Para encher espaco
    Usuario ni = Usuario("Ninguem", 0);

    //Usuarios a serem copiados
    Usuario admin = Usuario("Admin", 1234);
    Usuario jo = Usuario("Joao", 9223);
    Usuario ma = Usuario("Ma", 5782);

    
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

    //Eh criado um ofstream para salvar o arquivo
    std::ofstream wf("users.dat", std::ios::out | std::ios::binary);
    if (!wf) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }
    wf.write(escrever.c_str(), sizeof(escrever));
    wf.close();

    // A partir dai, existe um arquivo codifcado em binario com a string com as informacoes dos usuarios


    //Cria se uma ifstream para ler o arquivo
    std::ifstream rf("users.dat", std::ios::out | std::ios::binary);
    if (!rf) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }

    //Leia o arquivo que escrevemos
    rf.read(buf, sizeof(escrever));
    rf.close();
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
        Lista_fin[c] = Usuario(nm,std::stoi(cf));
        
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

    return 0;
}
