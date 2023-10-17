//Ковалёв Роман. Группа 4211. Вариант 47.17
//47. Статический упорядоченный список упорядоченный динамических списков
//17. Библиотечная сеть (название) - композиция библиотек (номера)
//	  Библиотека - композиция книг (автор, название)

#include <iostream>
#include <windows.h> 
#include <string>
#include "NetWork.h"
#include "File.h"

BibNetwork* network = NULL; // указатель на меню
File file("D:\\Pets\\cpp\\SAOD\\main_file.txt"); //путь к файлу

int failure() { //метод обработки ошибок ввода команды
	int a;
	while (!(cin >> a) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "\n ||Ошибка ввода! Повторите попытку: ";
	}
	return a;
}

void AddNewBiblio() { //добавить новую библиотеку
	int num;
	bool flag = false;
	network->Show();
	cout << " ||Номер новой библиотеки: ";
	scanf_s("%d", &num);
	flag = network->AddBiblios(num);
	system("cls");
	network->Show();
	if (flag) cout << " <<Успешно! Нажмите Enter, чтобы продолжить>>\n";
	else cout << " <<Ошибка! Нажмите Enter, чтобы продолжить>>\n";
	getchar(); getchar();
	system("cls");
	network->Show();
}

void FindBiblioNum() { //найти библиотеку по номеру
	int num;
	system("cls");
	network->Show();
	cout << " ||Введите номер библиотеки, которую хотите найти: ";
	scanf_s("%d", &num);
	if (network->FindBiblio(num)) cout << " ||Библиотека найдена\n";
	else cout << " ||Библиотека не найдена\n";
}

void DelBiblioNum() { //удалить библиотеку с заданным номером
	int num;
	system("cls");
	network->Show();
	cout << " ||Введите номер библиотеки, который надо удалить: ";
	scanf_s("%d", &num);
	if (network->DelBiblio(num)) {
		system("cls");
		network->Show();
		cout << " <<Успешно! Библиотека удалена. Нажмите Enter, чтобы продолжить>>\n";
	}
	else {
		cout << " <<Ошибка! Библиотека не удалена. Нажмите Enter, чтобы продолжить>>\n";
	}
	getchar(); getchar();
	system("cls");
	network->Show();
}

void AddNewBook() { //добавить новую книгу в заданную библиотеку
	string author, name;
	int num;
	system("cls");
	network->Show();
	cout << " ||Введите номер библиотеки, в которую добавим книгу: ";
	scanf_s("%d", &num);

	if (network->FindBiblio(num)) {
		cout << " ||Введите автора: ";
		while (cin.get() != '\n');
		getline(cin, author);
		cout << " ||Введите название: ";
		getline(cin, name);
		if (network->AddBook(num, author, name)) {
			system("cls");
			network->Show();
			cout << " <<Успешно! Книга добавлена. Нажмите Enter, чтобы продолжить>>\n";
		}
		else cout << " <<Ошибка! Книга добавлена. Нажмите Enter, чтобы продолжить>>\n";
		getchar();
		system("cls");
		network->Show();
	}
	else {
		cout << " <<Ошибка! Библиотека не найдена. Нажмите Enter, чтобы продолжить>>\n";
		getchar(); getchar();
		system("cls");
		network->Show();
	}
}

void FindABook() { //найти книгу в библиотеке
	string _author, _name;
	int num;
	system("cls");
	network->Show();
	cout << " ||Введите номер библиотеки, в которой ищем: ";
	scanf_s("%d", &num);
	if (network->FindBiblio(num)) {
		cout << " ||Введите автора: ";
		while (cin.get() != '\n');
		getline(cin, _author);
		cout << " ||Введите название: ";
		getline(cin, _name);
		if (network->FindBook(num, _author, _name)) {
			system("cls");
			network->Show();
			cout << " <<Успешно! Книга найдена. Нажмите Enter, чтобы продолжить>>\n";
		}
		else cout << " <<Ошибка! Книга не найдена. Нажмите Enter, чтобы продолжить>>\n";
		getchar();
		system("cls");
		network->Show();
	}
	else {
		cout << " <<Ошибка! Библиотека не найдена. Нажмите Enter, чтобы продолжить>>\n";
		getchar(); getchar();
		system("cls");
		network->Show();
	}
}

