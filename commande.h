#ifndef COMMANDE_H
#define COMMANDE_H
#include <iostream>
#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"
namespace magasin
{
	class Order
	{

	public:
		Order(clients::Clients client1);
		clients::Clients client();
		std::vector<magasin::Product> cart();
		std::string status();

	private:
		clients::Clients _client1;
		std::vector<magasin::Product> _cart;
		
		std::string _status;
	};
	std::ostream &operator<<(std::ostream &os,  Order& order);
}
#endif