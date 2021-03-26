#pragma once
#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* arr);
	MyString(const MyString& from);
	MyString& operator=(const MyString& from);
	~MyString();

	void set_string(const char* new_arr);

	void add_symbol(char s);
	void remove_sybol();
	void print() const;

	char* get_string() const;
	int get_size() const;

	friend std::ostream& operator<<(std::ostream& out, const MyString& to_print);
	friend std::istream& operator>>(std::istream& in, MyString& to_get);

private:

	char* arr;
	int arr_size;

};