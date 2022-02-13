#pragma once
#include "produto.h"

class Pedido
{
	public:
		static const int size = 100;
		static int ph_id;
		Pedido();
		~Pedido();
		Produto carrinho[size];
		int quantidade[size];
		void add_produto(Produto& p);
		double valor_total();



	private:

};
