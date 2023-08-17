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

	std::string get_house() {
		return std::to_string(house);
	}
	std::string get_apartment() {
		return std::to_string(apartment);
	}



	std::string get_fullAddress() {
		std::string fullAdress;
		fullAdress = { sity + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment) };
		return fullAdress;
	}
	
};



void sortAddress(std::string* array[], int size) {

	for (int c = 0; c < size; ++c) {
		bool flag = true;
		for (int i = 0; i < size - 1; ++i) {
			if (array[i][0] > array[i + 1][0]) {
					flag = false;
					for (int j = 0; j < 4; ++j) {
						std::string dopStr;
						dopStr = array[i][j];
						array[i][j] = array[i + 1][j];
						array[i + 1][j] = dopStr;
					}
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
	Address data;

	file_in.open("in.txt");
	file_out.open("out.txt");

	if (file_in.is_open() && file_out.is_open()) {
		file_in >> count;
		int const size = count;

		file_out << size << std::endl;
		
		std::string** array = new std::string*[4];
		for (int i = 0; i < size; ++i) {
		array[i] = new std::string [4];
		}

		for (int i = 0; i < size; ++i) {
				
				file_in >> sity;
				file_in >> street;
				file_in >> house;
				file_in >> apartment;

				Address data (sity, street, house, apartment);

				array[i][0] = data.get_sity();
				array[i][1] = data.get_street();
				array[i][2] = data.get_house();
				array[i][3] = data.get_apartment();
		} 

		sortAddress(array, size);
		
		for (int i = 0; i < size; ++i) {
			sity = array[i][0];
			street = array[i][1];
			std::to_string(house) = array[i][2];
			std::to_string(apartment) = array[i][3];
			
			Address data(sity, street, house, apartment);


			file_out << data.get_fullAddress() << '\n';
		}
		

		file_in.close();
		file_out.close();

		for (int i = 0; i < size; ++i) {
		delete[]array[4];
		}
		delete[] array;
	}
	else {
		std::cout << "File is (files are) not open!" << '\n';
	}

	return 0;
}
