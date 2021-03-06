#ifndef CLIENTS_H
#define CLIENTS_H

#include "produit.h"
namespace clients
{
	class Clients
	{

	public:
		Clients(std::string firstname, std::string lastname, std::string ID);

		std::string getFirstname() const;
		std::string getLastname() const;
		std::string getID() const;
		std::vector<magasin::Product> getCart() const; // 4a

		void setFirstname(std::string firstname);
		void setLastname(std::string lastname);
		void setID(std::string ID);
		void setCart(magasin::Product product,int Quantity); //4b
		void clearCart(); //4c
		void updateClientProductQuantity(int newQuantity,std::string title,int quantMax);// 4d
		void deleteCartProduct(std::string idProduct); //4e

	private:
		std::string _firstname;
		std::string _lastname;
		std::string _ID;
		std::vector<magasin::Product> _cart;
	};
	void displayCart( Clients &clients);
	std::ostream &operator<<(std::ostream &os, const Clients &clients);
std::vector<clients::Clients>::iterator findClient(const  std::string idClient, std::vector<clients::Clients>& vectorC);

}
#endif