#include <iostream>
#include "Algorithms.h"

using namespace std;

double Get_double();

bool Test1() {
	string initial_string = "Слово. Слово после него";
	string res = Find_sentence(initial_string);

	if (res == "   Слово. \n   Слово после него") { return true; }
	else {
		cout << "Ошибка в тесте №1" << endl;
		return false;
	}
}

bool Test2() {
	string initial_string = "Тестируем знаки препинания... Да? Да!";
	string res = Find_sentence(initial_string);

	if (res == "   Тестируем знаки препинания... \n   Да? \n   Да!") { return true; }
	else {
		cout << "Ошибка в тесте №2" << endl;
		return false;
	}
}

bool Test3() {
	string initial_string = "ставим несколько пробелов после точки.            Вот.";
	string res = Find_sentence(initial_string);

	if (res == "   ставим несколько пробелов после точки. \n   Вот.") { return true; }
	else {
		cout << "Ошибка в тесте №3" << endl;
		return false;
	}
}

bool Test4() {
	string initial_string = "Try digits. And english language. And specific symbols#$%^&*(). The End.";
	string res = Find_sentence(initial_string);

	if (res == "   Try digits. \n   And english language. \n   And specific symbols#$%^&*(). \n   The End.") { return true; }
	else {
		cout << "Ошибка в тесте №4" << endl;
		return false;
	}
}

void Module_tests() {
	if (Test1() && Test2() && Test3() && Test4()) {
		cout << "Модульные тесты прошли успешно!" << endl;
	}
}