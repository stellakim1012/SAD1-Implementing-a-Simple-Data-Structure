#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* link;
}Node;

typedef struct list
{
	Node* head;
	Node* before;
	Node* current;
}List;

void Init_CircularList(List* list)
{
	list->head = NULL;
	list->before = NULL;
	list->current = NULL;
}

void Insert_CircularList(List* list, int item)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->data = item;

	if (list->head == NULL)
	{
		list->head = newnode;
		newnode->link = newnode;
	}
	else
	{
		newnode->link = list->head->link;
		list->head->link = newnode;
		list->head = newnode;
	}
}

void display(List* list)
{
	list->current = list->head->link;

	while (list->current != list->head)
	{
		printf("%d ->", list->current->data);

		list->current = list->current->link;
	}
	printf("%d \n", list->current->data);
}

int Delete_CircularList(List* list, int item)
{
	list->current = list->head->link;
	list->before = list->head;
	while (list->current->data != item)
	{
		if (list->current == list->head)
		{
			printf("ã�� ���� �����ϴ�\n");
			return 0;
		}
		list->before = list->current;
		list->current = list->current->link;
	}

	if (list->current == list->head)
	{
		list->before->link = list->current->link;
		list->head = list->before;
	}
	else
	{
		list->before->link = list->current->link;
	}

	free(list->current);
	return 1;
}

void main()
{
	List list;
	int select = 1;
	int item = 0;

	Init_CircularList(&list);

	while (select != 4)
	{
		printf("-------------------------------\n1: �߰� 2: ���� 3: ��� 4: ����\n-------------------------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("�߰��� �� : ");
			scanf("%d", &item);
			Insert_CircularList(&list, item);
			break;

		case 2:
			printf("������ �� : ");
			scanf("%d", &item);
			Delete_CircularList(&list, item);
			break;

		case 3:
			display(&list);
			break;

		case 4:
			break;
		default:
			break;
		}
	}
}