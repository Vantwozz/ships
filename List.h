#pragma once
#include <string>
#include <iostream>
using namespace std;
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(string data);
	void clear();
	int GetSize()const;
	string& operator[](const int index);
private:
	class Node//класс эл-та очереди
	{
	public:
		Node* pNext;
		string data;
		Node(string data = string(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node* head;//"голова" для возможности обращения к очереди
};
