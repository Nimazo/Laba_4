#include <iostream>
#include "Tree.h"

int main()
{
	Tree tr;
	int mas[13] = {20, 10, 5, 6, 7, 15, 13, 16, 12, 25, 22, 30, 31};
	tr.AddMas(mas, 13);

	tr.ShowRec();
	printf("\n");
	tr.ShowStart();

	system("pause");
}