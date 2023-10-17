#pragma once
#include "BOOKS.h";
#include <iomanip>
#include <sstream>

using namespace std;

class Biblio { //����� ���������� � �� �������
private:
	struct biblioInfo { //��������� ���������� ���������� ����� ���������� � ������������ ������� ��������� ������
		int number;
		books* HEAD;
	}biblios;
public:
	int GetText() { return biblios.number; } //����� ������������ ����� ����������
	books* getHead() { return biblios.HEAD; } //����� ������������ ��������� �� ������������ ������� �������� ������

	Biblio() {  //����������� ������ ����������
		biblios.number = 1000;
		biblios.HEAD = new books();
	}
	Biblio(int _num) {  //����������� ���������� � �������� �������
		biblios.number = _num;
		biblios.HEAD = new books();
	}
	int getNum() { return biblios.number; }  //����� ������������ ����� ����������
	void setNum(int _num) { biblios.number = _num; }  //����� ��������������� ����� ����������
	bool addBook(string _author, string _name) {  //����� ���������� ����� ����� � ��������� ����������
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
	books* FindBook(string _author, string _name) {  //����� ������ ����� � ��������� ����������
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

	bool delBook(string _author, string _name) {  //����� �������� ����� � �������� ���������
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
	void delAllBook() {  //����� �������� ���� ����
		books* currBook = biblios.HEAD->getNext();
		books* temp = NULL;
		while (currBook != NULL) {
			temp = currBook;
			currBook = currBook->getNext();
			delete(temp);
		}
	}
	void ShowBooks() {  //����� ������ ���� ����
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

	string GetString() {  //�����, ���������� ��� ����� � ���� ������ ��� ������ � ����
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

	~Biblio() {  //����������
		delAllBook();
	};

};