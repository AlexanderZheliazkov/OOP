#pragma once
#include "MyString.hpp"
#include <iostream>


class CustomField
{
public:
	CustomField();
	CustomField(const char* name, const char* value);
	CustomField(const CustomField& from);
	CustomField& operator=(const CustomField& from);
	~CustomField();

	void set_value(const char* new_value);
	void set_name(const char* name);

	MyString get_value() const;
	MyString get_name() const;

	friend std::ostream& operator<<(std::ostream& out, const CustomField& to_print);
	friend std::istream& operator>>(std::istream& in, CustomField& to_get);

private:

	MyString name;
	MyString value;

};