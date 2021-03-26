#include "User.hpp"

User::User() {
	this->is_admin = false;
	this->shop = nullptr;
}
User::User(const User& from) {
	this->is_admin = from.is_admin;
	this->basket = from.basket;
	this->name = from.name;
	this->shop = from.shop;
}
User& User::operator=(const User& from) {
	if (this != &from) {
		this->is_admin = from.is_admin;
		this->basket = from.basket;
		this->name = from.name;
		this->shop = from.shop;
	}
	return *this;
}
User::~User() {
	
}

void User::add_in_basket(const int& to_add) {
	this->basket.add(to_add);
}
void User::remove_from_basket(const int& index) {
	this->basket.remove(index);
}

void User::buy_products() {
	for (int i = 0; i < this->basket.get_used(); i++)
	{
		this->shop->sell_product(this->basket.get(i));
	}
	this->clear_basket();
}

void User::set_shop(Shop& shop) {
	this->shop = &shop;
}

int User::get_products_in_basket_count()const {
	return this->basket.get_used();
}

Product& User::get_product_in_basket(const int& index) const {
	return this->shop->get_product(basket.get(index));
}

void User::clear_basket() {
	while (this->basket.get_used() > 0)
	{
		this->basket.remove(0);
	}
}