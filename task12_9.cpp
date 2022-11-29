#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


void tokenize(std::string const& str, const char delim,
    std::vector<std::string>& out)
{
    // construct a stream from the string
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}

int main() {

	ifstream file("file_12_9.txt");
	
	string dateFile;

    int* result = (int*)malloc(6 * sizeof(int));

	while (getline(file, dateFile)) {

		std::cout << dateFile << "\n";
        cout << "start\n";

        const char delim = ' ';

        std::vector<std::string> out;
        tokenize(dateFile, delim, out);

        int count = 0;
        for (auto& dateFile : out) {
            count++;
            int IntNum = stoi(dateFile);
            std::cout << IntNum + 1 << '\n';
        }

        cout << "end\n";
        
        count = 0;
        for (auto& dateFile : out) {
            
            int IntNum = stoi(dateFile);
            result[count] = IntNum;
            count++;
        }
        
        
        cout << "end\n";
	}
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (result[i] > result[i + 1]) result[i] = result[i] * result[i];
    }

    //for (int i = 0; i < 5; i++) {
    //    cout << result[i] << '\n';
    //}

	file.close();
    
    ofstream fileW("file_12_9.txt");

    for (int i = 0; i < 5; i++) {
        fileW << result[i] << " ";
    }

    fileW.close();


	return 0;
}