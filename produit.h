#ifndef PRODUIT_H
#define PRODUIT_H
#include <iostream>
#include <vector>
#include <algorithm>
namespace magasin
{
	class Product
	{

		Product(std::string title, std::string description, int quantity, double price);

	public:
		std::string title() const;
		std::string description() const;
		int quantity()const;
		double price() const;
		void setQuantity(int value);
	private:
		std::string _title;
		std::string _description;
		int _quantity;
		double _price;
	};
	std::ostream &operator<<(std::ostream &os, const Product &product);
	std::vector<magasin::Product>::iterator findProduct(const magasin::Product &product, std::vector<magasin::Product> &vectorP);
	std::vector<magasin::Product>::iterator findProduct(const std::string title, std::vector<magasin::Product> &vectorP);
}

#endif