#include "magasin.h"

#include <iterator>
void magManagement(magasin::Magasin& mag ){
	std::cout << "\033[2J\033[1;1H"; //clear terminal
  int choix;
    std::cout<< "---------------------------------------------Store Management ----------------------------------------------\n\n";
    std::cout<< " Enter an action ! \n" <<"   Add product : 1\n"<<"   Update product quantity: 2 \n"<<"   DisplayAllProducts : 3 \n"<<"   Display a Products : 4 \n\n";
    std::cin>>choix;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " You have chosen the number "<<choix<<"\n\n";
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
      std::cout<<" Action number "<<choix<< " doesn't exist"<<"\n";
      break;
}
}
void userManagement(magasin::Magasin& mag ){
  std::cout << "\033[2J\033[1;1H"; //clear terminal
  int choix;
    std::cout<< "---------------------------------------------User Management ----------------------------------------------\n\n";
    std::cout<< " Enter an action ! \n" <<"   Add a client : 1\n"<< "   Display a client : 2 \n" << "   Display all client : 3\n" <<"   Add a product to the client cart : 4 \n" << "   Delete a product from the client cart: 5 \n";
    std::cout<< "   Update product quantity in a client cart : 6 \n\n";
    std::cin>>choix;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " You have chosen the number "<<choix<<"\n\n";
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
      std::cout<<" Action number "<<choix<< " doesn't exist"<<"\n";
      break;
}
}
void orderManagement(magasin::Magasin& mag ){
  std::cout << "\033[2J\033[1;1H"; //clear terminal
  int choix;
    std::cout<< "---------------------------------------------Order Management ----------------------------------------------\n\n";
    std::cout<< " Enter an action ! \n" <<"   Check order : 1  \n" << "   Display all order : 2 \n" << "   Display a client orders : 3 \n\n";
    std::cin>>choix;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " You have chosen the number "<<choix<<"\n\n";
    switch (choix){
      case 1 :
      mag.checkOrder();      
      break;
      case 2 :
      mag.displayAllOrders();
      break;
      case 3 :
      mag.displayClientOrders();
      break;
      default :
      std::cout<<" Action number "<<choix<< " doesn't exist \n";
      break;
}
}

int main(int argc, char const *argv[]) {


magasin::Magasin mag;
while (1) {
 
	int choix;
    std::cout<< "---------------------------------------------Menu--------------------------------------------- \n\n";
    std::cout<< " Enter an action ! \n" <<"   Store management : 1 \n"<<"   Users management : 2 \n"<<"   Orders management : 3 \n\n";
    
    std::cin>>choix;
    std::cout<< " You have chosen the number "<<choix<<"\n\n";
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
      std::cout<<" Action number "<<choix<< " doesn't exist \n";
      break;

 
   }
}
return 0;
}