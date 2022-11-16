#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include "Language.h"

namespace Skobina
{
	class Procedural : public Language
	{
	public:
		Procedural() {/**/ } // конструктор по умолчанию

		bool Input(ifstream& FileInput);
		void Output(ofstream& FileOutput);
		void Output_Only_Procedural(ofstream& FileOutput);

	private:
		bool AbstractType;
	};
}

#endif