#include <iostream>
#include <string>
#include <fstream>

class Address {

private:
	std::string sity;
	std::string street;
	int house;
	int apartment;
	

public:

	Address(std::string sity, std::string street, int house, int apartment) {
		this->sity = sity;
		this->street = street;
		this->house = house;
		this->apartment = apartment;
	};

	Address() {
		sity = "";
		street = "";
		house = 0;
		apartment = 0;
	}

	std::string get_sity() {
		return sity;
	}
	std::string get_street() {
		return street;
	}
	int get_house() {
		return int(house);
	}
	int get_apartment() {
		return int(apartment);
	}

	std::string get_fullAddress() {
		std::string fullAdress;
		fullAdress = { sity + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment) };
		return fullAdress;
	}
};

void sortAddress(Address array[], int size) {

	for (int i = 0; i < size; ++i) {
		bool flag = true;
		for (int j = 0; j < size - 1; ++j) {
			if (array[j].get_sity() > array[j + 1].get_sity()) {
				flag = false;
				std::swap(array[j], array[j + 1]);					
			}
		}
		if (flag) {
			break;
		}

	}
}	

int main() {

	setlocale(LC_ALL, "Russian");

	std::ifstream file_in;
	std::ofstream file_out;
	int count{};
	std::string sity;
	std::string street;
	int house;
	int apartment;
	
	file_in.open("in.txt");
	file_out.open("out.txt");

	if (file_in.is_open() && file_out.is_open()) {
		file_in >> count;
		int const size = count;

		file_out << size << std::endl;
		
		Address* array = new Address[size];

		for (int i = 0; i < size; ++i) {
				
			file_in >> sity;
			file_in >> street;
			file_in >> house;
			file_in >> apartment;

			Address data (sity, street, house, apartment);

			array[i] = data;
		} 

		std::cout << array[0].get_sity() << std::endl;

		sortAddress(array, size);
		
		for (int i = 0; i < size; ++i) {
			Address data(array[i].get_sity(), array[i].get_street(), array[i].get_house(), array[i].get_apartment());

			file_out << data.get_fullAddress() << '\n';
		}
		
		std::cout << array[0].get_sity() << std::endl;

		file_in.close();
		file_out.close();

		delete[] array;
	}
	else {
		std::cout << "File is (files are) not open!" << '\n';
	}

	return 0;
}
