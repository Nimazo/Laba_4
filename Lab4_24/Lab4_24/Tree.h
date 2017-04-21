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

	void Add(int value); //добавление одного элемента 
	void AddMas(int *Mas, int count); //добавление массива элементов
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
	void Show(Node *dr); //показать дерево
	void AddHelp(Node *tmpN, Node *node, int value); //метод помощи при добавлении Add() (рекусия)
	
	void print_tree(Node *p, int level); //метод вывода для Show() (рекурсия)

};

void Tree::Add(int value) //добавить элемент
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

void Tree::AddMas(int * Mas, int count) // добавить массив элементов
{
	for (int i = 0; i < count; i++)
	{
		Add(Mas[i]);
	}
}

void Tree::AddHelp(Node *tmpN, Node *node, int value) // метод нужный для добавления элементов (рекурсия)
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

void Tree::Show(Node *currentNode) //нерекурсивный обход дерева с помощью стека
{
	Node *tmp = new Node; // создаем переменную с которой будем работать
	Stack<Node> stack; //создаем стек узлов

	stack.push(*currentNode); //кладем в стек корень дерева
	bool fl = true; //флаг для первого элемента прохода

	while ((tmp) || (!stack.empty()))
	{
		if (fl == true) //если флаг установлен, то берем из стека элемент
		{
			*tmp = stack.pop();
			fl = false; //закрываем флаг чтобы не входить еще раз
		}

		printf("%i\n", tmp->x); //печатаем элемент

		if (tmp->right) //если существует элемент справа, то кладем его в стек
		{
			stack.push(*tmp->right);
		}

		if (tmp->left) //если существует элемент слева, то переходим к нему
		{
			tmp = tmp->left;
		}
		else if (!stack.empty()) //иначе, если нет элемента слева, но есть элемент в стеке
		{
			*tmp = stack.pop(); //то берем его из стека
		}
		else //если элементов больше нет, то обнуляем tmp чтобы выйти из цикла
		{
			tmp = NULL;
		}
	}
}

void Tree::print_tree(Node *p, int level) //рекурсивный обход дерева
{
	if (p)
	{
		print_tree(p->right, level + 1);     // вывод левого поддерева
		for (int i = 0; i < level; i++)
		{
			printf("   ");
		}
		printf("%i\n", p->x);               // вывод корня поддерева
		print_tree(p->left, level + 1);    // вывод левого поддерева
	}
}