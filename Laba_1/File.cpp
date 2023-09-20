#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>
#include <Windows.h>
#define INPUT 1
#define RESULTS 2

using namespace std;


bool Get_bool();

void Output_data(int mode, string& str) {
	string file_path = "";
	bool is_data_saved = false;
	do {
		cout << "��������� �:" << endl;
		getline(cin, file_path);

		if (ifstream(file_path)) {
			cout << "���� ��� ����������." << endl;
			cout << "0 - ������������ ������������ ����." << endl;
			cout << "1 - ��������� ����." << endl;
			int try_another_file = Get_bool();
			if (try_another_file) {
				continue;
			}
		}

		ofstream my_file(file_path, ofstream::app);

		error_code ec;
		if (!filesystem::is_regular_file(file_path, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			continue;
		}

		if (!my_file) {
			cout << "������ ���������. ��������� ����." << endl;
			my_file.close();
			continue;
		}

		//my_file.close();
		//my_file.open(file_path, ofstream::trunc);

		if (mode == INPUT) {
			my_file << str << endl;
		}
		if (mode == RESULTS) {
			my_file << str << endl;

		}
		my_file.close();
		cout << "������ ���������." << endl;
		is_data_saved = true;
	} while (!is_data_saved);
}

void Input_data(string& str) {
	string file_path = "";
	bool is_data_loaded = false;
	int length = 0;
	do {
		cout << "��������� ��:" << endl;
		getline(cin, file_path);

		if (!ifstream(file_path)) {
			cout << "���� �� ����������. ��������� ����." << endl;
			continue;
		}

		error_code ec;
		if (!filesystem::is_regular_file(file_path, ec)) {
			cout << "����� �������� ������������ ��������. ��������� ����." << endl;
			continue;
		}

		ifstream my_file(file_path);

		if (!my_file) {
			cout << "�������� ���������. ��������� ����." << endl;
			my_file.close();
			continue;
		}

		string temp = "";

		while (getline(my_file, temp)) { // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
			cout << temp << endl; // ������� �� �����
			str += temp;
		}


		cout << "�������� ���������." << endl;
		is_data_loaded = true;

		my_file.close();
	} while (!is_data_loaded);
}