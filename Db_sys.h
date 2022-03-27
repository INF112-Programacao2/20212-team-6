#ifndef DB_SYS_H
#define DB_SYS_H
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
		static int add_salvar(std::string arq, std::string cont);
	
	

	private:

	protected:
		static int cy;

};

#endif