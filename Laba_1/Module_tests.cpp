#include <iostream>
#include "Algorithms.h"

using namespace std;

double Get_double();

bool Test1() {
	string initial_string = "�����. ����� ����� ����";
	string res = Find_sentence(initial_string);

	if (res == "   �����. \n   ����� ����� ����") { return true; }
	else {
		cout << "������ � ����� �1" << endl;
		return false;
	}
}

bool Test2() {
	string initial_string = "��������� ����� ����������... ��? ��!";
	string res = Find_sentence(initial_string);

	if (res == "   ��������� ����� ����������... \n   ��? \n   ��!") { return true; }
	else {
		cout << "������ � ����� �2" << endl;
		return false;
	}
}

bool Test3() {
	string initial_string = "������ ��������� �������� ����� �����.            ���.";
	string res = Find_sentence(initial_string);

	if (res == "   ������ ��������� �������� ����� �����. \n   ���.") { return true; }
	else {
		cout << "������ � ����� �3" << endl;
		return false;
	}
}

bool Test4() {
	string initial_string = "Try digits. And english language. And specific symbols#$%^&*(). The End.";
	string res = Find_sentence(initial_string);

	if (res == "   Try digits. \n   And english language. \n   And specific symbols#$%^&*(). \n   The End.") { return true; }
	else {
		cout << "������ � ����� �4" << endl;
		return false;
	}
}

void Module_tests() {
	if (Test1() && Test2() && Test3() && Test4()) {
		cout << "��������� ����� ������ �������!" << endl;
	}
}