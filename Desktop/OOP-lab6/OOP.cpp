#include "OOP.h"
#include <string>

bool Skobina::Object_Oriented::Input(ifstream& FileInput)
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
		return false;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // проверка на ввод цифры
	{
		return false;
	}
	int state = stoi(TempString);

	getline(FileInput, TempString, '\n'); // пропуск оставшихся данных

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