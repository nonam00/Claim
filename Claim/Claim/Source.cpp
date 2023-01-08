#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <Windows.h>

void DeAnonimus(std::string& shapka, std::string name)
{
	std::regex _name("(?:FIOrp|FIO)");
	shapka = regex_replace(shapka.c_str(), _name, name);
}
void set_date(std::string& shapka, std::string key, std::string date)
{
	std::regex _name(key);
	shapka = regex_replace(shapka.c_str(), _name, date);
}

void full(std::ofstream& _template, std::string shapka)
{
	if (_template.is_open())
	{
		_template << shapka;
		_template.close();;
	}
	else
		std::cout << "Error" << std::endl;
}
class Shapka
{
	std::string name;
public:
	Shapka()
	{
		std::cout << "Введите имя ";
		getline(std::cin, name);
	}
	std::string get_name()
	{
		return name;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string otstup = "\t\t\t\t\t\t\t";
	std::string otstup2 = "\t\t\t\t";

	std::ofstream template1("template1.txt");

	std::string shapka1 = otstup + std::string("Директору ООО \"The 2nd Law\"\n")
		+ otstup + std::string("Иванову И.И.\n")
		+ otstup + std::string("от FIOrp\n")
		+ otstup2 + std::string("Заявление\n\n")
		+ std::string("Прошу предоставить мне отпуск с begin_date по end_date.\n\n")
		+ std::string("cur_date") + std::string(otstup) + std::string{ "FIO\n" };

	full(template1, shapka1);

	std::ofstream template2("template2.txt");

	std::string shapka2 = otstup + std::string("Директору ООО \"Banana Galaxy\"\n")
		+ otstup + std::string("Иванову И.И.\n")
		+ otstup + std::string("от FIOrp\n")
		+ otstup2 + std::string("Заявление\n\n")
		+ std::string("Прошу предоставить мне отпуск с begin_date по end_date.\n\n")
		+ std::string("cur_date") + std::string(otstup) + std::string{ "FIO\n" };

	full(template2, shapka2);

	std::ofstream template3("template3.txt");

	std::string shapka3 = otstup + std::string("Директору ООО \"The Resistance\"\n")
		+ otstup + std::string("Иванову И.И.\n")
		+ otstup + std::string("от FIOrp\n")
		+ otstup2 + std::string("Заявление\n\n")
		+ std::string("Прошу предоставить мне отпуск с begin_date по end_date.\n\n")
		+ std::string("cur_date") + std::string(otstup) + std::string{ "FIO\n" };

	full(template3, shapka3);


	std::cout << "Выбирите шаблон заявления. Варианты:\n";
	std::cout << " 1 - Директору ООО \"The 2nd Law\"\n 2 - Директору ООО \"Banana Galaxy\"\n 3 - Директору ООО \"The Resistance\"\n";

	std::string choice;
	getline(std::cin, choice);

	std::string fileName;

	std::ifstream sh;
	std::string shapka;

	if (choice == "1")
	{
		std::cout << shapka1 << std::endl;
		fileName = "The 2nd Law_";
		sh.open("template1.txt");
		getline(sh, shapka, '\0');
		sh.close();
	}
	else if (choice == "2")
	{
		std::cout << shapka2 << std::endl;
		fileName = "Banana Galaxy_";
		sh.open("template2.txt");
		getline(sh, shapka, '\0');
		sh.close();
	}
	else if (choice == "3\0")
	{
		std::cout << shapka3 << std::endl;
		fileName = "The Resistance_";
		sh.open("template3.txt");
		getline(sh, shapka, '\0');
		sh.close();
	}
	else
		std::cout << "Ошибка. Такого варианта не существует" << std::endl;


	Shapka name;
	DeAnonimus(shapka, name.get_name());

	std::string date;

	std::cout << "Введите дату начала отпуска ";
	getline(std::cin, date);
	set_date(shapka, "begin_date", date);

	std::cout << "Введите дату окончания отпуска ";
	getline(std::cin, date);
	set_date(shapka, "end_date", date);

	std::cout << "Введите текущую дату ";
	getline(std::cin, date);
	set_date(shapka, "cur_date", date);

	fileName += name.get_name() + "_" + date + ".txt";
	std::cout << shapka << std::endl;

	std::ofstream shapka_f(fileName);
	full(shapka_f, shapka);

	return 0;
}