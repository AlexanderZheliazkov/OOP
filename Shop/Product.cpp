#include "Product.hpp"
#include <cstring>


Product::Product() {
	this->sell_price = 0;
	this->buy_price = 0;
	this->in_stock = 0;
}

Product::Product(const char* name, const char* description, const int in_stock, const double buy_price, const double sell_price) {
	this->name.set_string(name);
	this->description.set_string(description);
	this->in_stock = in_stock;
	this->buy_price = buy_price;
	this->sell_price = sell_price;
}

Product::Product(const Product& from) {
	
	this->sell_price = from.sell_price;
	this->buy_price = from.buy_price;
	this->name = from.name;
	this->description = from.description;
	this->in_stock = from.in_stock;
	this->custom_fields = from.custom_fields;

}
Product& Product::operator=(const Product& from) {
	if (this != &from) {
		this->sell_price = from.sell_price;
		this->buy_price = from.buy_price;
		this->name = from.name;
		this->description = from.description;
		this->in_stock = from.in_stock;
		this->custom_fields = from.custom_fields;
	}
	return *this;
}
Product::~Product() {

}

void Product::set_name(const char* name) {
	this->name.set_string(name);
}
void Product::set_description(const char* description) {
	this->description.set_string(description);
}

void Product::set_sell_price(const double new_price) {
	this->sell_price = new_price;
}
void Product::set_buy_price(const double new_price) {
	this->buy_price = new_price;
}

void Product::set_in_stock(const int new_in_stock) {
	this->in_stock = new_in_stock;
}
void Product::add_in_stock(const int add_in_stock) {
	this->in_stock += add_in_stock;
}

MyString Product::get_name() const {
	return this->name;
}
MyString Product::get_Description() const {
	return this->description;
}

int Product::get_in_stock() const {
	return this->in_stock;
}

double Product::get_sell_price() const {
	return this->sell_price;
}
double Product::get_buy_price() const {
	return this->buy_price;
}

std::ostream& operator<<(std::ostream& out, const Product& to_print) {
	out << "Product name: " << to_print.name << std::endl;
	out << "| Description: " << to_print.description << std::endl;
	out << "| Price: " << to_print.sell_price << std::endl;
	out << "| In stock: " << to_print.in_stock << std::endl;
	if (to_print.custom_fields.get_used() > 0) {
		for (int i = 0; i < to_print.custom_fields.get_used(); i++)
		{
			out << "| " << to_print.custom_fields.get(i) << std::endl;
		}
	}

	return out;
}
std::istream& operator>>(std::istream& in, Product& to_get) {
	std::cout << "Name: ";
	in >> to_get.name;

	std::cout << "Description: ";
	in >> to_get.description;

	std::cout << "Buy price: ";
	in >> to_get.buy_price;

	if (to_get.buy_price < 0) to_get.buy_price = 0;

	std::cout << "Sell price: ";
	in >> to_get.sell_price;
	if (to_get.sell_price < 0) to_get.sell_price = 0;

	std::cout << "In stock: ";
	in >> to_get.in_stock;
	if (to_get.in_stock < 0) to_get.in_stock = 0;

	int coustom_fields_count;
	std::cout << "Custom fields count(max 10): ";
	in >> coustom_fields_count;
	in.clear();
	if (coustom_fields_count > 0 && coustom_fields_count <= 10) {
		for (int i = 0; i < coustom_fields_count; i++)
		{
			CustomField temp;
			
			in >> temp;
			to_get.custom_fields.add(temp);
		}
	}

	return in;
}

CustomField Product::get_custom_field(const int& index) const {
	return this->custom_fields.get(index);
}

void Product::add_custom_field(const CustomField& to_add) {
	this->custom_fields.add(to_add);
}

int Product::get_custom_fields_count()const {
	return this->custom_fields.get_used();
}

//void Product::add_custom_field(const char* name, const char* value) {
//	CustomField temp(name, value);
//	this->custom_fields.add(temp);
//}


//shoes

Shoes::Shoes() : Product(), size(0) {}
Shoes::Shoes(const char* name, const char* description, const int in_stock, const double but_price, const double sell_price, const char* brand, int size) : Product(name, description, in_stock, but_price, sell_price), brand(brand), size(size) {}
Shoes::Shoes(const Shoes& from) : Product(from), size(from.size), brand(from.brand) {}
Shoes& Shoes::operator=(const Shoes& from) {
	if (this != &from) {
		this->Product::operator=(from);
		this->size = from.size;
		this->brand = from.brand;
	}
	return *this;
}
Shoes::~Shoes() {

}

void Shoes::set_brand(const char* new_brand) {
	this->brand.set_string(new_brand);
}
void Shoes::set_brand(const MyString& new_brand) {
	this->brand = new_brand;
}

void Shoes::set_size(const int& new_size) {
	this->size = new_size;
}

int Shoes::get_size() {
	return this->size;
}
MyString Shoes::get_brand() {
	return this->brand;
}


// flower

Flower::Flower() : Product() {};
Flower::Flower(const char* name, const char* description, const int in_stock, const double but_price, const double sell_price, const char* sort, const char* growth_region) : Product(name, description, in_stock, but_price, sell_price) {
	this->sort.set_string(sort);
	this->growth_region.set_string(growth_region);
}
Flower::Flower(const Flower& from) : Product(from) {
	this->sort = from.sort;
	this->growth_region = from.growth_region;
}
Flower& Flower::operator=(const Flower& from) {
	if (this != &from) {
		this->Product::operator=(from);
		this->sort = from.sort;
		this->growth_region = from.growth_region;
	}
	return *this;
}
Flower::~Flower() {

}

void Flower::set_sort(MyString sort) {
	this->sort = sort;
}
void Flower::set_gr(MyString gr) {
	this->growth_region = gr;
}

MyString Flower::get_sort() {
	return this->sort;
}
MyString Flower::get_gr() {
	return this->growth_region;
}