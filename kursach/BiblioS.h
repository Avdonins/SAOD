#pragma once
#include "BOOKS.h";
#include <iomanip>
#include <sstream>

using namespace std;

class Biblio { //класс библиотеки и ее методов
private:
	struct biblioInfo { //структура библиотеки содержащая номер библиотеки и заголовочный элемент дочернего списка
		int number;
		books* HEAD;
	}biblios;
public:
	int GetText() { return biblios.number; } //метод возвращающий номер библиотеки
	books* getHead() { return biblios.HEAD; } //метод возвращающий указатель на заголовочный элемент связного списка

	Biblio() {  //конструктор пустой библиотеки
		biblios.number = 1000;
		biblios.HEAD = new books();
	}
	Biblio(int _num) {  //конструктор библиотеки с заданным номером
		biblios.number = _num;
		biblios.HEAD = new books();
	}
	int getNum() { return biblios.number; }  //метод возвращающий номер библиотеки
	void setNum(int _num) { biblios.number = _num; }  //метод устанавливающий номер библиотеки
	bool addBook(string _author, string _name) {  //метод добавления новой книги с заданными значениями
		if (biblios.HEAD->getNext() == NULL) {
			books* temp = new books(_author, _name);
			biblios.HEAD->setNext(temp);
			return true;
		}
		else {
			books* prev = biblios.HEAD;
			books* currBook = biblios.HEAD->getNext();
			books* temp = new books(_author, _name);
			while ((currBook != NULL) && (_author > currBook->getBookAuthor())) {
				currBook = currBook->getNext();
				prev = prev->getNext();
			}
			if (currBook == NULL) {
				prev->setNext(temp);
			}
			else {
				prev->setNext(temp);
				temp->setNext(currBook);
			}
			return true;
		}
	}
	books* FindBook(string _author, string _name) {  //метод поиска книги с заданными значениями
		books* currBook = biblios.HEAD->getNext();
		while (currBook != NULL) {
			if (currBook->getBookAuthor() != _author);
			else {
				if (currBook->getBookName() != _name);
				else break;
			}
			currBook = currBook->getNext();
		}
		if (currBook != NULL) return currBook;
		else return NULL;
	}

	bool delBook(string _author, string _name) {  //метод удаления книги с заданным значением
		books* currBook = FindBook(_author, _name);
		if (currBook == NULL) return false;
		else {
			books* prev = biblios.HEAD;
			while (prev->getNext() != currBook) prev = prev->getNext();
			prev->setNext(currBook->getNext());
			delete currBook;
			return true;
		}
	}
	void delAllBook() {  //метод удаления всех книг
		books* currBook = biblios.HEAD->getNext();
		books* temp = NULL;
		while (currBook != NULL) {
			temp = currBook;
			currBook = currBook->getNext();
			delete(temp);
		}
	}
	void ShowBooks() {  //метод вывода всех книг
		if (biblios.HEAD->getNext() == NULL) cout << setw(20) << "|" << setw(26) << "||\n";
		else {
			books* currBook = biblios.HEAD->getNext();
			int i = 0;
			unsigned int lA, lN, aroundA, aroundN = 0;
			while (currBook != NULL) {
				lA = currBook->getBookAuthor().length();
				lN = currBook->getBookName().length();
				if (i >= 1) cout << " ||" << setw(16) << right << "|";
				aroundA = ((19 - lA) / 2) + lA;
				aroundN = ((23 - lN) / 2) + lN;
				cout << setw(aroundA) << currBook->getBookAuthor() << setw(20 - aroundA) << "|" << setw(aroundN) << currBook->getBookName() << setw(25 - aroundN) << "||" << "\n";
				currBook = currBook->getNext();
				i++;
			}
		}
	}

	string GetString() {  //метод, собирающий все книги в одну строку для записи в файл
		books* pCurrent = biblios.HEAD->getNext();
		string str = "";
		while (pCurrent != NULL) {
			stringstream ss;
			ss << pCurrent->getBookAuthor();
			str += "_";
			str += ss.str();
			str += "_";
			str += pCurrent->getBookName();
			pCurrent = pCurrent->getNext();
		}
		return str;
	}

	~Biblio() {  //деструктор
		delAllBook();
	};

};