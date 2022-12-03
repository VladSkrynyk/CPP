#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	string Name;
	string SurName;

	void InputPerson() {
		cout << "Input name of person => ";
		cin >> Name;

		cout << "Input surname of person => ";
		cin >> SurName;
	}

	void ShowPerson() {
		cout << "Peron with name: " << Name << " and surname: " << SurName << '\n';
	}
};

class Address:public Person {
public:
	string City;
	string Street;
	int NumberHome;
	int Flat;

	void InputAddress() {
		cout << "Input city => ";
		cin >> City;

		cout << "Input street => ";
		cin >> Street;

		cout << "Input number of home => ";
		cin >> NumberHome;

		cout << "Input flat => ";
		cin >> Flat;
	}

	void ShowAddress() {
		cout << "Address: " << City << ", " << Street << ", " << NumberHome << ", " << Flat << '\n';
	}
};

class EAddress :public Person {
public:
	string Email;
	string AddressPage;
	int Phone;

	void InputEAddress() {
		cout << "Input email => ";
		cin >> Email;

		cout << "Input addresspage => ";
		cin >> AddressPage;

		cout << "Input phone => ";
		cin >> Phone;
	}

	void ShowEAddress() {
		cout << "Address: " << Email << ", " << AddressPage << ", " << Phone << '\n';
	}
};

int main() {
	ofstream fileW("t16_15.txt");
	int number;

	cout << "Input number of users => ";
	cin >> number;

	for (int i = 0; i < number; i++) {
		EAddress e;
		e.InputEAddress();
		string str;
		str += e.Email;
		str += " ";
		str += e.AddressPage;
		str += " ";
		str += to_string(e.Phone);
		str += '\n';

		fileW << str;
	}

	fileW.close();

	string userInputCity;
	string userInputEmail;
	vector<EAddress> arrayAddress;

	cout << "Input city => ";
	cin >> userInputCity;

	cout << "Input email => ";
	cin >> userInputCity;

	ifstream file("t16_15.txt");
	string dateFile;

	while (getline(file, dateFile)) {
		//std::cout << dateFile << "\n";
		std::string temp = "";
		std::string temp1 = "";
		std::string temp2 = "";
		std::string temp3 = "";

		int count = 0;
		for (int i = 0; i < (int)dateFile.size(); i++) {
			if (dateFile[i] != ' ') {
				temp += dateFile[i];
			}
			else {
				count++;
				//std::cout << temp << "\n";
				if (count == 1) temp1 = temp;
				else if (count == 2) temp2 = temp;
				temp = "";
			}
		}
		count++;
		//std::cout << "Test " << count << "\n";
		if (count == 3) temp3 = temp;

		EAddress a;
		a.Email = temp1;
		a.AddressPage = temp2;
		a.Phone = stoi(temp3);
		if (temp1 == userInputCity && temp3 == userInputEmail) arrayAddress.push_back(a);
	}

	file.close();

	return 0;
}