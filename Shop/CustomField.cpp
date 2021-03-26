#include "CustomField.hpp"

CustomField::CustomField() {
	
}

CustomField::CustomField(const char* name, const char* value) {
	this->value.set_string(value);
	this->name.set_string(name);
}

CustomField::CustomField(const CustomField& from) {
	this->value = from.value;
	this->name = from.name;
}


CustomField& CustomField::operator=(const CustomField& from) {
	if (this != &from) {
		this->value = from.value;
		this->name = from.name;
	}
	return *this;
}

CustomField::~CustomField() {

}

void CustomField::set_value(const char* value) {
	this->value = value;
}

void CustomField::set_name(const char* name) {
	this->name.set_string(name);
}

MyString CustomField::get_value() const {
	return this->value;
}

MyString CustomField::get_name() const {
	return this->name;
}

std::ostream& operator<<(std::ostream& out, const CustomField& to_print) {
	out << to_print.get_name() << ": " << to_print.get_value();
	return out;
}

std::istream& operator>>(std::istream& in, CustomField& to_get) {
	std::cout << "Enter name: ";
	in >> to_get.name;
	std::cout << "Enter value: ";
	in >> to_get.value;
	return in;
}