#pragma once
#include <iostream>
using namespace std;

class books { //����� ����� � �� �������
private:
	struct bookInfo { //��������� ��� �������� ������, �������� � ��������� �� ��������� ������� �������
		string author;
		string name;
		books* next = NULL;
	}abooks;
public:
	books() { //����������� ������ �����
		abooks.author = "";
		abooks.name = "";
		abooks.next = NULL;
	}
	books(string _author, string _name) { //����������� ����� � ��������� ����������
		abooks.author = _author;
		abooks.name = _name;
		abooks.next = NULL;
	}
	string getBookAuthor() { return abooks.author; } //����� ������������ author
	string getBookName() { return abooks.name; } //����� ������������ name
	void setNext(books* _next) { abooks.next = _next; } //����� ��������������� ��������� next
	books* getNext() { return abooks.next; } //����� ������������ ��������� �� ��������� �������
	~books() {}; //����������
};