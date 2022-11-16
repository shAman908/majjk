#include "OOP.h"
#include <string>

bool Skobina::Object_Oriented::Input(ifstream& FileInput)
{
	if (!Skobina::Language::Input(FileInput)) // �������� �� ������������ ����� ������
	{
		return false;
	}

	string TempString;

	FileInput >> TempString;
	if (TempString == "\0") // �������� �� ����� ������
	{
		return false;
	}
	if (TempString.length() > 1) // �������� �� ����� ������
	{
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // �������� �� ���� �����
	{
		return false;
	}
	int state = stoi(TempString);

	getline(FileInput, TempString, '\n'); // ������� ���������� ������

	switch (state)
	{
	case 1:
		Number = Object_Oriented::Inheritance::SINGLE;
		return true;
	case 2:
		Number = Object_Oriented::Inheritance::MULTIPLE;
		return true;
	case 3:
		Number = Object_Oriented::Inheritance::INTERFACE;
		return true;
	default:
		return false;
	}
}


void Skobina::Object_Oriented::Output(ofstream& FileOutput)
{
	FileOutput << "It is Object-oriented programming language: Inheritance is ";
	switch (Number)
	{
	case Object_Oriented::Inheritance::SINGLE:
		FileOutput << "single, ";
		break;
	case Object_Oriented::Inheritance::MULTIPLE:
		FileOutput << "multiple, ";
		break;
	case Object_Oriented::Inheritance::INTERFACE:
		FileOutput << "interface, ";
		break;
	default:
		break;
	}

	Skobina::Language::Output(FileOutput);
}