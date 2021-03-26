#pragma once
#include "Array.hpp"
#include "Product.hpp"
#include "Category.hpp"

class Shop
{
public:
	Shop();
	Shop(const Shop& from);
	Shop& operator=(const Shop& from);
	~Shop();

	void add_product(const Product& to_add);
	void remove_product(const int& index);

	void buy_product(const int& index);
	void sell_product(const int& index);

	void set_balance(double new_balance);

	int get_products_count()const;

	double get_balance()const;
	double get_income()const;
	double get_outcome()const;

	double calculate_profit()const;

	Product& get_product(const int& index)const;

private:

	double balance;
	double income;
	double outcome;

	Array<Product> all_products;
	//Array<Category> all_categories;

};