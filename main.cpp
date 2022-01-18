#include "magasin.h"

void magManagement(magasin::Magasin& mag ){
	std::cout << "\033[2J\033[1;1H"; //clear terminal
  int choix;
    std::cout<< "---------------------------------------------Store Management ----------------------------------------------"<<std::endl<<std::endl;
    std::cout<< " Enter an action ! " <<std::endl<<" Add product : 1"<<std::endl<<" Update product quantity: 2 "<<std::endl<<" displayAllProducts : 3 "<<std::endl<<" display a Products : 4 "<<std::endl;
    std::cin>>choix;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      mag.addProduct();
      break;
      case 2 :
      mag.updateProductQuantity();
      break;
      case 3 :
      mag.displayAllProducts();
      break;
      case 4 :
      mag.displayProduct();
      break;
      default :
      std::cout<<" action number "<<choix<< " doesn't exist"<<std::endl;
      break;
}
}
void userManagement(magasin::Magasin& mag ){
  std::cout << "\033[2J\033[1;1H"; //clear terminal
  int choix;
    std::cout<< "---------------------------------------------Store Management ----------------------------------------------"<<std::endl<<std::endl;
    std::cout<< " Enter an action ! " <<std::endl<<" Add a client : 1"<<std::endl;
    std::cout<< " Display a client : 2 " <<std::endl<< " Display all client : 3" <<std::endl;
    std::cout<< " Add a product to the client cart : 4 " <<std::endl<< " Delete a product from the client cart: 5 " <<std::endl;
     std::cout<< " Update product quantity in a client cart : 6 " <<std::endl;
    std::cin>>choix;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      mag.addClient();
      break;
      case 2 :
      mag.displayClients();
      break;
      case 3 :
      mag.displayAllClients();
      break;
      case 4 :
      mag.addProductToClient();
      break;
      case 5 : 
      mag.delProductToClient();
      break;
      case 6 :
      mag.updateProductQuantityToClient();
      break;
      default :
      std::cout<<" action number "<<choix<< " doesn't exist"<<std::endl;
      break;
}
}
void orderManagement(magasin::Magasin& mag ){
  std::cout << "\033[2J\033[1;1H"; //clear terminal
  int choix;
    std::cout<< "---------------------------------------------Store Management ----------------------------------------------"<<std::endl<<std::endl;
    std::cout<< " Enter an action ! " <<std::endl<<" Add a client : 1"<<std::endl;
    std::cout<< " Display a client : 2 " <<std::endl<< " Display all client : 4 " <<std::endl;
    std::cout<< " Add a product to the client cart : 5 " <<std::endl<< " Delete a product from the client cart: 6 " <<std::endl;
     std::cout<< " Update product quantity in a client cart : 9 " <<std::endl;
    std::cin>>choix;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      mag.addClient();
      break;
      case 2 :
      mag.displayClients();
      break;
      case 3 :
      mag.displayAllClients();
      break;
      case 4 :
      mag.addProductToClient();
      break;
      case 5 : 
      mag.delProductToClient();
      break;
      case 6 :
      mag.updateProductQuantityToClient();
      break;
      default :
      std::cout<<" action number "<<choix<< " doesn't exist"<<std::endl;
      break;
}
}

int main(int argc, char const *argv[]) {


magasin::Magasin mag;
while (1) {
	int choix;
    std::cout<< "---------------------------------------------Menu---------------------------------------------"<<std::endl<<std::endl;
    std::cout<< " Enter an action ! " <<std::endl<<" Store management : 1"<<std::endl<<" Users management: 2 "<<std::endl<<" Orders management : 3 "<<std::endl;
    
    std::cin>>choix;
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      magManagement(mag);
      break;
      case 2 :
      userManagement(mag);
      break;
      case 3 :
      orderManagement(mag);
      break;
      
      default :
      choix=0;
      break;

 
   }
}
return 0;
}