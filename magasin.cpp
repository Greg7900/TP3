
#include "magasin.h"
namespace magasin{



	Magasin::Magasin(){}
	void Magasin::displayProduct(){
		for(auto it=_products.begin(); it!=_products.end();it++){
         std::cout<<*it<<std::endl;
      }
	}
	void Magasin::addProduct(magasin::Product product){
		_products.push_back(product);
	}
	std::ostream& operator<<(std::ostream& os, const Magasin& magasin){
	
	return os;
	}
	

}