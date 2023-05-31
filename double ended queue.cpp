#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct FIFO
{
	int data;
	FIFO* next;
	FIFO* prev;
};
void vvod(FIFO** head, FIFO** tail)
{
	FIFO* temp;
	char x[255];
	cin.getline(x, 255);
	char* token;
	token = strtok(x, " ");
	while (token)
	{
		temp = new FIFO;
		temp->next = NULL;
		temp->data = atoi(token);
		if (*head == NULL)
		{
			*head = temp;
			*tail = temp;
		}
		else
		{
			(*tail)->next = temp;
			*tail = temp;
		}
		token = strtok(NULL, " ");
	}
}
int sum(FIFO** head, FIFO** head2) 
{
	int sum = 0;
	FIFO* tmp1, * tmp2;
	tmp1 = *head;
	while (tmp1) 
	{
		tmp2 = *head2;
		bool check = false;
		while (tmp2) 
		{
			if (tmp1->data == tmp2->data)
			{
				check = true;
			}
			tmp2 = tmp2->next;
		}
		if (check == false)
		{
			sum += tmp1->data;	
		}
		tmp1 = tmp1->next;
	}
	return sum;
}
int main() {

	FIFO* head, * tail, * head2, * tail2;
	head = NULL;
	tail = NULL;
	head2 = NULL;
	tail2 = NULL;
	vvod(&head, &tail);
	vvod(&head2, &tail2);
	int summa = sum(&head, &head2);
	cout << summa;

	return 0;
}
