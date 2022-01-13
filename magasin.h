#ifndef MAGASIN_H
#define MAGASIN_H
#include <iostream>
#include <vector>

#include "produit.h"
#include "client.h"

namespace magasin
{
	class Magasin
	{
	public : 
	    Magasin();
	    void displayProduct();
	    void addProduct (magasin::Product product);
	private:
		
		std::vector<magasin::Product> _products;
		std::vector<clients::Clients> _clients;
		std::vector<magasin::Order> _orders;
	};

	std::ostream &operator<<(std::ostream &os, const Magasin &magasin);


}
#endif
