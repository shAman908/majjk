#include "Proc.h"
#include <string>

bool Skobina::Procedural::Input(ifstream& FileInput)
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
	int State = stoi(TempString);
	getline(FileInput, TempString, '\n'); // пропуск оставшихся данных

	if (State > 0)
	{
		AbstractType = true;
	}
	else
	{
		AbstractType = false;
	}
	return true;
}


void Skobina::Procedural::Output(ofstream& FileOutput)
{
	FileOutput << "It is Procedural programming language: Abstract data types is ";
	if (AbstractType)
	{
		FileOutput << "present, ";
	}
	else
	{
		FileOutput << "missing, ";
	}

	Skobina::Language::Output(FileOutput);
}


void Skobina::Procedural::Output_Only_Procedural(ofstream& FileOutput)
{
	Skobina::Procedural::Output(FileOutput);
}