#pragma once

#include <string>

template<class T>
class Stack  // ����� ����
{
public:
	Stack()//�����������
	{
		_head = NULL;
		_tail = NULL;
		count = 0;
	}

	~Stack() // ����������
	{
		while (_head)
		{
			_tail = _head->next;
			delete _head;
			_head = _tail;
		}
	}

	void push(T val) // ��������� �������� � ����
	{
		Node* Temp;
		Temp = new Node;
		Temp->element = val;
		if (_tail == 0)
		{
			_tail = Temp;
		}
		else
		{
			Temp->next = _tail;
			_tail = Temp;
		}
		count++;
	}

	T pop() // ����� �������� �� ����� � �������������� ��� ������� ������ (���� �������� ���, �� ������ �����)
	{
		if (_tail == 0)
		{
			throw std::string("Stack is empty!");
		}
		else
		{
			T tmp = _tail->element;
			Node* delptr = _tail;
			_tail = _tail->next;
			delete delptr;
			count--;
			return tmp;
		}
	}

	void print() // ������ ��������� ����� 
	{
		if (_tail == NULL)
		{
			printf("Error: Stack is empty!\n");
		}
		else
		{
			for (Node* ptr = _tail; ptr != 0; ptr = ptr->next)
			{
				std::cout << ptr->element << ' ';
			}
			std::cout << '\n';
		}
	}

	bool empty()
	{
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	struct Node // ��������� ��� �������� ���������
	{
		Node()
		{
			//element = NULL;
			next = NULL;
		}
		Node* next;
		T element;
	};
	Node* _head;
	Node* _tail;
	int count;
};

