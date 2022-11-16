#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	class Linked_List
	{
		struct Node
		{
			Language* Lang; // структура узла в связном списке
			Node* Next;
			Node* Previous;
		};
	public:
		Linked_List(); // конструктор
		~Linked_List(); // деструктор

		void Linked_List_Input(ifstream& FileInput);
		void Linked_List_Output(ofstream& FileOutput);
		void Linked_List_Output_Only_Procedural(ofstream& FileOutput);

		void Sort_Linked_List(); // метод сортировки списка
	private:
		Node* Head;
		Node* Tail;
		size_t SizeLinkedList;

		void Swap(Node* First, Node* Second); // вспомогательный метод сортировки списка
	};
}

#endif