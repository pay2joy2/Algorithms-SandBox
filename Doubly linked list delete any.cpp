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
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		List* temp, * tmp;
		temp = new List;
		cin >> x;
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
void Delete(List** Head, List** Tail) 
{
	int x;
	cin >> x;
	List* temp;
	temp = *Head;
	for (int i = 1; i <= x; i++) 
	{
		if (i == x) 
		{

			if (temp->Prev) 
				temp->Prev->Next = temp->Next;
			if (temp->Next) 
				temp->Next->Prev = temp->Prev;
			if (!temp->Prev)
				*Head = temp->Next;
			if (!temp->Next) 
				*Tail = temp->Prev;
		}
		if (temp == NULL)
		{
			break;
		}
		else
		{
			temp = temp->Next;
		}
	}
}
void vivod(List* Tail)
{
	List* temp;
	temp = Tail;
	while (temp)
	{
		cout << setw(3) << temp->Data;
		temp = temp->Prev;
	}
}
int main() {
	List *Head, *Tail;
	Head = NULL;
	Tail = NULL;
	vvod(&Head, &Tail);
	Delete(&Head, &Tail);
	vivod(Tail);
	return 0;
}
