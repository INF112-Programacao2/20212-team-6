#ifndef DB_SYS_H
#define DB_SYS_H


#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ios>
#include "Db_sys.h"

//Valor "chave" da cifra usada na string
int Db_sys::cy = 13;


//Escreve em um arquivo "arq.dat",cont e sobscreve
int Db_sys::salvar(std::string arq, std::string cont)
{
    
    //cont += "0";
    //cy = std::max(3, rand() % 15);

    for (int c = 0;c < cont.length();c++)
    {
        cont[c] += cy;
    }
    
    //std::cout << cy << std::endl;

    std::ofstream wf(arq + ".dat", std::ios::out | std::ios::binary);
    if (!wf) {
        std::cout << "Nao foi possivel criar o arquivo!" << std::endl;
        return 1;
    }
    wf.write(cont.c_str(), cont.size());
    wf.close();
    return 0;
}

//Escreve em um arquivo "arq.dat" cont, cont eh adicionado ao final do conteudo ja existente
int Db_sys::add_salvar(std::string arq, std::string cont)
{

    for (int c = 0;c < cont.length();c++)
    {
        cont[c] += cy;
    }

    std::ofstream sal;

    sal.open(arq + ".dat", std::ios_base::app);
    sal << cont;
    sal.close();
    return 0;
}


//Le o arquivo arq, e remove a cifra
std::string Db_sys::ler(std::string arq, int f_size=0)
{
    int cx = 0;
    char cq = 0;
    std::string valx = "";
    std::string val = "";
   
    std::ifstream rf(arq + ".dat", std::ios::in | std::ios::binary);
    if (!rf) {
        std::cout << "nao foi posivel abrir o arquivo!" << std::endl;
        
    }
    std::getline(rf,val);
   
    

    for (int c = 0;c < val.length();c++)
    {
        val[c] -= cy;
    }

    

    


    return val;
}
