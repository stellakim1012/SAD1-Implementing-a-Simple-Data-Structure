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
		list->current = list->head;

		while (list->current->link != list->head)
		{
			list->current = list->current->link;
		}
		newnode->link = list->current->link;
		list->current->link = newnode;
	}
}

void display(List* list)
{
	list->current = list->head;

	while (list->current->link != list->head)
	{
		printf("%d ->", list->current->data);

		list->current = list->current->link;
	}
	printf("%d \n", list->current->data);
}

int Delete_CircularList(List* list, int item)
{
	list->current = list->head;

	while (list->current->data != item)
	{
		if (list->current->link == list->head)
		{
			printf("찾는 값이 없습니다\n");
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
		printf("-------------------------------\n1: 추가 2: 삭제 3: 출력 4: 종료\n-------------------------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("추가될 값 : ");
			scanf("%d", &item);
			Insert_CircularList(&list, item);
			break;

		case 2:
			printf("삭제될 값 : ");
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