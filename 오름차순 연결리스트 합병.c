#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* link;
} Node;

typedef struct linkedList {
	Node* head;
	Node* current;
} List;

void Initialization(List* plist)
{
	plist->head = NULL;
	plist->current = NULL;
}

void List_Create(List* plist, int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = array[i];
		newnode->link = plist->head;
		plist->head = newnode;
	}
}

void List_Merge(List* list_a, List* list_b, List* list_c)
{
	while (list_a->head != NULL && list_b->head != NULL)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));

		if (list_c->head == NULL)
		{
			if (list_a->head->data < list_b->head->data) {
				newnode->data = list_a->head->data;
				list_c->head = newnode;
				list_c->current = list_c->head;
				list_a->head = list_a->head->link;
			}
			else {
				newnode->data = list_b->head->data;
				list_c->head = newnode;
				list_c->current = list_c->head;
				list_b->head = list_b->head->link;
			}
		}
		else {
			if (list_a->head->data < list_b->head->data) {
				newnode->data = list_a->head->data;
				list_c->current->link = newnode;
				list_c->current = newnode;
				list_a->head = list_a->head->link;
			}
			else {
				newnode->data = list_b->head->data;
				list_c->current->link = newnode;
				list_c->current = newnode;
				list_b->head = list_b->head->link;
			}
		}
		list_c->current->link = NULL;
	}
	while (list_a->head != NULL || list_b->head != NULL)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));

		if (list_a->head != NULL)
		{
			newnode->data = list_a->head->data;
			list_c->current->link = newnode;
			list_c->current = newnode;
			list_a->head = list_a->head->link;
		}
		else if (list_b->head != NULL)
		{
			newnode->data = list_b->head->data;
			list_c->current->link = newnode;
			list_c->current = newnode;
			list_b->head = list_b->head->link;
		}
		list_c->current->link = NULL;
	}
}

void display(List* plist)
{
	plist->current = plist->head;

	while (plist->current != NULL)
	{
		if (plist->current->link != NULL)
		{
			printf("%d ->", plist->current->data);
		}
		else
		{
			printf("%d\n", plist->current->data);
		}
		plist->current = plist->current->link;
	}
}

void main()
{
	List* list_a = (List*)malloc(sizeof(List));
	List* list_b = (List*)malloc(sizeof(List));
	List* list_c = (List*)malloc(sizeof(List));

	int array_a[] = { 50, 40, 30, 20, 10 };
	int array_b[] = { 90, 85, 45, 35, 15 };

	int n = 5;

	Initialization(list_a);
	Initialization(list_b);
	Initialization(list_c);

	List_Create(list_a, array_a, n);
	List_Create(list_b, array_b, n);

	display(list_a);
	display(list_b);

	int select = 2;

	while (select != 0)
	{
		printf("----------------------------------\n1)오름차순 연결리스트 합병 0)종료\n----------------------------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			List_Merge(list_a, list_b, list_c);
			display(list_c);
			break;
		default:
			break;
		}
	}
}