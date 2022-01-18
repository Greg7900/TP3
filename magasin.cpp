
#include "magasin.h"
namespace magasin{



	Magasin::Magasin(){}
	
	void Magasin::addProduct(){  // 3a
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		std::string title,description;
		int quantity;
		double price;
		std::cout<< " Enter product name : " ;
      	std::cin>> title;
      	std::cout<< " Enter product description : " ;
      	std::cin>> description;
		std::cout<< " Enter product quantity : " ;
      	std::cin>> quantity;
      	std::cout<< " Enter product price : " ;
      	std::cin>> price;
      	magasin::Product prod(title,description,quantity,price);
		_products.push_back(prod);
	}

	void Magasin::displayAllProducts() { //3b
		std::cout << "\033[2J\033[1;1H"; //clear terminal2

		for(auto it=_products.begin(); it!=_products.end();it++){
         std::cout<<*it<<std::endl;
      }
	}
	void Magasin::displayProduct() { //3c
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		std::string title;
		std::cout<< " Enter product title : " ;
      	std::cin>> title;
		auto it=magasin::findProduct(title,_products);
		if(it !=_products.end()){
			std::cout<<*it;
		}else{ std::cout<<" Product not found ! \n";
		}
	}
	void Magasin::updateProductQuantity(){ // 3d
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		int newQuantity;
		std::cout<< " Enter product new quantity : " ;
      	std::cin>> newQuantity;
		std::string title;
		std::cout<< " Enter product title : " ;
      	std::cin>> title;
		auto it=magasin::findProduct(title,_products);
		if(it !=_products.end()){
			(*it).setQuantity(newQuantity);
		}else{ std::cout<<" Product not found ! \n";
		}
	}
	void Magasin::addClient(){ //5a
		  std::cout << "\033[2J\033[1;1H"; //clear terminal
		  std::string nom, prenon, idClient;
		  std::cout << std::endl;
		  std::cout<< " Enter Customer firstname : " ;
		  std::cin>> prenon;
		  std::cout<< " Enter Customer lastname : " ;
		  std::cin>> nom;
		  std::cout<< " Enter Customer ID : " ;
		  std::cin>> idClient;
		  clients::Clients client(prenon, nom, idClient);
		_clients.push_back(client);
	}
	void Magasin::displayAllClients(){ //5b
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		for(auto it=_clients.begin(); it!=_clients.end();it++){
         std::cout<<*it<<std::endl;
      }
	} 
	void Magasin::displayClients() { //5c
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		int flag=1;
		std::string idClient;
      	std::cout<< " Enter Customer ID or name : " ;
      	std::cin>> idClient;
      	for(auto it=_clients.begin();it!=_clients.end();it++){
        if( (*it).getID()==idClient ){
          flag=0;
          std::cout<<(*it);
        }else if((*it).getLastname()==idClient){
          flag=0;
          std::cout<<(*it);
         }
      }if(flag==1){
			std::cout <<"product not found";
      	}
	}
	void Magasin::addProductToClient(){ //5d
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		std::string idClient;
		int Quantity,num;
		int i=1;
  		std::cout<< "------------------------------------------------Liste des produits---------------------------------------------"<<std::endl;
  		for (auto number : _products){
    	std::cout<< "Produit numero "<<i<<":"<<std::endl;
    	std::cout<< number << " "<< std::endl;
    	i++;
  		}
  		std::cout<< "-----------------------------------------------------------------------------------------------------------------"<<std::endl;

  		std::cout<< " Choose a product number : ";
  		std::cin>> num;
  		if(!( (num>=1) && (num <=i) )){
  			std::cout<< " the product doesn't exist' "<<std::endl;
  			std::cin>> num;
  		}
  		magasin::Product prod = _products.at(num-1);
  		std::cout<< "--------------------------------------------------------Fin--------------------------------------------------------"<<std::endl;
      	std::cout<< " Enter Customer ID or name : " ;
      	std::cin>> idClient;
		std::cout<< " Enter product quantity : " ;
      	std::cin>> Quantity;
      	for(auto it=_clients.begin();it!=_clients.end();it++){
	        if((*it).getID()==idClient){
	          (*it).setCart(prod,Quantity);
	        }else if((*it).getLastname()==idClient){
	          (*it).setCart(prod,Quantity);
	         }
      	}
	}
	void Magasin::delProductToClient(){ //5e
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		int flag=1;
		std::string idClient,idProduct;
      	std::cout<< " Enter Customer ID or name : " ;
      	std::cin>> idClient;
      	std::cout<< " Enter product title : " ;
      	std::cin>> idProduct;
      	for(auto it=_clients.begin();it!=_clients.end();it++){
	        if((*it).getID()==idClient){
	          flag=0;
	          (*it).deleteCartProduct(idProduct);
	          std::cout<<"product deleted successfully";
	        }else if((*it).getLastname()==idClient){
	          flag=0;
	          (*it).deleteCartProduct(idProduct);
	          std::cout<<"product deleted successfully";
	         }
      	}if(flag==1){
			std::cout <<"product not found";
      	}
	}
	void Magasin::updateProductQuantityToClient(){ //5f
	std::cout << "\033[2J\033[1;1H"; //clear terminal
	std::string idClient,idProduct;
	int newQuantity;
  	std::cout<< " Enter Customer ID or name : " ;
  	std::cin>> idClient;
  	std::cout<< " Enter product title : " ;
    std::cin>> idProduct;
  	std::cout<< " Enter product new quantity : " ;
  	std::cin>> newQuantity;
  	for(auto it=_clients.begin();it!=_clients.end();it++){
        if((*it).getID()==idClient){
          (*it).updateClientProductQuantity(newQuantity,idProduct);
        }else if((*it).getLastname()==idClient){
          (*it).updateClientProductQuantity(newQuantity,idProduct);
         }
  	}
  	
  	
	}
	void Magasin::checkOrder(){ //7a
		std::string idClient;
		int flag=1;
      	std::cout<< " Enter Customer ID or name to check : " ;
      	std::cin>> idClient;
      	for(auto it=_clients.begin();it!=_clients.end();it++){
	        if(  ( (*it).getID()==idClient ) ){
	          	flag=0;
	          	for(long unsigned int i=1 ; i<=((*it).getCart()).size();i++){
	          			auto test= (*it).getCart();
	          			auto it1=magasin::findProduct(,_products);
			  			if(it1 !=_products.end()){
			     			if((*it1).quantity()<=test.quantity()){
			     				magasin::order order((*it),(*it).getCart(),"ok");
			     			}else{
			     				std::cout<< "quantity not available";
			     			}
						}
				}
			}else if((*it).getLastname()==idClient){
	          flag=0;
	          (*it).
	         }
      	}
      }
      	if(flag==1){
			std::cout <<"product not found";
      	}
  	}



}