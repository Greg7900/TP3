#include "clients.h"


namespace clients {
    Clients::Clients(std::string firstname, std::string lastname, std::string ID) : _firstname(firstname), _lastname(lastname), _ID(ID){
    }



//Getter
    std::string Clients::getFirstname() const {
        return _firstname;
    }

    std::string Clients::getLastname() const {
        return _lastname;
    }

    std::string Clients::getID() const {
        return _ID;
    }
    std::vector<panier::Panier> Clients::getCart()const{
    	return _cart;
    }

	std::string display(Clients c) {
    return c.Getfirstname() + " " + c.Getlastname() + " " +c.GetID();
	}

    std::ostream& operator << (std::ostream& os,const Clients &clients) {
        os << clients.Getfirstname() + " " + clients.Getlastname() + " " +clients.GetID() <<std::endl;
        int i=1;
        os<< "client cart : \n"<<std::endl;
  		for (auto number : _cart){
    	os << number << " "<< std::endl;
   	 	i++;
  		}
  
  return os;
    }



//Setter
	void Clients::setFirstname(std::string firstname){
	_firstname = firstname;
	}

    void Clients::setLastname(std::string lastname){
	_lastname = lastname;
	}

	void Clients::setID(std::string ID){
	_ID = ID;
	}
	void setCart(magasin::Product product){
    	getcart().pushBack(produit);
    }
    void deleteProduct(magasin::Product product){
    	auto it=findProduct(product,_cart);
    	if(!it=_panier.end())
    	{
    		_panier.erase(it);
    	}else{std::cout<< " Product not found "<<std::endl;}
    }
   
}