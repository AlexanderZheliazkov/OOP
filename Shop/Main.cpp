#include <iostream>
#include "Array.hpp"
#include "Product.hpp"
#include "MyString.hpp"
#include "CustomField.hpp"
#include "Shop.hpp"
#include "User.hpp"

void start_menu(Shop& from, User user);
void show_products(Shop& from, User user);
void show_product_info(Shop& from, const int& index, User user);
void add_product_menu(Shop& shop, User user);
void show_basket_menu(Shop& shop, User user);

int main() {

	Shop my_shop;

	User user;
	user.set_shop(my_shop);

	Product red_shoes("Red Shoes", "Very light red shoes, perfect for long walks.", 10, 24.95, 39.95);
	Product green_shoes("Green Shoes", "Green shoes, perfect for rainy days.", 10, 19.95, 29.95);
	Product white_shirt("White shirt", "Clean white shirt.", 10, 14.95, 19.95);
	Product Toster("Toster", "If you are hungry you shoud try this!!!", 10, 44.95, 55.95);
	Product Deadpool_book("Deadpool", "Great action comedy book.", 10, 5.95, 9.95);


	CustomField red_shoes_color("Color", "Red"), red_shoes_size("Size", "41, 42, 43, 44");
	red_shoes.add_custom_field(red_shoes_color);
	red_shoes.add_custom_field(red_shoes_size);

	CustomField green_shoes_color("Color", "Green"), green_shoes_size("Size", "40, 42, 43, 44");
	green_shoes.add_custom_field(green_shoes_color);
	green_shoes.add_custom_field(green_shoes_size);

	CustomField white_shirt_color("Color", "White"), white_shirt_size("Size", "XS, S, M, L");
	white_shirt.add_custom_field(white_shirt_color);
	white_shirt.add_custom_field(white_shirt_size);

	CustomField Deadpool_book_autor("Autor", "unknown");
	Deadpool_book.add_custom_field(Deadpool_book_autor);

	CustomField Toster_food("Food per hour", "3 toasts");
	Toster.add_custom_field(Toster_food);


	my_shop.add_product(red_shoes);
	my_shop.add_product(green_shoes);
	my_shop.add_product(white_shirt);
	my_shop.add_product(Deadpool_book);
	my_shop.add_product(Toster);

	
	start_menu(my_shop, user);


	return 0;
}

void start_menu(Shop& from, User user) {
	system("CLS");

	std::cout << "Choose: \n";
	std::cout << "1. See all products" << std::endl;
	std::cout << "2. See categories(in development)" << std::endl;
	std::cout << "3. See basket" << std::endl;
	std::cout << "4. Add product(Admin only)" << std::endl;
	std::cout << "0. Exit" << std::endl;
	int index;
	std::cin >> index;

	switch (index)
	{
	case 1: show_products(from, user); break;
	case 2: break;
	case 3: show_basket_menu(from, user);
	case 4: add_product_menu(from, user); break;
	default:
		break;
	}
}

void show_products(Shop& from, User user) {
	system("CLS");

	for (int i = 0; i < from.get_products_count(); i++)
	{
		std::cout << i << ") " << from.get_product(i).get_name() << "\t\tPrice: " << from.get_product(i).get_sell_price() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Choose: \n";
	std::cout << "-1. Back to main menu" << std::endl;
	std::cout << "OR press number of product to see more info." << std::endl;
	int index;
	std::cin >> index;

	if (index < 0) {
		system("CLS");
		start_menu(from, user);
		return;
	}
	else
	{
		if (index >= 0 && index < from.get_products_count()) {
			show_product_info(from, index, user);
		}
	}

}

void show_product_info(Shop& from, const int& index, User user) {
	system("CLS");
	std::cout << std::endl;
	std::cout << from.get_product(index) << std::endl;

	std::cout << "Choose: \n";
	std::cout << "0. Return to main menu" << std::endl;
	std::cout << "1. Buy product" << std::endl;
	std::cout << "2. Add to basket" << std::endl;
	
	int temp;
	std::cin >> temp;

	switch (temp)
	{
	case 0: start_menu(from, user); break;
	case 1: 
		from.sell_product(index);
		start_menu(from, user);
		break;
	case 2:
		user.add_in_basket(index);
		start_menu(from, user);
		break;
	default:
		break;
	}
}

void add_product_menu(Shop& shop, User user) {
	system("CLS");
	
	Product temp;
	std::cout << "Adding product" << std::endl;
	std::cin >> temp;
	shop.add_product(temp);

	start_menu(shop, user);
}

void show_basket_menu(Shop& shop, User user) {
	system("CLS");

	for (int i = 0; i < user.get_products_in_basket_count(); i++)
	{
		std::cout << i << ") " << user.get_product_in_basket(i) << std::endl;
	}

	std::cout << "Choose: \n";
	std::cout << "0. Return to main menu" << std::endl;
	std::cout << "1. Buy products" << std::endl;
	std::cout << "2. Remove product" << std::endl;
	std::cout << "3. Clear basket" << std::endl;

	int temp;
	std::cin >> temp;

	switch (temp)
	{
	case 0: start_menu(shop, user); break;
	case 1: user.buy_products(); start_menu(shop, user); break;
	case 2: {

		std::cout << "\nChoose: \n";
		std::cout << "-1. Back to main menu" << std::endl;
		std::cout << "OR press number of product to romove it from the basket." << std::endl;

		int temp1;
		std::cin >> temp1;

		if (temp1 < 0) {
			start_menu(shop, user); return;
		}
		else
		{
			if (temp1 < user.get_products_in_basket_count()) {
				user.remove_from_basket(temp1);
			}
			start_menu(shop, user); return;
		}
	}
	case 3:user.clear_basket(); break;
	default:
		break;
	}
}