#pragma once
#include "Product.hpp"
#include "Array.hpp"
#include "MyString.hpp"
#include "Shop.hpp"

class User
{
public:
	User();
	User(const User& from);
	User& operator=(const User& from);
	~User();

	void add_in_basket(const int& index);
	void remove_from_basket(const int& index);

	void buy_products();

	void set_shop(Shop& shop);

	void clear_basket();

	int get_products_in_basket_count()const;
	Product& get_product_in_basket(const int& index) const;

private:

	bool is_admin;

	MyString name;
	Array<int> basket;  //stores the indexes of products that are in the basket
	Shop* shop;
};