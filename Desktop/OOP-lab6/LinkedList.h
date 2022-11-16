#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Language.h"

namespace Skobina
{
	class Linked_List
	{
		struct Node
		{
			Language* Lang; // ��������� ���� � ������� ������
			Node* Next;
			Node* Previous;
		};
	public:
		Linked_List(); // �����������
		~Linked_List(); // ����������

		void Linked_List_Input(ifstream& FileInput);
		void Linked_List_Output(ofstream& FileOutput);
		void Linked_List_Output_Only_Procedural(ofstream& FileOutput);

		void Sort_Linked_List(); // ����� ���������� ������
	private:
		Node* Head;
		Node* Tail;
		size_t SizeLinkedList;

		void Swap(Node* First, Node* Second); // ��������������� ����� ���������� ������
	};
}

#endif