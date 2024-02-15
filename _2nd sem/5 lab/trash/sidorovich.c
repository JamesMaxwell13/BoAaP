#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <stdio.h>
#include <stdlib.h>

/*1 ���� � ����� �� ��������
2 ���� � ����� �� ��������
�� �������� ���������� ������� 3-�� ���� �� ����������� */

struct FILO {
	int data;
	struct FILO *next;
};

struct FILO *push(struct FILO *, int);  // ������������� �������� � ������, ������� ������ ������
struct FILO *create_down(struct FILO *head); // �������� ����� �� ��������, ������� ������
void print(struct FILO *); // �������� �����
struct FILO *pop(struct FILO *);
struct FILO *create_up_from_2_down(struct FILO *h1, struct FILO *h2, struct FILO *h3);

int main() {
	int  k;
	struct FILO *head1, *head2, *head3;    
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;

	head1 = create_down(head1);
	head2 = create_down(head2);
		
	printf("\n");
	print(head1);
	printf("\n");
	print(head2);

	head3 = create_up_from_2_down(head1, head2, head3);
	print(head3);
	
	

	free(head1);
}

struct FILO *create_up_from_2_down(struct FILO *h1, struct FILO *h2, struct FILO *h3)
{
	int a;
	while (h1 != NULL && h2 != NULL)
	{
		if (h1->data >= h2->data)
		{
			h3 = push(h3, h1->data);
			h1 = pop(h1);
		}
		else
		{
			h3 = push(h3, h2->data);
			h2 = pop(h2);
		}
	}
	if (h1==NULL && h2!=NULL)
		while (h2 != NULL)
		{
			
				h3 = push(h3, h2->data);
				h2 = pop(h2);
			
		}

	if (h2 == NULL && h1 != NULL)
	while (h1 != NULL)
	{

		h3 = push(h3, h1->data);
		h1 = pop(h1);

	}
	return h3;
}

struct FILO *create_down(struct FILO *head)
{
	int a;
	fflush(stdin);
	while (scanf("%d", &a))
	{
		if (head != NULL)
		{
			if (a > head->data)
				head = push(head, a);
		}
		else head = push(head, a);
	}
	return head;
}

struct FILO *push(struct FILO *head, int x) {
	struct FILO *n;    // ��������� �� ����� ���������
	n = (struct FILO *)malloc(sizeof(struct FILO)); // �������� ������
	n->next = NULL;
	n->data = x;
	if (head == NULL)
		head = n;
	else
	{
		n->next = head;
		head = n;
	}
	return head;
}

// void push(Node_t **head, T value) {
//     Node_t *tmp = malloc(sizeof(Node_t));
// if (tmp == NULL) {
//         exit(STACK_OVERFLOW);
//     }
//     tmp->next = *head;
//     tmp->value = value;
//     *head = tmp;
// }


void print(struct FILO *head){
	struct FILO *p = head;
	while (p != NULL) {   // ���� �� ����� �����    
		printf("%2d ---> ", p->data);
		p = p->next;       // ����������� �� ������
	}
	printf("\n");
}


struct FILO *pop(struct FILO * head)
{
	if (head != NULL)
	{
		head = head->next;
		return head;
	}
	else return NULL;

}