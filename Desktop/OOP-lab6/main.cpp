#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3) // проверка на передачу в программу корректных параметров
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream FileInput(argv[1]);
	if (!FileInput.is_open()) // проверка на доступ к файлу
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	ofstream FileOutput(argv[2]);
	if (!FileOutput.is_open()) // проверка на доступ к файлу
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	list.Linked_List_Input(FileInput); // создание связного списка и его заполнение
	FileOutput << "Filled container." << endl;
	list.Linked_List_Output(FileOutput); // вывод в файл

	FileOutput << endl << "Sorted Linked List." << endl;
	list.Sort_Linked_List(); // сортировка списка
	list.Linked_List_Output(FileOutput); // вывод в файл отсортированного списка

	list.Linked_List_Output_Only_Procedural(FileOutput); // фильтрованный вывод в файл

	list.~Linked_List(); // вызов деструктора
	FileOutput << "Empty container." << endl;
	list.Linked_List_Output(FileOutput);

	cout << "Stop" << endl;
	return 0;
}