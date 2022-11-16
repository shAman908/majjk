#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace Skobina;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);

	cout << "Start" << endl;
	LinkedList list;
	Init(list); //����������� ������
	LinkedList_Input(list, fin); //���������� ������
	fout << "Filled container." << endl;
	LinkedList_Output(list, fout); //������ ���������� ����������

	fout << endl << "Sorted Linked List." << endl;
	Sort_List(list); //��������� ������
	LinkedList_Output(list, fout); //������� � ���� ������������� �������
	Only_Procedural(list, fout); //����� ������� �������������� ������

	Clear(list); //���������� ������
	fout << "Empty container." << endl;
	LinkedList_Output(list, fout); //������, ��� ��������� ������
	cout << "Stop" << endl;
	return 0;
}