void DelABook() { //удалить книгу в библиотеке
	string _author, _name;
	int num;
	system("cls");
	network->Show();
	cout << " ||Введите номер библиотеки, в которой удаляем книгу: ";
	scanf_s("%d", &num);

	if (network->FindBiblio(num)) {
		cout << " ||Введите автора: ";
		while (cin.get() != '\n');
		getline(cin, _author);
		cout << " ||Введите название: ";
		getline(cin, _name);
		if (network->DelBook(num, _author, _name)) {
			system("cls");
			network->Show();
			cout << " <<Успешно! Книга удалена. Нажмите Enter, чтобы продолжить>>\n";
		}
		else cout << " <<Ошибка! Книга не удалена. Нажмите Enter, чтобы продолжить>>\n";
		getchar();
		system("cls");
		network->Show();
	}
	else {
		cout << " <<Ошибка! Библиотека не найдена. Нажмите Enter, чтобы продолжить>>\n";
		getchar(); getchar();
		system("cls");
		network->Show();
	}
}


int main() {
	system("color 70");
	setlocale(0, "");
	SetConsoleCP(1251);	// задаем кодировку для вывода символов на экран
	SetConsoleOutputCP(1251); //задаем кодировку для ввода символов с клавиатуры в консоль
	int n;
	network = new BibNetwork();
	string headline = "";
	if (!file.InputData(network)) {
		cout << " Ошибка загрузки файла (файл не найден или он пуст)!\n Введите название библиотечной сети: ";
		cin >> headline;
		network->Setname(headline);
	}
	network->Show();
	while (true) {

		cout << " ||===========================================================||\n";
		cout << " ||                Выберите команду из списка:                ||\n";
		cout << " ||[1] Добавить новую библиотеку                              ||\n";
		cout << " ||[2] Найти библиотеку по номеру                             ||\n";
		cout << " ||[3] Удалить библиотеку                                     ||\n";
		cout << " ||[4] Добавить новую книгу в библиотеку                      ||\n";
		cout << " ||[5] Найти книгу в библиотеке                               ||\n";
		cout << " ||[6] Удалить книгу из библиотеки                            ||\n";
		cout << " ||[7] Изменить название библиотечной сети                    ||\n";
		cout << " ||[8] Очистить всё                                           ||\n";
		cout << " ||===========================================================||\n";
		cout << " ||[0] Выход из программы                                     ||\n";
		cout << " ||>> ";
		n = failure();
		while ((n < 0) || (n > 8)) {
			cout << " ||Ошибка ввода! Повторите попытку: "; n = failure();
		}
		switch (n) {
		case 1:
			system("cls");
			AddNewBiblio();
			break;
		case 2:
			FindBiblioNum();
			cout << " <<Нажмите Enter, чтобы продолжить>>\n";
			getchar(); getchar();
			system("cls");
			network->Show();
			break;
		case 3:
			DelBiblioNum();
			break;
		case 4:
			AddNewBook();
			break;
		case 5:
			FindABook();
			break;
		case 6:
			DelABook();
			break;
		case 7:
			cout << " ||Введите новое название: ";
			cin.clear(); cin.ignore(32767, '\n'); cin >> headline;
			network->Setname(headline);
			system("cls");
			network->Show();
			break;
		case 8:
			system("cls");
			cout << " <<Очищено...";
			delete network;
			cout << " Успешно!>>";
			cout << "\n Введите название библиотечной сети: ";
			cin >> headline;
			network = new BibNetwork(headline);
			system("cls");
			network->Show();
			break;
		}
		if (n == 0) {
			cout << " ||Сохранить в файл?\n ||1: Да, 0: Нет: "; n = failure();
			while ((n < 0) || (n > 1)) {
				cout << " ||Ошибка ввода! Повторите попытку: "; n = failure();
			}
			if (n == 1) {
				if (file.OutputData(network)) cout << " ||Данные успешно обновлены\n\n ||Выход из программы...";
				else cout << "\n Ошибка! Файл не сохранён\n\n ||Выход из программы...";
				delete network;
				Sleep(3000);
				break;
			}
			else {
				delete network;
				break;
			}
		}
	}
}
