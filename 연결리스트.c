#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//연결리스트의 노드의 구조체 정의
typedef struct node {
	int data;
	struct node* link;
} pNode;

//연결리스트 수행을 위한 구조체
typedef struct linkedList {
	pNode* head;
	pNode* before;
	pNode* current;
} List;

void Initialization(List* plist)
{
	plist->head = NULL;
	plist->before = NULL;
	plist->current = NULL;
}

void List_Create(List* plist, int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		pNode* newnode = (pNode*)malloc(sizeof(pNode));
		newnode->data = array[i];
		newnode->link = plist->head;
		plist->head = newnode;
	}
}

void List_Insert(List* plist, int data, int location)
{
	pNode* newnode = (pNode*)malloc(sizeof(pNode));
	newnode->data = data;

	plist->current = plist->head;

	for (int i = 0; i < location - 2; i++)
	{
		plist->current = plist->current->link;
	}
	newnode->link = plist->current->link;
	plist->current->link = newnode;
}

int List_Delete(List* plist, int data)
{
	if (plist->head == NULL)
	{
		return 0;
	}

	plist->current = plist->head;

	while (plist->current != NULL)
	{
		if (plist->current->data == data)
		{
			if (plist->current == plist->head)
			{
				plist->head = plist->current->link;
			}
			else
			{
				plist->before->link = plist->current->link;
			}

			free(plist->current);

			return 1;
		}
		else
		{
			plist->before = plist->current;
			plist->current = plist->current->link;
		}
	}

	return 0;
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
	List* plist = (List*)malloc(sizeof(List));

	int data = 0;
	int location = 0;
	int select = 4;

	int arraydata[] = { 10, 20, 30, 40, 50 };
	int n = 5;

	Initialization(plist);

	while (select != 0)
	{
		printf("-----------------------------------\n1)생성 2)삽입 3)삭제 4)출력 0)종료\n-----------------------------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			List_Create(plist, arraydata, n);
			break;
		case 2:
			printf("입력값 : ");
			scanf("%d", &data);
			printf("삽입 위치 : ");
			scanf("%d", &location);
			if (data > 0) List_Insert(plist, data, location);
			else printf("양의 정수만 입력하세요.\n");
			break;
		case 3:
			printf("삭제할 값 : ");
			scanf("%d", &data);
			if (List_Delete(plist, data) == 0)
			{
				printf("삭제하려는 값이 없습니다\n");
			}
			break;
		case 4:
			display(plist);
			break;
		default:
			break;
		}
	}
}