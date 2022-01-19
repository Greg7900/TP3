#include "produit.h"	
namespace magasin{
	Product::Product(std::string title, std::string description, int quantity, double price) : _title(title), _description(description), _quantity(quantity),_price(price) {}

	std::string Product::title() const{
		return _title;
	}
	std::string Product::description() const{
		return _description;
	}
	int Product::quantity()const{
		return _quantity;
	}
	double Product::price() const{
		return _price;
	}
	void Product::setQuantity(int value){
		_quantity = value;
	}
	magasin::Product operator + ( magasin::Product& product,  magasin::Product& product1) {
		product.setQuantity(product.quantity() + product1.quantity());
		return product;
	}
	magasin::Product operator - ( magasin::Product& product,  magasin::Product& product1) {
		product.setQuantity(product.quantity() - product1.quantity());
		return product;
	}
	std::ostream& operator<<(std::ostream& os, const Product& product){
		os<<" Title : " + product.title()  + "\n Description : "+product.description() + "\n Quantity : " + std::to_string(product.quantity()) +"\n Price : " + std::to_string(product.price()) + "\n";
	return os;
	}
		std::vector<magasin::Product>::iterator findProduct(const magasin::Product& product, std::vector<magasin::Product>& vectorP )
	    {
	    	auto it = std::find_if(vectorP.begin(),vectorP.end(),[product](const magasin::Product& prod) {return product.title()==prod.title();});
	    	return it; 
	    }
	    
	    
	std::vector<magasin::Product>::iterator findProduct(const std::string title, std::vector<magasin::Product>& vectorP )
	    {
	    	auto it=std::find_if(vectorP.begin(),vectorP.end(),[title](const magasin::Product& prod) {return title==(prod.title());});
	    	return it; 
		}
}