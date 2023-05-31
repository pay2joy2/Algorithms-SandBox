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
		tmp = *Tail;
		temp->Data = x;
		temp->Next = NULL;
		temp->Prev = NULL;
		if (*Tail == NULL)
		{
			*Head = temp;
			*Tail = temp;
		}
		else
		{
			tmp->Next = temp;
			temp->Prev = tmp;
			*Tail = temp;
		}
	}
}
void smthnew(List** Head)
{
	int x;
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
	}
	else
	{
		temp->Next = *Head;
		tmp->Prev = temp;
		*Head = temp;
	}

}
void vivod(List* Head)
{
	List* temp;
	temp = Head;
	while (temp)
	{
		cout << setw(3) << temp->Data;
		temp = temp->Next;
	}
}
int main() {
	List *Head, *Tail;
	Head = NULL;
	Tail = NULL;
	vvod(&Head, &Tail);
	smthnew(&Head);
	vivod(Head);
	return 0;
}
