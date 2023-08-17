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

	std::string get_fullAddress() {
		std::string fullAdress;
		fullAdress = { sity + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment) };
		return fullAdress;
	}

	
};

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
		std::string* array = new std::string[size];
		file_out << size << std::endl;

		for (int i = 0; i < size; ++i) {

			file_in >> sity;
			file_in >> street;
			file_in >> house;
			file_in >> apartment;

			Address data(sity, street, house, apartment);

			array[i] = data.get_fullAddress();
		}

		for (int i = 0; i < size; ++i) {
			file_out << array[size - i - 1] << std::endl;
		}

		file_in.close();
		file_out.close();

		
		delete[] array;

	}
	else {
		std::cout << "File is (files are) not open!" << '\n';
	}

	return 0;
}