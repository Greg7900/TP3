
#include "magasin.h"
namespace magasin{



	Magasin::Magasin(){}
	
	void Magasin::addProduct(){  // 3a
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
		std::cout<< " Enter product price : " ;
		std::cout<<_products.size();
		
		for(auto it=_products.begin(); it!=_products.end();it++){
         std::cout<<*it<<std::endl;
      }
	}
	void Magasin::displayProduct() { //3c
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
		for(auto it=_clients.begin(); it!=_clients.end();it++){
         std::cout<<*it<<std::endl;
      }
	} 
	void Magasin::displayClients() { //5c
		std::string idClient;
      	std::cout<< " Enter Customer ID or name : " ;
      	std::cin>> idClient;
      	for(auto it=_clients.begin();it!=_clients.end();it++){
        if((*it).getID()==idClient){
          std::cout<<(*it);
        }else if((*it).getLastname()==idClient){
          std::cout<<(*it);
         }
      }
	}
	void Magasin::addProductToClient(){ //5d
		std::string idClient;
		int Quantity,num;
		int i=1;
  		std::cout<< "------------------------------------------------Liste des produits---------------------------------------------"<<std::endl;
  		for (auto number : _products){
    	std::cout<< "Produit numero "<<i<<":"<<std::endl;
    	std::cout<< number << " "<< std::endl;
    	i++;
  		}
  		std::cout<< " Choose a product number : ";
  		std::cin>> num;
  		magasin::Product prod = _products.at(num);
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
		std::string idClient,idProduct;
      	std::cout<< " Enter Customer ID or name : " ;
      	std::cin>> idClient;
      	std::cout<< " Enter product title : " ;
      	std::cin>> idProduct;
      	for(auto it=_clients.begin();it!=_clients.end();it++){
	        if((*it).getID()==idClient){
	          (*it).deleteCartProduct(idProduct);
	        }else if((*it).getLastname()==idClient){
	          (*it).deleteCartProduct(idProduct);
	         }
      	}
	}
	void Magasin::updateProductQuantityToClient(){ //5f
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

  	}



}