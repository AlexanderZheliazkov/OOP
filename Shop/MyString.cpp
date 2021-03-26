#include "MyString.hpp"
#include <iostream>

int str_length(const char* arr) {
	int size = 0;
	while (arr[size] != 0)
	{
		size++;
	}
	return size;
}

MyString::MyString() {
	this->arr = new char[1];
	this->arr[0] = '\0';
	this->arr_size = 1;
}
MyString::MyString(const char* arr) {
	this->arr_size = str_length(arr) + 1;
	this->arr = new char[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		this->arr[i] = arr[i];
	}
}
MyString::MyString(const MyString& from) {
	this->arr_size = from.arr_size;
	this->arr = new char[arr_size];
	for (int i = 0; i < this->arr_size; i++)
	{
		this->arr[i] = from.arr[i];
	}
}
MyString::~MyString() {
	delete[] this->arr;
}

MyString& MyString::operator=(const MyString& from) {

	if (this != &from) {

		this->arr_size = from.arr_size;
		delete[] this->arr;
		this->arr = new char[this->arr_size];
		for (int i = 0; i < this->arr_size; i++)
		{
			this->arr[i] = from.arr[i];
		}
	}
	return *this;

}

void MyString::set_string(const char* new_arr) {
	this->arr_size = str_length(new_arr) + 1;
	delete[] this->arr;
	this->arr = new char[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		this->arr[i] = new_arr[i];
	}
}

void MyString::add_symbol(char s) {
	this->arr_size += 1;
	char* temp = new char[this->arr_size];
	for (int i = 0; i < this->arr_size - 2; i++)
	{
		temp[i] = this->arr[i];
	}
	temp[this->arr_size - 2] = s;
	temp[this->arr_size - 1] = '\0';
	delete[] this->arr;
	this->arr = new char[this->arr_size];
	for (int i = 0; i < this->arr_size; i++)
	{
		this->arr[i] = temp[i];
	}
	delete[] temp;
}
void MyString::remove_sybol() {
	if (this->arr_size <= 1) return;

	this->arr_size -= 1;
	char* temp = new char[this->arr_size];
	for (int i = 0; i < this->arr_size; i++)
	{
		temp[i] = this->arr[i];
	}
	temp[this->arr_size - 1] = '\0';
	delete[] this->arr;
	this->arr = new char[this->arr_size];
	for (int i = 0; i < this->arr_size; i++)
	{
		this->arr[i] = temp[i];
	}
	delete[] temp;

}
void MyString::print() const {
	std::cout << arr;
}

char* MyString::get_string() const {
	return this->arr;
}
int MyString::get_size() const {
	return this->arr_size;
}

std::ostream& operator<<(std::ostream& out, const MyString& to_print) {
	out << to_print.arr;
	return out;
}

std::istream& operator>>(std::istream& in, MyString& to_get) {
	char* temp = new char[1001];
	in.getline(temp, 1000);
	to_get.set_string(temp);
	delete[] temp;
	return in;
}