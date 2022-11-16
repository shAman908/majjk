#include "Functional.h"
#include <string>

bool Skobina::Functional::Input(ifstream& FileInput)
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
		getline(FileInput, TempString, '\n'); // ������� ���������� ������
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // �������� �� ���� �����
	{
		getline(FileInput, TempString, '\n'); // ������� ���������� ������
		return false;
	}

	int State = stoi(TempString);
	if (State > 0)
	{
		LazyCalculations = true;
	}
	else
	{
		LazyCalculations = false;
	}

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

	State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // ������� ���������� ������

	switch (State)
	{
	case 1:
		Type = Functional::Typification::STRICT;
		return true;
	case 2:
		Type = Functional::Typification::DYNAMIC;
		return true;
	default:
		return false;
	}
}


void Skobina::Functional::Output(ofstream& FileOutput)
{
	FileOutput << "It is Functional programming language: Support \"lazy\" calculations is ";
	if (LazyCalculations)
	{
		FileOutput << "present, ";
	}
	else
	{
		FileOutput << "missing, ";
	}

	FileOutput << "Typification is ";
	switch (Type)
	{
	case Functional::Typification::STRICT:
		FileOutput << "strict, ";
		break;
	case Functional::Typification::DYNAMIC:
		FileOutput << "dynamic, ";
		break;
	default:
		break;
	}

	Skobina::Language::Output(FileOutput);
}