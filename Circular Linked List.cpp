#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>

using namespace std;

struct ring
{
	char data;
	ring* next;
	ring* prev;
};
void vvod(ring** head, int *remember)
{
	char x;
	cin >> x;
	while(!isdigit(x))
	{
		ring* temp, * tmp1;
		temp = new ring;
		temp->data = x;
		temp->next = NULL;
		temp->prev = NULL;
		tmp1 = *head;
		if (*head == NULL) 
		{
			temp->next = temp;
			temp->prev = temp;
			*head = temp;
		}
		else
		{
			temp->next = tmp1->next;
			tmp1->next->prev = temp;
			tmp1->next = temp;
			temp->prev = tmp1;
			*head = temp;
		}
		cin >> x;
	}
	*remember = x - '0';
}
void func(ring** head, int remember) 
{
	ring* temp;
	temp = *head;
	int count = 0;
	while (temp->next != *head) 
	{
		count++;
		if (count % remember == 0)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
		temp = temp->next;
		if (temp->next == *head)
		{
			count++;
			if (count % remember == 0)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
		}
		
	}
}
void vivod(ring* head) 
{
	ring* temp, * tmp1;
	tmp1 = head;
	temp = head;
	do
	{	
		cout << temp->data;
		temp = temp->next;
	} while (temp != tmp1);
}
int main() {
	int remember;
	ring* head;
	head = NULL;
	vvod(&head, &remember);
	head = head->next;
	func(&head, remember);
	vivod(head);
	return 0;
}
