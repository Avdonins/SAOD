#pragma once
#include <iostream>
using namespace std;

class books { //класс книги и ее методов
private:
	struct bookInfo { //структура для хранения автора, названия и указателя на следующий элемент объекта
		string author;
		string name;
		books* next = NULL;
	}abooks;
public:
	books() { //конструктор пустой книги
		abooks.author = "";
		abooks.name = "";
		abooks.next = NULL;
	}
	books(string _author, string _name) { //конструктор книги с заданными значениями
		abooks.author = _author;
		abooks.name = _name;
		abooks.next = NULL;
	}
	string getBookAuthor() { return abooks.author; } //метод возвращающий author
	string getBookName() { return abooks.name; } //метод возвращающий name
	void setNext(books* _next) { abooks.next = _next; } //метод устанавливающий указатель next
	books* getNext() { return abooks.next; } //метод возвращающий указатель на следующий элемент
	~books() {}; //деструктор
};