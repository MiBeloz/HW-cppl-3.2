#include "Smart_array.h"

#include <iostream>


void array_info(const Smart_array<int>& arr);

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "\tКопирование умных массивов.\n" << std::endl;

	try {
		Smart_array<int> arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		array_info(arr);

		Smart_array<int> new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		array_info(new_array);

		std::cout << "Копирование объекта '" << new_array.get_address() << "' в объект '" << arr.get_address() << "'." << std::endl;
		arr = new_array;
		array_info(arr);
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}

	system("pause > nul");
	return 0;
}

void array_info(const Smart_array<int>& arr) {
	std::cout << "Smart_array '" << arr.get_address() << "': ";
	for (size_t i = 0; i < arr.get_size(); ++i) {
		std::cout << arr.get_element(i) << " ";
	}
	std::cout << "\nРазмер массива: " << arr.get_size() << std::endl;
	std::cout << "Емкость массива: " << arr.get_capacity() << std::endl << std::endl;
}
