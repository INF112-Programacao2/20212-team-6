#pragma once
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
class Db_sys
{
	public:
		static int salvar(std::string arq, std::string cont);
		static std::string ler(std::string arq, int f_size);
	
	

	private:

	protected:
		static int cy;

};

