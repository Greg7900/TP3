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

        auto quantMax=product.quantity();
        product.setQuantity(Quantity);
        auto it=magasin::findProduct(product.title(),_cart); // si le produit est deja dans le panier on additionne les quantités
        if(it !=_cart.end()){
            (*it)=(*it)+product;
            if(((*it).quantity()>quantMax)){
                std::cout << "Quantity max exceeded, the product quantity will be set as quantity max\n";
                (*it).setQuantity(quantMax);
            }

        }else{
            _cart.push_back(product);
        }

        
    }
    void Clients::clearCart(){ //4c
        _cart.clear();
    }
    
    void Clients::updateClientProductQuantity(int newQuantity,std::string title, int quantMax){ // 4d

        auto it=findProduct(title,_cart);
        if(it!=_cart.end())
        {
          if(newQuantity<=quantMax){
              (*it).setQuantity(newQuantity); 
          }else{
            std::cout<< " Quantity unchanged because of availability \n";
        }
    }else{std::cout<< " Product not found in client cart \n"<<std::endl;
}
} 


    void Clients::deleteCartProduct(std::string idProduct){  // 4e

        auto it=findProduct(idProduct,_cart);
        if(it!=_cart.end())
        {
          _cart.erase(it);
      }else{std::cout<< " Product not found "<<std::endl;}
  }
  void displayCart( Clients &clients){
    std::cout << "-------------------------------------------Client cart-----------------------------------------------\n\n";
    for (auto number : clients.getCart()){
        std::cout << number << " "<< std::endl;
    }std::cout << "-----------------------------------------------------------------------------------------------------\n\n";

}
    std::ostream& operator << (std::ostream& os,const Clients &clients) { // 4f

        os << "--> Firstname : "+ clients.getFirstname() + " | Lastname : " + clients.getLastname() + " | ID : " +clients.getID() +"\n" ;
        os<< " Client cart : \n"<<std::endl;
        for (auto number : clients.getCart()){
            os << number << " "<< std::endl;
        }

        return os;
    }
    std::vector<clients::Clients>::iterator findClient( const std::string idClient, std::vector<clients::Clients>& vectorC)
    {
        auto it = std::find_if(vectorC.begin(),vectorC.end(),[idClient](const clients::Clients& client) {return idClient==(client.getID());});
        return it; 
    }


}