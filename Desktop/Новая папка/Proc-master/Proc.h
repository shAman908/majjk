#pragma once
#ifndef PROC_H
#define PROC_H

#include <fstream>

using namespace std;

namespace Skobina
{
	struct Proc
	{
		enum lang //������������ ��� �������� ������������
		{
			PROC,
			OOP,
			FUNCTIONAL
		} key;
		unsigned short int year_of_development;
		int reference;
		bool abstract_type;
	};

	Proc* Proc_Input(Proc& obj, ifstream& fin);
	void Proc_Output(Proc* obj, ofstream& fout);
}

#endif