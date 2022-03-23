#pragma once
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Db_sys.h"

int Db_sys::cy = 13;

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
        std::cout << "Cannot open file1!" << std::endl;
        return 1;
    }
    wf.write(cont.c_str(), cont.size());
    wf.close();
}

std::string Db_sys::ler(std::string arq, int f_size)
{
    int cx = 0;
    char cq = 0;
    std::string valx = "";
    std::string val = "";
   
    std::ifstream rf(arq + ".dat", std::ios::in | std::ios::binary);
    if (!rf) {
        std::cout << "Cannot open file!" << std::endl;
        
    }
    std::getline(rf,val);
   
    //std::cout << "cy " << cy << std::endl;

    for (int c = 0;c < val.length();c++)
    {
        val[c] -= cy;
    }

    

    


    return val;
}
