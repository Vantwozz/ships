#include "List.h"
List::List()//конструктор
{
	Size = 0;
	head = nullptr;
}

List::~List()//деконструктор
{
	clear();
}

void List::pop_front()//удаление первог элемента, изменение Head
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

void List::push_back(string data)//добавление в конец очереди
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);
	}
	Size++;
}

void List::clear()//очищение
{
	while (Size)
	{
		pop_front();
	}
}

string& List::operator[](const int index)//оператор квадратных скобок для удобства вывода
{
	int counter = 0;
	Node* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int List::GetSize()const {
	return Size;
}
