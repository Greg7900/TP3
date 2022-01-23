
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
		std::cout<< "------------------------------------------------Liste des produits---------------------------------------------\n";
		for(auto it=_products.begin(); it!=_products.end();it++){
			std::cout<<*it<<std::endl;
		}  std::cout<< "-----------------------------------------------------------------------------------------------------------------\n";

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
			if( ((*it).getID()==idClient) || ( (*it).getLastname()==idClient )){
				flag=0;
				std::cout<<(*it);
			}
		}if(flag==1){
			std::cout <<"client not found \n";
		}
	}
	void Magasin::addProductToClient(){ //5d
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		std::string idClient;
		int Quantity,num;
		int i=1 ,flag=1;
		std::cout<< "------------------------------------------------Liste des produits----------------------------------------------\n";
		for (auto number : _products){
			std::cout<< "Produit numero "<<i<<": \n";
			std::cout<< number << " \n";
			i++;
		}
		std::cout<< "-----------------------------------------------------------------------------------------------------------------\n";
		if(_products.size()>0){ // pour voir s'il y a des produits a ajouter 
			std::cout<< " Choose a product number : ";
			std::cin>> num;
			if(!( (num>=1) && (num <=i) )){
				std::cout<< " the product doesn't exist \n";
				std::cout<< " Choose a product number : ";
				std::cin>> num;
			}
			magasin::Product prod = _products.at(num-1);
			std::cout<< " Enter Customer ID or lastname : " ;
			std::cin>> idClient;
			std::cout<< " Enter product quantity : " ;
			std::cin>> Quantity;
		    while(Quantity>prod.quantity() || Quantity<=0){ // verification de la quantité dispo
		      	std::cout<< " Quantity unavailable \n";
		      	std::cout<< " Enter product quantity : " ;
		      	std::cin >> Quantity;
		    }
		    for(auto it=_clients.begin();it!=_clients.end();it++){
		      	if( ((*it).getID()==idClient) || ( (*it).getLastname()==idClient )){
		      		flag=0;
		      		(*it).setCart(prod,Quantity);
		      	}
		      	}
		      	if(flag==1)
		      	{
		      		std::cout <<"client not found \n";
		      	}
	      }else{
	      	std::cout <<" No product to add \n";
	      }
	}
	void Magasin::delProductToClient(){ //5e
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		int flag=1;
		std::string idClient,idProduct;
		std::cout<< " Enter Customer ID or lastname : " ;
		std::cin>> idClient;
		
		for(auto it=_clients.begin();it!=_clients.end();it++){
			if( ((*it).getID()==idClient) || ( (*it).getLastname()==idClient )){
				flag=0;
				displayCart((*it));
				std::cout<< " Enter product title : " ;
				std::cin>> idProduct;
				(*it).deleteCartProduct(idProduct);
				std::cout<<"product deleted successfully \n";
			}
		}if(flag==1){
			std::cout <<"client not found \n";
		}
	}
	void Magasin::updateProductQuantityToClient(){ //5f
	std::cout << "\033[2J\033[1;1H"; //clear terminal
	std::string idClient,idProduct;
	int newQuantity,quantMax;
	std::cout<< " Enter Customer ID : " ;
	std::cin>> idClient;
	auto it=clients::findClient(idClient,_clients); // on cherche le client choisie
	if(it!=_clients.end()){ // et s'il est trouver on fait ca
			displayCart((*it)); // afficher le panier pour faciliter la saisie
			std::cout<< " Enter product title : " ;
			std::cin>> idProduct;
			auto it1=magasin::findProduct(idProduct,_products); // on cherche le produit dans le stock du magasin pour récuperer la quantité maximale 
			if(it1 !=_products.end()){

				quantMax=(*it1).quantity(); // 
				std::cout<< " Max quantity = "<<quantMax<<"\n";
				std::cout<< " Enter product new quantity : " ;
				std::cin>> newQuantity;
				(*it).updateClientProductQuantity(newQuantity,idProduct,quantMax);
			}else{
				std::cout<< " This product is not in cart";
			}

		
	}else{std::cout<<" Client not found \n";}
	}

	void status(magasin::Order& order){ // changement de status d'une commande après la validation
		order.updateStatus();
	}

	void Magasin::checkOrder(){ //7a
		std::string idClient;
		std::cout<< " Enter Customer ID to check : " ;
		std::cin>> idClient;
		int flag=0;
		auto it=clients::findClient(idClient,_clients);
		if(it!=_clients.end()){ // it iterateur client
				
				auto cart=(*it).getCart();
				for(long unsigned int i=1; i<=cart.size(); i++){
					magasin::Product prod =cart.at(i-1);
					auto it1=magasin::findProduct(prod,_products); // it1 iterateur produit magasin
					if(it1!=cart.end()){
						magasin::Order order((*it)); // création d'une commande
						status(order);   // changement de status de la commande
						_orders.push_back(order);   // envoie dans le vector _order de magasin
						(*it1)=((*it1)-prod);       // mise à jour quantité
						(*it).clearCart();
						flag=1;
						std::cout << "\033[2J\033[1;1H"; //clear terminal
						std::cout<< " Order has been validate and added \n";

					}
				}if(flag==0){  // si flag=0, if(it1!=cart.end()) non validité. j'utulise un flag pour éviter l'affichage en double
				std::cout << "\033[2J\033[1;1H"; //clear terminal;
				std::cout<< " Cart is empty, can't check the order \n";
			}
		}else{
			std::cout<<" Client not found\n";
		}
	}
		
	

	

  	void Magasin::displayAllOrders(){ //5b
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		std::cout<< "------------------------------------------------Orders list---------------------------------------------\n\n";
		for(auto it=_orders.begin();it!=_orders.end();it++){
			
			std::cout<<(*it)<<"\n";
		}std::cout<< "-------------------------------------------------------------------------------------------------------\n\n";
	}

	void Magasin::displayClientOrders(){ //5b
		std::cout << "\033[2J\033[1;1H"; //clear terminal
		std::string idClient;
		int flag=1;
		std::cout<< " Enter Customer ID  : " ;
		std::cin>> idClient;
		for(auto it=_orders.begin();it!=_orders.end();it++){

			if( (((*it).client()).getID()==idClient) || ( ((*it).client()).getLastname()==idClient )){
				flag=0;
				std::cout<<*it<<"\n";
			}
		}
		if(flag==1){
			std::cout <<"client not found";
		}
	}  

	std::vector<magasin::Order> Magasin::getOrders()const{
		return _orders;
	}
	
	std::vector<magasin::Product> Magasin::getProducs()const{
		return _products;
	}
	std::vector<clients::Clients> Magasin::getClients()const{
		return _clients;
	}

}