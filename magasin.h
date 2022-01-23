#ifndef MAGASIN_H
#define MAGASIN_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "produit.h"
#include "client.h"
#include "commande.h"

namespace magasin
{
	class Magasin
	{
	public : 
	    Magasin();
	    void addProduct (); // 3a
	    void displayAllProducts() ; //3b
	    void displayProduct() ; //3c
	    void updateProductQuantity(); // 3d
		void addClient(); //5a
		void displayAllClients(); //5b
		void displayClients(); //5c
		void addProductToClient(); //5d
		void delProductToClient(); //5e
		void updateProductQuantityToClient();//5f
		void checkOrder();// 7a
		void displayAllOrders(); //7c
		void displayClientOrders();//7d
	    std::vector<magasin::Order> getOrders()const;
	    std::vector<magasin::Product> getProducs()const;
		std::vector<clients::Clients> getClients()const;
		
	private:
		
		std::vector<magasin::Product> _products;
		std::vector<clients::Clients> _clients;
		std::vector<magasin::Order> _orders;
	};
	void status(); //7b
	

}
#endif
