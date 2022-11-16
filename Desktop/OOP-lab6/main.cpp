#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3) // �������� �� �������� � ��������� ���������� ����������
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream FileInput(argv[1]);
	if (!FileInput.is_open()) // �������� �� ������ � �����
	{
		cout << "No input file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	ofstream FileOutput(argv[2]);
	if (!FileOutput.is_open()) // �������� �� ������ � �����
	{
		cout << "No output file found or could not open!" << endl;
		system("pause");
		return 1;
	}

	cout << "Start" << endl;

	Linked_List list;
	list.Linked_List_Input(FileInput); // �������� �������� ������ � ��� ����������
	FileOutput << "Filled container." << endl;
	list.Linked_List_Output(FileOutput); // ����� � ����

	FileOutput << endl << "Sorted Linked List." << endl;
	list.Sort_Linked_List(); // ���������� ������
	list.Linked_List_Output(FileOutput); // ����� � ���� ���������������� ������

	list.Linked_List_Output_Only_Procedural(FileOutput); // ������������� ����� � ����

	list.~Linked_List(); // ����� �����������
	FileOutput << "Empty container." << endl;
	list.Linked_List_Output(FileOutput);

	cout << "Stop" << endl;
	return 0;
}