#include <iostream>
#include <string>
#include <regex>
using namespace std;

double Get_double() {
	double input = 0;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "¬ведите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

bool Get_bool() {
	bool input = false;
	cin >> input;
	while (cin.fail()) {
		while (getchar() != '\n');
		cin.clear();
		cout << "¬ведите число." << endl;
		cin >> input;
	}
	while (getchar() != '\n');
	return input;
}

int Check_choice(int q_elements) {
	regex r;
	if (q_elements == 2)  r = "^[12]$";
	if (q_elements == 3)  r = "^[123]$";
	string input;
	int choice = 0;
	bool again = false;
	do {
		getline(cin, input);
		if (regex_match(input.c_str(), r)) {
			choice = stoi(input);
			again = false;
		}
		else {
			cout << "ќшибка ввода, попробуйте еще раз" << endl;
			again = true;
		}
	} while (again == true);
	return choice;
}


string Find_sentence(string initial_str) {

	regex dot("[\\.+]\\s+");
	regex question_mark("[?]\\s+");
	regex exclamation_mark("[!]\\s+");
	smatch sm;



	string res = "";
	res = regex_replace(initial_str, question_mark, "? \n   ");	// ставим абзацы после вопросительного знака
	res = regex_replace(res, exclamation_mark, "? \n   ");		// ставим абзацы после восклицательного знака
	res = "   " + regex_replace(res, dot, "\. \n   ");			// ставим абзацы после точек
	return res;


}


