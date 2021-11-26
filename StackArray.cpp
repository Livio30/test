#include<stdio.h>
#include<conio.h>
#define SIZE 6

int isFull();
int isEmpty();
void PUSH(int);
void POP();
void PEEK();
void DISPLAY();
int stack[SIZE];
int TOS = -1;

int main()
{
	int choice = 0, element = 0;
	while (1)
	{
		printf("\nMenu");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n3. PEEK");
		printf("\n4. DISPLAY");
		printf("\n5. Exit\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: printf("\nEnter  the element to Push");
			scanf_s("%d", &element);
			PUSH(element);
			break;
		case 2: POP();
			printf("\nElement Popped");

			break;
		case 3: PEEK();
			break;
		case 4: DISPLAY();
			break;
		case 5: return 0;
		default: printf("\nEnter correct choice");
		}
		
	}
	_getch();
}

int isFull()
{
	if (TOS == (SIZE - 1))
		return 1;
	return 0;
}
int isEmpty()
{
	if (TOS == -1 )
		return 1;
	return 0;
}

void PUSH(int  element) {
	if (isFull())
		printf("\nStack Overflow");
	else
	{
		stack[++TOS] = element;
	}
}
void POP()
{
	if (isEmpty())
		printf("\nStack Underflow");
	else
		--TOS;
}
void PEEK()
{
	if (isEmpty())
		printf("\nStack Underflow");
	else
		printf("Top element : %d", stack[TOS]);
}
void DISPLAY()
{
	int i = TOS;
	if (isEmpty())
		printf("\nStack Underflow");
	else
	{
		//r (i = TOS; i >= 0; i--)
		while (i >= 0)
		{
			printf("%d\t", stack[i--]);
		}
	}
}