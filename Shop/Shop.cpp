#include "Shop.hpp"

Shop::Shop() {
	this->balance = 0;
	this->income = 0;
	this->outcome = 0;
}
Shop::Shop(const Shop& from) {
	this->income = from.income;
	this->outcome = from.outcome;
	this->balance = from.balance;

	this->all_products = from.all_products;
}
Shop& Shop::operator=(const Shop& from) {
	if (this != &from) {
		this->income = from.income;
		this->outcome = from.outcome;
		this->balance = from.balance;

		this->all_products = from.all_products;
	}
	return *this;
}
Shop::~Shop() {

}

void Shop::add_product(const Product& to_add) {
	this->all_products.add(to_add);
}
void Shop::remove_product(const int& index) {
	this->all_products.remove(index);
}

void Shop::buy_product(const int& index) {
	this->all_products.get(index).add_in_stock(1);
	this->balance -= all_products.get(index).get_buy_price();
	this->outcome += all_products.get(index).get_buy_price();
}
void Shop::sell_product(const int& index) {
	if (this->all_products.get(index).get_in_stock() < 1) return;
	this->all_products.get(index).add_in_stock(-1);
	this->balance += all_products.get(index).get_sell_price();
	this->income += all_products.get(index).get_sell_price();
}

void Shop::set_balance(double new_balance) {
	this->balance = new_balance;
}

double Shop::get_balance()const {
	return this->balance;
}
double Shop::get_income()const {
	return this->income;
}
double Shop::get_outcome()const {
	return this->outcome;
}

double Shop::calculate_profit()const {
	return this->income - this->outcome;
}

int Shop::get_products_count()const {
	return this->all_products.get_used();
}

Product& Shop::get_product(const int& index)const {
	return this->all_products.get(index);
}