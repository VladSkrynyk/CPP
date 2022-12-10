#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
	string name;
	string author;
	int numberPages;
	int Date;

public:
	Book(string n, string a, int n1, int d) {
		this->name = n;
		this->author = a;
		this->numberPages = n1;
		this->Date = d;
	}

	string getName() {
		return this->name;
	}

	string getAuthor() {
		return this->author;
	}

};

int main() {
	int n;
	cout << "Input number of books => ";
	cin >> n;

	vector<Book> arr;

	for (int i = 0; i < n; i++) {
		string name;
		string author;
		int numberPages;
		int Date;

		cout << "Input name => ";
		cin >> name;

		cout << "Input author => ";
		cin >> author;

		cout << "Input name => ";
		cin >> numberPages;

		cout << "Input name => ";
		cin >> Date;
		
		Book b(name, author, numberPages, Date);
	}

	string userName;
	cout << "=> ";
	cin >> userName;

	for (int i = 0; i < n; i++) {
		if (arr[i].getName() == userName) {
			cout << "Your book info:" << arr[i].getAuthor << " " << arr[i].getName();
		}
	}

	return 0;
}