#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>

using namespace std;

struct FILO
{
	int data;
	FILO* next;
};
void vvod(FILO** head) 
{
	int x;
	FILO* temp;
	while(cin >> x)
	{
		temp = new FILO;
		temp->next = NULL;
		temp->data = x;
		if (*head == NULL) 
		{
			*head = temp;
		}
		else 
		{
			temp->next = *head;
			*head = temp;
		}
		
	}
}
void del(FILO** head)
{
	FILO* temp = *head;
	int max = temp->data;
	while (temp) 
	{
		if (temp->data > max) 
		{
			max = temp->data;
		}
		temp = temp->next;
	}
	temp = *head;
	while(temp->next->data != max)
	{
		temp = *head;
		*head = temp->next;
	}
}
void vivod(FILO* head) 
{
	FILO* temp;
	temp = head;
	while (temp)
	{
		cout << setw(3) << temp->data;
		temp = temp->next;
	}
}
int main() {

	FILO* head;
	head = NULL;
	vvod(&head);
	del(&head);
	vivod(head);

	return 0;
}
