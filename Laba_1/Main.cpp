#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include "Main.h"
#include "Algorithms.h"
#include <string>

using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {

		Greeting();

		cout << "Провести модульные тесты?\n1 - Да\n2 - Нет" << endl;
		int choice = Check_choice(TWO_ELEMENTS);
		if (choice == YES) {
			Module_tests();
		}

		Menu();
		string initial_str = "";
		choice = Check_choice(THREE_ELEMENTS);
		switch (choice) {
		case 1: {
			cout << "Введите текст: " << endl;
			getline(cin, initial_str);
			break;
		}
		case 2: {
			initial_str = "Слово. Предложение из нескольких слов. Несколько пробелов после точки.    Другой знак препинания? Может быть... Конец!";
			cout << initial_str << endl;
			break;
		}
		case 3: {
			Input_data(initial_str);
			break;
		}
		}
		string res = Find_sentence(initial_str);
		cout << "\nРезультат работы программы: \n" << res << endl;


		cout << "\nСохранить данные ввода?\n1 - сохранить\n2 - не сохранять" << endl;
		choice = Check_choice(2);
		if (choice == YES) {
			Output_data(INPUT, initial_str);
		};
		cout << "\nСохранить результаты?\n1 - сохранить\n2 - не сохранять" << endl;
		choice = Check_choice(2);
		if (choice == YES) {
			Output_data(RESULTS, res);
		};
		cout << "Нажмите Enter, для того чтобы повторить программу.\n" "'0' - для завершения программы." << endl;
	} while (getchar() != '0');
}