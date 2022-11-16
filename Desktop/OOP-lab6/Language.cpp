#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Proc.h"
#include "OOP.h"
#include "Functional.h"
#include <ctime>
#include <string>

Skobina::Language* Skobina::Language::Language_Input(ifstream& FileInput)
{
	Language* Langua;
	string TempString;

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return NULL;
	}
	if (TempString.length() > 1) // проверка на длину строки
	{
		FileInput.get();
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	if (!isdigit(int(unsigned char(TempString.front())))) // проверка на ввод цифры
	{
		FileInput.get();
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	int State = stoi(TempString);

	getline(FileInput, TempString, '\n'); // пропуск оставшихся данных

	switch (State)
	{
	case 1:
		Langua = new Procedural;
		break;
	case 2:
		Langua = new Object_Oriented;
		break;
	case 3:
		Langua = new Functional;
		break;
	default:
		FileInput.get();
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return NULL;
	}
	if (!Langua->Input(FileInput))
	{
		return NULL;
	}
	else
	{
		return Langua;
	}
}


bool Skobina::Language::Input(ifstream& FileInput)
{
	string TempString;

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return false;
	}
	if (TempString.length() != 4) // проверка на длину строки
	{
		getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
		return false;
	}
	for (auto iter = TempString.begin(); iter != TempString.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter)))) // проверка на ввод цифры
		{
			getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
			return false;
		}
	}
	YearOfDevelopment = stoul(TempString);

	FileInput >> TempString;
	if (TempString == "\0") // проверка на конец строки
	{
		return false;
	}
	for (auto iter = TempString.begin(); iter != TempString.end(); ++iter)
	{
		if (!isdigit(int(unsigned char(*iter)))) // проверка на ввод цифры
		{
			getline(FileInput, TempString, '\n'); // пропуск оставшихся данных
			return false;
		}
	}
	Reference = stoull(TempString);
	return true;
}


void Skobina::Language::Output(ofstream& FileOutput)
{
	FileOutput << "Year of development = " << YearOfDevelopment
		<< ", The number of references of this language on the Internet = " << Reference << endl;
}


void Skobina::Language::Output_Only_Procedural(ofstream& fout)
{
	fout << endl;
}


int Skobina::Language::Past_Years()
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - YearOfDevelopment;
}


bool Skobina::Language::Compare(Language& Second)
{
	if (this == NULL && &Second != NULL)
	{
		return true;
	}
	if (this != NULL && &Second == NULL)
	{
		return false;
	}
	if (this == NULL && &Second == NULL)
	{
		return false;
	}
	return Past_Years() < Second.Past_Years();
}