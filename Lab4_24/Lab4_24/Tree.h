#pragma once
#include <iostream>
#include <cmath>
#include "Stack.h"

class Tree
{
public:
	Tree()
	{
		_root = NULL;
	};

	void Add(int value); //���������� ������ �������� 
	void AddMas(int *Mas, int count); //���������� ������� ���������
	void ShowStart()
	{
		Show(_root);
	}

	void ShowRec()
	{
		print_tree(_root, 0);
	};


private:
	class Node
	{
	public:
		Node()
		{
			x = NULL;
			left = NULL;
			right = NULL;
		}
		int x;
		Node *left, *right;
	};
	Node *_root;
	void Show(Node *dr); //�������� ������
	void AddHelp(Node *tmpN, Node *node, int value); //����� ������ ��� ���������� Add() (�������)
	
	void print_tree(Node *p, int level); //����� ������ ��� Show() (��������)

};

void Tree::Add(int value) //�������� �������
{
	if (_root == NULL)
	{
		Node *node = new Node;
		node->x = value;
		node->left = NULL;
		node->right = NULL;
		_root = node;
	}
	else
	{
		Node *tmpN = new Node;
		tmpN->x = value;
		Node *node = _root;
		AddHelp(tmpN, node, value);
	}
}

void Tree::AddMas(int * Mas, int count) // �������� ������ ���������
{
	for (int i = 0; i < count; i++)
	{
		Add(Mas[i]);
	}
}

void Tree::AddHelp(Node *tmpN, Node *node, int value) // ����� ������ ��� ���������� ��������� (��������)
{
	if (value > node->x)
	{
		if (node->right == NULL)
		{
			node->right = tmpN;
		}
		else
		{
			AddHelp(tmpN, node->right, value);
		}
	}
	else if (value <= node->x)
	{
		if (node->left == NULL)
		{
			node->left = tmpN;
		}
		else
		{
			AddHelp(tmpN, node->left, value);
		}
	}
}

void Tree::Show(Node *currentNode) //������������� ����� ������ � ������� �����
{
	Node *tmp = new Node; // ������� ���������� � ������� ����� ��������
	Stack<Node> stack; //������� ���� �����

	stack.push(*currentNode); //������ � ���� ������ ������
	bool fl = true; //���� ��� ������� �������� �������

	while ((tmp) || (!stack.empty()))
	{
		if (fl == true) //���� ���� ����������, �� ����� �� ����� �������
		{
			*tmp = stack.pop();
			fl = false; //��������� ���� ����� �� ������� ��� ���
		}

		printf("%i\n", tmp->x); //�������� �������

		if (tmp->right) //���� ���������� ������� ������, �� ������ ��� � ����
		{
			stack.push(*tmp->right);
		}

		if (tmp->left) //���� ���������� ������� �����, �� ��������� � ����
		{
			tmp = tmp->left;
		}
		else if (!stack.empty()) //�����, ���� ��� �������� �����, �� ���� ������� � �����
		{
			*tmp = stack.pop(); //�� ����� ��� �� �����
		}
		else //���� ��������� ������ ���, �� �������� tmp ����� ����� �� �����
		{
			tmp = NULL;
		}
	}
}

void Tree::print_tree(Node *p, int level) //����������� ����� ������
{
	if (p)
	{
		print_tree(p->right, level + 1);     // ����� ������ ���������
		for (int i = 0; i < level; i++)
		{
			printf("   ");
		}
		printf("%i\n", p->x);               // ����� ����� ���������
		print_tree(p->left, level + 1);    // ����� ������ ���������
	}
}