#pragma once

template<class T>
class Array
{
public:
	Array();
	Array(const Array& from);
	Array& operator=(const Array& from);
	~Array();

	void add(const T& new_obj);
	void remove(const int& index);

	T& get(const int& index)const;

	int get_used() const;

private:

	int max_size;
	int used;

	T* arr;
};

template<class T>
Array<T>::Array() {
	this->arr = new T[1];
	this->max_size = 1;
	this->used = 0;
}

template<class T>
Array<T>::Array(const Array& from) {
	this->max_size = from.max_size;
	this->used = from.used;

	this->arr = new T[this->max_size];
	for (int i = 0; i < this->used; i++)
	{
		this->arr[i] = from.arr[i];
	}
}

template<class T>
Array<T>& Array<T>::operator=(const Array& from) {
	if (this != &from) {
		this->max_size = from.max_size;
		this->used = from.used;

		delete[] this->arr;
		this->arr = new T[this->max_size];
		for (int i = 0; i < this->used; i++)
		{
			this->arr[i] = from.arr[i];
		}
	}
	return *this;
}

template<class T>
Array<T>::~Array() {
	delete[] this->arr;
}

template<class T>
void Array<T>::add(const T& obj) {
	if (this->used == this->max_size) {
		this->max_size++;
	}

	T* temp = new T[this->max_size];
	for (int i = 0; i < this->used; i++)
	{
		temp[i] = this->arr[i];
	}

	temp[used] = obj;
	used++;
	delete[] this->arr;
	this->arr = new T[this->max_size];
	for (int i = 0; i < this->used; i++) {
		this->arr[i] = temp[i];
	}
	delete[] temp;
}

template<class T>
void Array<T>::remove(const int& index) {
	if (index > used&& index < 0) {
		return;
	}

	T* temp = new T[this->max_size];
	for (int i = 0; i < this->used; i++)
	{
		if (i < index) {
			temp[i] = this->arr[i];
		}
		else
		{
			if (i > index) {
				temp[i - 1] = this->arr[i];
			}
		}
	}
	used--;
	delete[] this->arr;
	this->arr = new T[this->max_size];
	for (int i = 0; i < used; i++)
	{
		this->arr[i] = temp[i];
	}
	delete[] temp;
}

template<class T>
T& Array<T>::get(const int& index) const {
	if (index < 0 && index > used) {
		//return NULL;
	}
	return this->arr[index];
}

template<class T>
int Array<T>::get_used() const{
	return this->used;
}