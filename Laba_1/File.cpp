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
		cout << "Сохранить в:" << endl;
		getline(cin, file_path);

		if (ifstream(file_path)) {
			cout << "Файл уже существует." << endl;
			cout << "0 - Перезаписать существующий файл." << endl;
			cout << "1 - Повторить ввод." << endl;
			int try_another_file = Get_bool();
			if (try_another_file) {
				continue;
			}
		}

		ofstream my_file(file_path, ofstream::app);

		error_code ec;
		if (!filesystem::is_regular_file(file_path, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		if (!my_file) {
			cout << "Запись запрещена. Повторите ввод." << endl;
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
		cout << "Запись завершена." << endl;
		is_data_saved = true;
	} while (!is_data_saved);
}

void Input_data(string& str) {
	string file_path = "";
	bool is_data_loaded = false;
	int length = 0;
	do {
		cout << "Загрузить из:" << endl;
		getline(cin, file_path);

		if (!ifstream(file_path)) {
			cout << "Файл не существует. Повторите ввод." << endl;
			continue;
		}

		error_code ec;
		if (!filesystem::is_regular_file(file_path, ec)) {
			cout << "Адрес содержит недопустимые значения. Повторите ввод." << endl;
			continue;
		}

		ifstream my_file(file_path);

		if (!my_file) {
			cout << "Загрузка запрещена. Повторите ввод." << endl;
			my_file.close();
			continue;
		}

		string temp = "";

		while (getline(my_file, temp)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
			cout << temp << endl; // выводим на экран
			str += temp;
		}


		cout << "Загрузка завершена." << endl;
		is_data_loaded = true;

		my_file.close();
	} while (!is_data_loaded);
}