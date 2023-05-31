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
	vivod(Tail);
	return 0;
}
