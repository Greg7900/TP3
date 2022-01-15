#include "commande.h"

namespace magasin{
		Order::Order(clients::Clients client1): _client1(client1){}
		
		clients::Clients Order::client(){
			return _client1;
		}
		std::vector<magasin::Product> Order::cart(){
			return _cart;
		}
		std::string Order::status(){
			return _status;
		}

	std::ostream &operator<<(std::ostream &os, Order& order){
		os << order.client();
        os<< "client cart : \n"<<std::endl;
        for (auto number : order.cart()){
        os << number << " "<< std::endl;
        }
  
  return os;
	}

}