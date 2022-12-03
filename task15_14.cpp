#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TicTacToe {
public:
	int num = 9;
	string player1 = "A";
	string player2 = "B";

	vector<int> row = { NULL, NULL, NULL };
	vector<vector<int>> situation;

	TicTacToe() {
		situation.push_back(row);
		situation.push_back(row);
		situation.push_back(row);
	}

	bool makeChoice(string player) {
		int userInput;
		cout << "Player " << player << " input on which number you want to put you figure = > ";
		cin >> userInput;

		if (userInput < 0 || userInput > 10) return false;
		else {
			if (player == "A") {
				if (!this->checkChoice(userInput)) return false;
				if (userInput == 1) situation[0][0] = 1;
				if (userInput == 2) situation[0][1] = 1;
				if (userInput == 3) situation[0][2] = 1;
				if (userInput == 4) situation[1][0] = 1;
				if (userInput == 5) situation[1][1] = 1;
				if (userInput == 6) situation[1][2] = 1;
				if (userInput == 7) situation[2][0] = 1;
				if (userInput == 8) situation[2][1] = 1;
				if (userInput == 9) situation[2][2] = 1;
			}
			else {
				if (!this->checkChoice(userInput)) return false;
				if (userInput == 1) situation[0][0] = 2;
				if (userInput == 2) situation[0][1] = 2;
				if (userInput == 3) situation[0][2] = 2;
				if (userInput == 4) situation[1][0] = 2;
				if (userInput == 5) situation[1][1] = 2;
				if (userInput == 6) situation[1][2] = 2;
				if (userInput == 7) situation[2][0] = 2;
				if (userInput == 8) situation[2][1] = 2;
				if (userInput == 9) situation[2][2] = 2;
			}
		}
	}

	void showCurrentSituation() {
		int count = 0;
		for (int i = 0; i < 3; i++) {
			cout << "| ";
			for (int j = 0; j < 3; j++) {
				count++;
				if (situation[i][j] == 1) cout << " X ";
				else if (situation[i][j] == 2) cout << " O ";
				else cout << " " << count << " ";
			}
			cout << " |\n";
		}
	}

	bool checkWin() {
		// s horizontal
		if (situation[0][0] == 1 && situation[0][1] == 1 && situation[0][2] == 1) return true;
		if (situation[0][0] == 2 && situation[0][1] == 2 && situation[0][2] == 2) return true;
		

		if (situation[1][0] == 1 && situation[1][1] == 1 && situation[1][2] == 1) return true;
		if (situation[1][0] == 2 && situation[1][1] == 2 && situation[1][2] == 2) return true;
		

		if (situation[2][0] == 1 && situation[2][1] == 1 && situation[2][2] == 1) return true;
		if (situation[2][0] == 2 && situation[2][1] == 2 && situation[2][2] == 2) return true;
		
		// e horizontal

		// s diagonal
		if (situation[0][0] == 1 && situation[1][1] == 1 && situation[2][2] == 1) return true;
		if (situation[0][0] == 2 && situation[1][1] == 2 && situation[2][2] == 2) return true;
		

		if (situation[0][2] == 1 && situation[1][1] == 1 && situation[2][0] == 1) return true;
		if (situation[0][2] == 2 && situation[1][1] == 2 && situation[2][0] == 2) return true;
		
		// e diagonal

		// s verical
		if (situation[0][0] == 1 && situation[1][0] == 1 && situation[2][0] == 1) return true;
		if (situation[0][0] == 2 && situation[1][0] == 2 && situation[2][0] == 2) return true;
		

		if (situation[0][1] == 1 && situation[1][1] == 1 && situation[2][1] == 1) return true;
		if (situation[0][1] == 2 && situation[1][1] == 2 && situation[2][1] == 2) return true;

		if (situation[2][2] == 1 && situation[2][2] == 1 && situation[2][2] == 1) return true;
		if (situation[2][2] == 2 && situation[2][2] == 2 && situation[2][2] == 2) return true;
		// e vertical

		return false;
	}

	bool checkChoice(int userInput) {
		if (userInput == 1) {
			if (situation[0][0] == 1 || situation[0][0] == 2) return false;
			else return true;
		}
		else if (userInput == 2){
			if (situation[0][1] == 1 || situation[0][1] == 2) return false;
			else return true;
		}
		else if (userInput == 3) {
			if (situation[0][2] == 1 || situation[0][2] == 2) return false;
			else return true;
		}
		else if (userInput == 4) {
			if (situation[1][0] == 1 || situation[1][0] == 2) return false;
			else return true;
		}
		else if (userInput == 5) {
			if (situation[1][1] == 1 || situation[1][1] == 2) return false;
			else return true;
		}
		else if (userInput == 6) {
			if (situation[1][2] == 1 || situation[1][2] == 2) return false;
			else return true;
		}
		else if (userInput == 7) {
			if (situation[2][0] == 1 || situation[2][0] == 2) return false;
			else return true;
		}
		else if (userInput == 8) {
			if (situation[2][1] == 1 || situation[2][1] == 2) return false;
			else return true;
		}
		else {
			if (situation[2][2] == 1 || situation[2][2] == 2) return false;
			else return true;
		}
	}

	void startGame() {
		cout << "\t\t WELCOME TO GAME!!! \n";
		this->showCurrentSituation();

		string currentPlayer = player1;
		while(true) {
			if (!makeChoice(currentPlayer)) {
				cout << "Something wrong with your input, try again please\n";
				continue;
			}
			this->showCurrentSituation();

			if (this->checkWin()) {
				cout << "Player " << currentPlayer << " win!!!\nCongratulations!!!!";
				break;
			}

			if (currentPlayer == player1) currentPlayer = player2;
			else currentPlayer = player1;
		}
	}
};

int main33() {
	TicTacToe point;
	point.startGame();

	return 0;
}