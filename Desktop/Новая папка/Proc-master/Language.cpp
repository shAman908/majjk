#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include <ctime>

Skobina::Language* Skobina::Language_Input(ifstream& fin) //Language* Language_Input(ifstream& fin)
{
	Language* language = new Language;
	Proc* proc;
	Object_oriented* oop;
	Functional* func;
	unsigned short int temp;
	fin >> temp;
	fin >> language->year_of_development;
	fin >> language->reference;
	switch (temp)
	{
	case 1:
		proc = new Proc;
		language->key = Language::lang::PROC;
		proc = (Proc*)language; //��� ������ ���������� � proc ��� � lang
		language = (Language*)Proc_Input(*proc, fin); //����� ������� ��� ������������ ������ 
		return language;
	case 2:
		oop = new Object_oriented;
		language->key = Language::lang::OOP;
		oop = (Object_oriented*)language;
		language = (Language*)Object_oriented_Input(*oop, fin);
		return language;
	case 3:
		func = new Functional;
		language->key = Language::lang::FUNCTIONAL;
		func = (Functional*)language;
		language = (Language*)Functional_Input(*func, fin);
		return language;
	default:
		return 0;
	}
}

void Skobina::Language_Output(Language* obj, ofstream& fout)
{
	switch (obj->key)
	{
	case Language::lang::PROC:
		Proc_Output((Proc*)obj, fout);
		break;
	case Language::lang::OOP:
		Object_oriented_Output((Object_oriented*)obj, fout);
		break;
	case Language::lang::FUNCTIONAL:
		Functional_Output((Functional*)obj, fout);
		break;
	default:
		fout << "Incorrect programming language" << endl;
		return;
	}
	fout << "Year of development = " << obj->year_of_development
		<< ", The number of references of this language on the Internet = " << obj->reference << endl;
}

int Skobina::Past_Years(Language* obj)
{
	time_t now = time(NULL);
	tm* localtm = localtime(&now);
	return 1900 + localtm->tm_year - obj->year_of_development;
}

bool Skobina::Compare(Language* first, Language* second)
{
	return Past_Years(first) < Past_Years(second);
}