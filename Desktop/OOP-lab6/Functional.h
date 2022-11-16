#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H

#include "Language.h"

namespace Skobina
{
	class Functional : public Language
	{
	public:
		Functional() {/**/ } // ����������� �� ���������

		bool Input(ifstream& FileInput);
		void Output(ofstream& FileOutput);

	private:
		bool LazyCalculations;
		enum Typification
		{
			STRICT,
			DYNAMIC
		} Type;
	};
}

#endif