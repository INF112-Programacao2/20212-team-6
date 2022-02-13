#include <iostream>
#include <cstring>
#include  <algorithm>
#include <fstream>
#include "Pedido.h"
#include "Produto.h"

int Pedido::ph_id = -8192;
Pedido::Pedido()
{
	std::cout << sizeof(quantidade) << std::endl;
	for (int x = 0;x < size;x++)
	{
		quantidade[x] = 0;
		carrinho[x] = Produto(ph_id, 0,199);

	}



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
				break;
			}
		}
		
	}
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

Pedido::~Pedido()
{

}
