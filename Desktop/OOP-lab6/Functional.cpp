#include "Functional.h"
#include <string>

bool Skobina::Functional::Input(ifstream& FileInput)
{
	if (!Skobina::Language::Input(FileInput)) // проверка на корректность общих данных
	{
		return false;
	}

	string TempString;

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return false;
	}
	if (TempString.length() > 1) // проверка на длину строки
	{
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // проверка на ввод цифры
	{
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
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
	if (TempString == "\0") // проверка на конец строки
	{
		return false;
	}
	if (TempString.length() > 1) // проверка на длину строки
	{
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // проверка на ввод цифры
	{
		return false;
	}

	State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // пропуск оставшихся данных

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