#pragma once
#include "MyString.hpp"
#include "CustomField.hpp"
#include "Array.hpp"
#include "Category.hpp"

class Product
{
public:
	Product();
	Product(const char* name, const char* description, const int in_stock, const double but_price, const double sell_price);
	Product(const Product& from);
	Product& operator=(const Product& from);
	~Product();

	void set_name(const char* name);
	void set_description(const char* description);

	void set_sell_price(const double new_price);
	void set_buy_price(const double new_price);

	void set_in_stock(const int new_in_stock);
	void add_in_stock(const int add_in_stock);

	void add_custom_field(const CustomField& to_add);
	//void add_custom_field(const char* name, const char* value);

	int get_in_stock() const;
	int get_custom_fields_count() const;

	double get_sell_price() const;
	double get_buy_price() const;

	MyString get_name() const;
	MyString get_Description() const;
	
	CustomField get_custom_field(const int& index) const;
	
	friend std::ostream& operator<<(std::ostream& out, const Product& to_print);
	friend std::istream& operator>>(std::istream& in, Product& to_get);

private:

	int in_stock;

	double sell_price;
	double buy_price;

	MyString name;
	MyString description;

	Array<CustomField> custom_fields;
};



class Shoes : public Product
{
public:
	Shoes();
	Shoes(const char* name, const char* description, const int in_stock, const double but_price, const double sell_price, const char* brand, int size);
	Shoes(const Shoes& from);
	Shoes& operator=(const Shoes& from);
	~Shoes();

	void set_brand(const char* new_brand);
	void set_brand(const MyString& new_brand);

	void set_size(const int& new_size);

	int get_size();
	MyString get_brand();

private:
	MyString brand;
	int size;
};



class Flower : public Product
{
public:
	Flower();
	Flower(const char* name, const char* description, const int in_stock, const double but_price, const double sell_price, const char* sort, const char* growth_region);
	Flower(const Flower& from);
	Flower& operator=(const Flower& from);
	~Flower();

	void set_sort(MyString sort);
	void set_gr(MyString gr);

	MyString get_sort();
	MyString get_gr();

private:
	MyString sort;
	MyString growth_region;
};