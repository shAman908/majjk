#include "LinkedList.h"

Skobina::Linked_List::Linked_List() // конструктор
{
	Head = NULL;
	Tail = NULL;
	SizeLinkedList = 0;
}


Skobina::Linked_List::~Linked_List() // деструктор
{
	Node* TempNode = NULL;

	while (Tail != NULL)
	{
		TempNode = Tail->Previous;
		delete Tail;
		Tail = TempNode;
		--SizeLinkedList;
	}
	Head = TempNode;
}


void Skobina::Linked_List::Linked_List_Input(ifstream& FileInput)
{
	Node* TempNode;

	while (!FileInput.eof())
	{
		TempNode = new Node;

		TempNode->Lang = Language::Language_Input(FileInput); // заполнение блока данных
		TempNode->Next = NULL;
		++SizeLinkedList;

		if (Head == NULL)
		{
			TempNode->Previous = NULL;
			Head = Tail = TempNode;
		}
		else
		{
			TempNode->Previous = Tail;
			Tail->Next = TempNode;
			Tail = TempNode;
		}
	}
}


void Skobina::Linked_List::Linked_List_Output(ofstream& FileOutput)
{
	Node* TempNode = Head; // создание указателя на первый элемент
	FileOutput << "Container contains " << SizeLinkedList << " elements." << endl;

	for (size_t i = 0; i < SizeLinkedList; i++)
	{
		FileOutput << i + 1 << ": ";
		if (TempNode->Lang == NULL)
		{
			FileOutput << "Error reading data! Expected other values in the string." << endl;
		}
		else
		{
			TempNode->Lang->Output(FileOutput);
			FileOutput << "The number of years that have passed since the year the language was created = "
				<< TempNode->Lang->Past_Years() << endl;
		}
		TempNode = TempNode->Next;
	}
}


void Skobina::Linked_List::Linked_List_Output_Only_Procedural(ofstream& FileOutput)
{
	Node* TempNode = Head;
	FileOutput << endl << "Only Procedural languages." << endl;

	for (size_t i = 0; i < SizeLinkedList; i++)
	{
		FileOutput << i + 1 << ": ";
		if (TempNode->Lang == NULL)
		{
			FileOutput << endl;
			continue;
		}
		TempNode->Lang->Output_Only_Procedural(FileOutput);
		TempNode = TempNode->Next;
	}

	FileOutput << endl;
}


void Skobina::Linked_List::Sort_Linked_List() // метод сортировки списка
{
	if (SizeLinkedList < 2) // список с одним элементом не сортируется
	{
		return;
	}

	Node* TempNode = Head;
	bool Flag = false;

	do
	{
		TempNode = Head;
		Flag = false;

		for (size_t i = 0; i < (SizeLinkedList - 1); ++i)
		{
			if (TempNode->Lang->Compare(*TempNode->Next->Lang))
			{
				Swap(TempNode, TempNode->Next);
				Flag = true;
			}
			else
			{
				TempNode = TempNode->Next;
			}
		}
	} while (Flag);
}


void Skobina::Linked_List::Swap(Node* First, Node* Second)
{
	if ((First->Previous == NULL) && (Second->Next == NULL)) // если всего 2 элемента в списке
	{
		Head = Second;
		Tail = First;
		First->Previous = Second;
		Second->Next = First;
		First->Next = NULL;
		Second->Previous = NULL;
		return;
	}
	if ((First->Previous == NULL) && (Second->Next != NULL))
	{
		First->Next = Second->Next;
		First->Previous = Second;
		Second->Next->Previous = First;
		Second->Next = First;
		Second->Previous = NULL;
		Head = Second;
		return;
	}
	if ((First->Previous != NULL) && (Second->Next == NULL))
	{
		Second->Previous = First->Previous;
		First->Previous = Second;
		First->Next = NULL;
		Second->Next = First;
		Second->Previous->Next = Second;
		Tail = First;
		return;
	}
	if ((First->Previous != NULL) && (Second->Next != NULL))
	{
		First->Next = Second->Next;
		Second->Previous = First->Previous;
		Second->Next = First;
		First->Previous = Second;
		Second->Previous->Next = Second;
		First->Next->Previous = First;
		return;
	}
}