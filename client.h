#ifndef CLIENTS_H
#define CLIENTS_H
#include <iostream>

	namespace clients {
	class Clients{


	public:

		Clients(std::string firstname, std::string lastname, std::string ID)

			std::string getFirstname() const;  
			std::string getLastname() const;
			std::string getID() const;
			std::vector<panier::Panier> getCart()const;

		void setFirstname(std::string firstname);
		void setLastname(std::string lastname);
		void setID(std::string ID);
		void setCart(magasin::Product product);
		void clearPanier();
		void deleteProduct(magasin::Product product);


	private:

			std::string _firstname;
			std::string _lastname;
			std::string _ID;
			std::vector<panier::Panier> _cart;

	};

			std::string getFullName(const Clients &p);
			std::ostream& operator << (std::ostream& os,const Clients &clients);
			std::string display(Clients c);

}
#endif