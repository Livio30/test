#include <stdio.h>
#include <stdlib.h>

int getElement();//Done
int getPosition();//Done


void insertStart(int);//Done
void insertEnd(int);//Done
void insertRandom(int, int);//Done
void deleteStart();//Done
void deleteEnd();//Done
void deleteRandom(int);//Done
void display();//Done

struct node
{
	int data;
	struct node *next;
};

struct node *HEAD = NULL;

int main()
{
	int choice;
	while (1)
	{
		printf("\n Menu");
		printf("\n 1. Insert Node at Start");
		printf("\n 2. Insert Node at End");
		printf("\n 3. Insert Node at Specific Position");
		printf("\n 4. Delete Node from Start");
		printf("\n 5. Delete Node from End");
		printf("\n 6. Delete Node at Specific Position");
		printf("\n 7. Display");
		printf("\n 8. Exit \n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insertStart(getElement());
			break;

		case 2:
			insertEnd(getElement());
			break;
		case 3:
			insertRandom(getElement(), getPosition());
			break;

		case 4:
			deleteStart();
			break;

		case 5:
			deleteEnd();
			break;

		case 6:
			deleteRandom(getPosition());
			break;

		case 7:
			display();
			break;

		case 8:
			return 0;

		default:
			printf("Enter correct choice");
		}
	}
	return 0;
}

int getElement()
{
	int element;
	printf("Enter the Element :");
	scanf("%d", &element);
	return element;
}

int getPosition()
{
	int pos;
	printf("Enter the Position : ");
	scanf("%d", &pos);
	return pos;
}

void insertStart(int element)
{
	struct node *newNode;
	newNode = (struct node *)(malloc(sizeof(struct node)));

	newNode->data = element;
	newNode->next = HEAD;

	HEAD = newNode;

	printf("Node inserted");
}

void insertEnd(int element)
{
	struct node *newNode, *ptr;
	newNode = (struct node *)(malloc(sizeof(struct node)));

	newNode->data = element;

	if (HEAD == NULL)
	{
		newNode->next = HEAD;
		HEAD = newNode;
	}
	else
	{
		ptr = HEAD;
		while (ptr->next != NULL)
			ptr = ptr->next;
		newNode->next = NULL;
		ptr->next = newNode;
	}
	printf("Node inserted");
}

void insertRandom(int element, int pos)
{
	int i = 1;
	struct node *newNode, *ptr;
	newNode = (struct node *)(malloc(sizeof(struct node)));

	newNode->data = element;

	if (HEAD == NULL)
	{
		newNode->next = HEAD;
		HEAD = newNode;
	}
	else
	{
		ptr = HEAD;
		newNode->next = NULL;
		while (i < (pos - 1))
		{
			ptr = ptr->next;
			i++;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	printf("Node inserted");
}
int isEmpty()
{
	if (HEAD == NULL)
		return 1;
	return 0;
}

void deleteStart()
{
	struct node *ptr;
	if (isEmpty())
		printf("\n List is Empty");
	else
	{
		ptr = HEAD;
		HEAD = HEAD->next;
		free(ptr);
	}
	printf("\n Node deleted.");
}

void deleteEnd()
{
	struct node *ptr, *prevNodePtr;
	if (isEmpty())
	{
		printf("List is Empty");
		return;
	}
	else if (HEAD->next == NULL)
	{
		HEAD = NULL;
		free(HEAD);
	}
	else
	{
		ptr = HEAD;
		while (ptr->next != NULL)
		{
			prevNodePtr = ptr;
			ptr = ptr->next;
		}
		prevNodePtr->next = NULL;
		free(ptr);
	}
	printf("Node Deleted");
}

void deleteRandom(int pos)
{
	struct node *ptr, *prevNodePtr;
	int i;
	ptr = HEAD;
	for (i = 0; i < pos - 1; i++)
	{
		prevNodePtr = ptr;
		ptr = ptr->next;

		if (ptr == NULL)
		{
			printf("Can't Delete");
			return;
		}
	}

	prevNodePtr->next = ptr->next;
	free(ptr);
	printf("Node Deleted");
}

void display()
{
	struct node *ptr;
	ptr = HEAD;
	if (isEmpty())
	{
		printf("List Empty");
	}
	else
	{
		printf("List : ");
		while (ptr != NULL)
		{
			printf("%d -> ", ptr->data);
			ptr = ptr->next;
		}
		printf("NULL");
	}
}