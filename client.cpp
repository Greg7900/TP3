#include "client.h"



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
    std::vector<magasin::Product>Clients::getCart() const{
    	return _cart;
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


	void Clients::setCart(magasin::Product product,int Quantity){  // 4b
    	if(Quantity==0){}else{
        product.setQuantity(Quantity);
        _cart.push_back(product);}
    }
    void Clients::clearCart(){ //4c
        _cart.clear();
    }
    
    void Clients::updateClientProductQuantity(int newQuantity,std::string title){ // 4d
       
        auto it=findProduct(title,_cart);
        if(it!=_cart.end())
        {
          (*it).setQuantity(newQuantity);  
        }else{std::cout<< " Product not found "<<std::endl;}
    }
   

    void Clients::deleteCartProduct(std::string idProduct){  // 4e

        auto it=findProduct(idProduct,_cart);
    	if(it!=_cart.end())
    	{
    		_cart.erase(it);
    	}else{std::cout<< " Product not found "<<std::endl;}
    }
   
    std::ostream& operator << (std::ostream& os,const Clients &clients) { // 4f
        
        os << clients.getFirstname() + " " + clients.getLastname() + " " +clients.getID() <<std::endl;
        os<< "client cart : \n"<<std::endl;
        for (auto number : clients.getCart()){
        os << number << " "<< std::endl;
        }
  
  return os;
    }



}