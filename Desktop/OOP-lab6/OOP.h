#ifndef OOP_H
#define OOP_H

#include "Language.h"

namespace Skobina
{
	class Object_Oriented : public Language
	{
	public:
		Object_Oriented() {/**/ } // конструктор по умолчанию

		bool Input(ifstream& FileInput);
		void Output(ofstream& FileOutput);

	private:
		enum Inheritance
		{
			SINGLE,
			MULTIPLE,
			INTERFACE
		} Number;
	};
}

#endif