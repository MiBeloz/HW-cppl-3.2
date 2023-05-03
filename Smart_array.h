#pragma once

#include <iostream>
#include <exception>


template<typename T>
class Smart_array {
public:
	Smart_array(const size_t size);

	void add_element(const T element);
	T get_element(const size_t element) const;
	size_t get_size() const;
	size_t get_capacity() const;
	const Smart_array<T>* get_address() const;

	//Конструктор копирования
	Smart_array<T> (const Smart_array<T>& other);

	//Конструктор присваивания
	Smart_array<T>& operator=(const Smart_array<T>& other);

	~Smart_array();

private:
	size_t m_capacity;
	size_t m_size;
	T* m_array;
};


template<typename T>
Smart_array<T>::Smart_array(const size_t size) {
	if (size > SHRT_MAX) {
		throw std::exception("Smart_array is too long");
	}

	m_capacity = size;
	m_size = 0;
	if (m_capacity != 0) {
		m_array = new T[m_capacity]{};
	}
	else {
		m_array = nullptr;
	}
	

	//В конструкторе нельзя писать в поток вывода, это для примера работы программы.
	std::cout << "\t///Вызов конструктора для объекта: '" << this << "'///" << std::endl;
}

template<typename T>
void Smart_array<T>::add_element(const T element) {
	if (m_capacity > m_size) {
		m_array[m_size++] = element;
	}
	else {
		m_capacity = m_capacity * 2;

		T* temp_array = new T[++m_capacity]{};
		for (size_t i = 0; i < m_size; ++i) {
			temp_array[i] = m_array[i];
		}

		temp_array[m_size++] = element;

		delete[] m_array;
		m_array = temp_array;
	}
}

template<typename T>
T Smart_array<T>::get_element(const size_t element) const {
	if (element >= m_size) {
		throw std::exception("Smart_array out of range");
	}
	return m_array[element];
}

template<typename T>
size_t Smart_array<T>::get_size() const {
	return m_size;
}

template<typename T>
size_t Smart_array<T>::get_capacity() const {
	return m_capacity;
}

template<typename T>
const Smart_array<T>* Smart_array<T>::get_address() const {
	return this;
}

//Конструктор копирования
template<typename T>
Smart_array<T>::Smart_array(const Smart_array<T>& other) {
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	if (m_capacity != 0) {
		m_array = new T[m_capacity]{};
		for (size_t i = 0; i < m_size; ++i) {
			m_array[i] = other.m_array[i];
		}
	}
	else {
		m_array = nullptr;
	}
}

//Конструктор присваивания
template<typename T>
Smart_array<T>& Smart_array<T>::operator=(const Smart_array<T>& other) {
	if (this != &other) {
		delete[] m_array;
		m_array = nullptr;

		m_capacity = other.m_capacity;
		m_size = other.m_size;
		if (m_capacity != 0) {
			m_array = new T[m_capacity]{};
			if (m_size > m_capacity) {
				throw std::exception("Smart_array error");
			}
			for (size_t i = 0; i < m_size; ++i) {
				m_array[i] = other.m_array[i];
			}
		}
	}

	return *this;
}

template<typename T>
Smart_array<T>::~Smart_array() {
	delete[] m_array;
	m_array = nullptr;

	//В деструкторе нельзя писать в поток вывода, это для примера работы программы.
	std::cout << "\t///Вызов деструктора для объекта: '" << this << "'///" << std::endl;
}
