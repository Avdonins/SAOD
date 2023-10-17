#pragma once
#pragma warning(disable:4996)
#include "NetWork.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class File {
private:
	string address;
public:
	File(string _address) {
		
		address = _address;
	}

	bool InputData(BibNetwork *_menu) {

		string text, name;
		char buffer[100];
		char *f;

		ifstream file(address);

		if (!file.is_open()) return false;

		if (file.get() != EOF) {
			file.getline(buffer, 100);
			text = buffer;
			_menu->Setname(text);
		}
		else return false;
		while (!file.eof()) {
			file.getline(buffer, 100);
			f = strtok(buffer, "_");
			if (f == NULL) continue;
			int num = 0;
			if (f) num = atoi(f);
			_menu->AddBiblios(num);
			f = strtok(NULL, "_");
			while (f) { //пока не пусто
				if (f) text = f;
				f = strtok(NULL, "_");
				if (f) name = f;
				else return false;
				_menu->AddBook(num, text, name);
				f = strtok(NULL, "_");
			}
		}
		file.close();
		return true;
	}

	bool OutputData(BibNetwork *_menu) {
		ofstream file(address);
		if (!file.is_open()) return false;
		file << _menu->GetString();
		file.close();
		return true;
	};

	~File() {};
};
