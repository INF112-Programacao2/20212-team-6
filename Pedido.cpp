#include <iostream>
#include <cstring>
#include  <algorithm>
#include <fstream>
#include <string>
#include <exception>
#include "Pedido.h"
#include "Produto.h"
#include "Estoque.h"

int Pedido::ph_id = -8192;
Pedido::Pedido()
{
	//std::cout << sizeof(quantidade) << std::endl;
	for (int x = 0;x < size;x++)
	{
		quantidade[x] = 0;
		carrinho[x] = Produto(ph_id, 0,199);

	}
	p_size = 0;



}

void Pedido::add_produto(Produto& p)
{
	p.setEmEstoque();
	if (p.getEmEstoque() == true)
	{
		for (int x = 0;x < size;x++)
		{
			if (carrinho[x].getID() == p.getID())
			{
				quantidade[x] ++;
				break;
			}
			if (carrinho[x].getID() == Pedido::ph_id)
			{
				carrinho[x] = p;
				quantidade[x] = 1;
				p_size++;
				break;
			}
		}
		
	}
	Estoque::setQtdDeProdutos(1, 2);
	Estoque::setValorTotalDoEstoque(1,p.getPreco(),2);
}

double Pedido::valor_total()
{
	double res = 0;
	for (int x = 0;x < size;x++)
	{
		//std::cout << "$: " << carrinho[x].getPreco() << " x" << quantidade[x] << std::endl;
		res += (carrinho[x].getPreco() * quantidade[x]);
	}



	return res;
}


void Pedido::limpar_carrinho()
{
	for (int x = 0;x < p_size;x++)
	{
		quantidade[x] = 0;
		carrinho[x] = Produto(ph_id, 0, 199);

	}
}

int Pedido::remover_item(std::string in)
{
	int inx = -1;
	std::string nm = "";

	try {
		inx = std::stoi(in);
	}
	catch (std::invalid_argument e)
	{
		nm = in;
	}
	//std::cout << inx << std::endl;
	inx--;
	if (inx >= 0)
	{
		
		if (inx > p_size -1)
		{
			std::cout << "\x1b[0;91m Valor maior que o numero de produtos no carrinho\x1b[0m" << std::endl;
			return 1;
		}

		quantidade[inx] = 0;
		carrinho[inx] = Produto(ph_id, 0, 199);

		if (inx != p_size - 1)
		{
			Produto temp[100];
			int temp_q[100] = {};
			int idx=0;
			for (int c = 0;c < p_size;c++)
			{
				if (carrinho[c].getID() != ph_id)
				{
					temp[idx] = carrinho[c];
					temp_q[idx] = quantidade[c];
					idx++;

				}
			}
			limpar_carrinho();
			for (int d = 0;d < idx;d++)
			{
				//add_produto(temp[d]);
				carrinho[d] = temp[d];
				quantidade[d] = temp_q[d];
				Estoque::setQtdDeProdutos(1, 1);
				Estoque::setValorTotalDoEstoque(1, carrinho[d].getPreco(), 1);
			}

		}



		
	    p_size--;
		return 0;
	}

	else {
		std::cout << "\x1b[0;91mValor eh zero ou menor\x1b[0m" << std::endl;
		return 2;
	}

	return 4;
}


void Pedido::listar_produtos()
{
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
	for (int c = 0;c < p_size;c++)
	{
		std::cout << c+1 << "- " << carrinho[c].getDescricao() << " R$" << carrinho[c].getPreco() << " x" << quantidade[c] << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << std::endl;
}

Pedido::~Pedido()
{
	
}
