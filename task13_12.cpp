#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main1() {
	string str = "some string in this file";
	string strCapitalize = "";
	
	strCapitalize.push_back((char)toupper(str[0]));
	for (int i = 1; i < str.length(); i++) {
		//cout <<(char) toupper(str[i]) << '\n';
		
		if (str[i - 1] == ' ')
			strCapitalize.push_back((char)toupper(str[i]));
		else 
			strCapitalize.push_back(str[i]);
	}

	cout << "First string => " << str << '\n';
	cout << "Result => " << strCapitalize << '\n';

	return 0;
}