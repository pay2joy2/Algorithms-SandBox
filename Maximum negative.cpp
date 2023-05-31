#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>

using namespace std;

struct List
{
	int Data;
	List* Next;
	List* Prev;
};
void vvod(List** Head, List** Tail) 
{
	int x, n;
	while(cin >> x)
	{
		List* temp, * tmp;
		temp = new List;
		tmp = *Head;
		temp->Data = x;
		temp->Next = NULL;
		temp->Prev = NULL;
		if (*Head == NULL) 
		{
			*Head = temp;
			*Tail = temp;
		}
		else
		{
			temp->Next = *Head;
			tmp->Prev = temp;
			*Head = temp;
		}
	}
}
void min(List* Head) 
{
	List* tmp1;
	tmp1 = Head;
	int min;
	while (tmp1) 
	{
		if (tmp1->Data < 0)
		{
			min = tmp1->Data;
			break;
		}
		tmp1 = tmp1->Next;
	}
	tmp1 = Head;
	while (tmp1) 
	{
		if (tmp1->Data < 0) {
			if (tmp1->Data > min)
			{
				min = tmp1->Data;
			}
		}
		tmp1 = tmp1->Next;
	}
	cout << min;
}
int main() {
	List *Head, *Tail;
	Head = NULL;
	Tail = NULL;
	vvod(&Head, &Tail);
	min(Head);
	return 0;
}
