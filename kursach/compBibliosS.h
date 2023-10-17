#pragma once
#include "BiblioS.h"
using namespace std;
#define ARR_SIZE 10

class compBiblio { //класс композиции библиотек и его методы
private:
	Biblio bibs[ARR_SIZE]; //массив библиотек
	int count = 0; //кол-во библиотек в массиве на текущий момент
public:
	int FindBibliot(int _num) {  //метод поиска библиотеки с заданным номером
		bool flag = false;
		int i = 0;
		while(i < count){
			if (bibs[i].getNum() == _num) {
				flag = true;
				break;
			}
			else i++;
		}
		if (flag == true) return i;
		else return -1;
	}
	bool FindBookInBib(int _num, string _author, string _name) {  //метод поиска книги с заданным названием и автором в заданной библиотеке
		int z, n = 0;
		while (n < count) {
			if (bibs[n].getNum() == _num) break;
			else n++;
		}
		if (bibs[n].FindBook(_author, _name) != NULL) return true;
		else return false;
	}
	bool addBibliot(int _num) {  //метод добавления библиотеки
		for (int i = 0; i < count; i++) if (_num == bibs[i].getNum()) return false;
		if (count == ARR_SIZE) return false;
		else {
			if (count == 0) {
				bibs[0].setNum(_num);
				count++;
			}
			else {
				int i = 0;
				while (_num > bibs[i].getNum()) i++;
				for (int j = count; j > i; j--) {
					bibs[j] = bibs[j - 1];
				}
				bibs[i] = NULL;
				bibs[i].setNum(_num);
				count++;
			}
		}
	}
	bool addBookToBib(int _num, string _author, string _name) {  //метод добавления книги с заданным названием и автором в заданную библиотеку
		int b = FindBibliot(_num);
		if (b == -1) return false;
		else {
			bibs[b].addBook(_author, _name);
			return true;
		}
	}
	bool delBookToBib(int _num, string _author, string _name) { //метод удаления книги с заданным названием и автором из заданной библиотеки
		int b = FindBibliot(_num);
		if (b == -1) return false;
		else {
			if (bibs[b].delBook(_author, _name)) return true;
			else return false;
		}
	}
	bool delBibliot(int _num) { //удаление библиотеки
		int b = FindBibliot(_num);
		if (b == -1) return false;
		else {
			for (int i = b; i < count; i++) {
				bibs[i] = bibs[i + 1];
			}
			count--;
			bibs[count] = NULL;
			bibs[count].setNum(1000);
			return true;
		}
	}
	bool showAllBib() { //метод вывода всех библиотек и их книг
		if (count == 0) return false;
		else {
			for (int i = 0; i < count; i++) {
				cout << " ||-----------------------------------------------------------||\n";
				cout << " ||Библиотека №" << setw(2) << bibs[i].getNum() << setw(2) << "|";
				bibs[i].ShowBooks();
			}
			return true;
		}
	}
	string GetString() {  //метод, собирающий все номера библиотек в одну строку для записи в файл
		string str = "";
		for (int i = 0; i < count; i++) {
			stringstream ss;
			ss << bibs[i].GetText();
			str += ss.str();
			str += bibs[i].GetString();
			str += '\n';
		}
		return str;
	}
	~compBiblio() {}; //деструктор
};
