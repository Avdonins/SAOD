#pragma once
#include "compBibliosS.h"
using namespace std;

class BibNetwork { //класс библиотечной сети и ее методы
private:
	string name; //название библиотечной сети
	compBiblio biblios;

public:
	BibNetwork(string _name) { name = _name; } //конструктор, устанавливающий название библиотечной сети
	BibNetwork() { name = "-Не указано-"; } //конструктор пустого названия библиотечной сети

	void Setname(string _name) { name = _name; } //метод ввода названия библиотечной сети
	string Getname() { return name; } //метод, возвращающий название библиотечной сети

	bool AddBiblios(int _num) { //добавление новой библиотеки
		if (biblios.addBibliot(_num)) return true;
		else return false;
	};

	bool FindBiblio(int _num) { //поиск библиотеки по номеру
		if (biblios.FindBibliot(_num) != -1) return true;
		else return false;
	};

	bool DelBiblio(int _num) { return biblios.delBibliot(_num); }; //удаление заданной библиотеки

	bool AddBook(int _num, string _author, string _name) { return biblios.addBookToBib(_num, _author, _name); }; //добавить книгу в библиотеку

	bool FindBook(int _num, string _author, string _name) { //найти книгу в библиотеке
		if (biblios.FindBookInBib(_num, _author, _name) == true) return true;
		else return false;
	};

	bool DelBook(int _num, string _author, string _name) { return biblios.delBookToBib(_num, _author, _name); }; //удалить книгу из библиотеки

	void Show() //вывод всей таблицы на экран
	{
		int l = name.length();
		cout << "\n ||-----------------------------------------------------------||\n";
		cout << " ||             Библиотечная сеть '" << name << "'" << setw(28 - l) << "||";
		cout << "\n ||-----------------------------------------------------------||";
		cout << "\n ||     Номер     |" << "              Книги в наличии              ||";
		cout << "\n ||   Библиотеки  |" << "       Автор       |       Название        ||\n";
		biblios.showAllBib();
		cout << " ||-----------------------------------------------------------||\n";
	};

	string GetString() { return " " + name + '\n' + biblios.GetString(); }; //формирование таблицы в виде строки 

	~BibNetwork() {};
};