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

		cout << "�������� ��������� �����?\n1 - ��\n2 - ���" << endl;
		int choice = Check_choice(TWO_ELEMENTS);
		if (choice == YES) {
			Module_tests();
		}

		Menu();
		string initial_str = "";
		choice = Check_choice(THREE_ELEMENTS);
		switch (choice) {
		case 1: {
			cout << "������� �����: " << endl;
			getline(cin, initial_str);
			break;
		}
		case 2: {
			initial_str = "�����. ����������� �� ���������� ����. ��������� �������� ����� �����.    ������ ���� ����������? ����� ����... �����!";
			cout << initial_str << endl;
			break;
		}
		case 3: {
			Input_data(initial_str);
			break;
		}
		}
		string res = Find_sentence(initial_str);
		cout << "\n��������� ������ ���������: \n" << res << endl;


		cout << "\n��������� ������ �����?\n1 - ���������\n2 - �� ���������" << endl;
		choice = Check_choice(2);
		if (choice == YES) {
			Output_data(INPUT, initial_str);
		};
		cout << "\n��������� ����������?\n1 - ���������\n2 - �� ���������" << endl;
		choice = Check_choice(2);
		if (choice == YES) {
			Output_data(RESULTS, res);
		};
		cout << "������� Enter, ��� ���� ����� ��������� ���������.\n" "'0' - ��� ���������� ���������." << endl;
	} while (getchar() != '0');
}