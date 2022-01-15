#include "magasin.h"

void magManagement(magasin::Magasin mag ){
	int choix;
    std::cout<< "---------------------------------------------Store Management ----------------------------------------------"<<std::endl<<std::endl;
    std::cout<< " Enter an action ! " <<std::endl<<"  Add product : 1"<<std::endl<<" Update product quantity: 2 "<<std::endl<<" displayAllProducts : 3 "<<std::endl<<" display a Products : 4 "<<std::endl;
    std::cout<< " Display a client : 5 " <<std::endl<< " Display all client : 6 " <<std::endl;
    std::cin>>choix;
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      mag.addClient();
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
      case 5 :
      mag.displayClients();
      break;
      case 6 :
      mag.displayAllClients();
      break;
      case 7 :
      mag.addProductToClient();
      break;
      default :
      choix=0;
      break;
}
}


int main(int argc, char const *argv[]) {

magasin::Magasin mag;
magasin::Product prod1("WD40","graisse",4,4.97);
while (1) {
	int choix;
    std::cout<< "---------------------------------------------Menu---------------------------------------------"<<std::endl<<std::endl;
    std::cout<< " Enter an action ! " <<std::endl<<"  Store management : 1"<<std::endl<<" Users management: 2 "<<std::endl<<" Orders management : 3 "<<std::endl;
    
    std::cin>>choix;
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      magManagement(mag);
      break;
      case 2 :
      
      break;
      case 3 :
     
      break;
      
      default :
      choix=0;
      break;

 
   }
}
return 0;
}