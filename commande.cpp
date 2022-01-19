#include "commande.h"

namespace magasin{
		Order::Order(clients::Clients client1): _client1(client1){
			_cart=_client1.getCart();
		}
		
		clients::Clients Order::client(){
			return _client1;
		}
		std::vector<magasin::Product> Order::cart(){
			return _cart;
		}
		std::string Order::status(){
			return _status;
		}
		void Order::updateStatus(){
			_status="valided";
		}
		void changeStatus(Order& order){
			order.updateStatus();
		}

	std::ostream &operator<<(std::ostream &os,  Order& order){
		os << order.client();
		os<< " Order status: " << order.status()<<std::endl;
        
  
  return os;
	}

}