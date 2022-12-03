//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main() {
//
//	string dateFile;
//	char userGroup;
//	vector<float> Marks;
//	fstream file("t14_8.txt");
//
//	cout << "Input group => ";
//	cin >> userGroup;
//	
//	int count = 0;
//	while (getline(file, dateFile)) {
//		//cout << dateFile[2] << "\n";
//		if (userGroup == dateFile[4]) {
//			count++;
//			for (int i = 6; i < dateFile.size(); i += 2) {
//				float currentMark = stof(dateFile[i]);
//				Marks.push_back(currentMark);
//			}
//			//cout << "Yes ";
//			
//		}
//	}
//	file.close();
//
//	float sum = 0;
//	for (int i = 0; i < Marks.size(); i++) {
//		sum += Marks[i];
//	}
//
//	cout << "Average mark in group " << userGroup << " is => " << sum / count << '\n';
//
//	return 0;
//}