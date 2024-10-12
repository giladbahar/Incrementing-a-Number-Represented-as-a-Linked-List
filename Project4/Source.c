#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
	int value;
	struct node* next;
}node;

void printList(node* head)
{
	while (head != NULL)
	{
		printf("[%d]-> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

node* createNode(int value, node* next)
{
	node* item = (node*)malloc(sizeof(node*));
	item->value = value;
	item->next = next;
	return item;
}

node* createListFromArray(int* arr, int n)
{
	int i;
	node* head = NULL;
	for (i = n - 1; i >= 0; i--)
		head = createNode(arr[i], head);
	return head;
}

int convert(node* head)
{
	int result = 0;

	while (head != NULL)
	{
		result = (result * 10) + head->value;
		head = head->next;
	}

	return result;
}

int numLength(int n)
{
	int result = 0;

	if (n == 0)
		return 1;

	while (n > 0)
	{
		result++;
		n /= 10;
	}

	return result;
}

void sumList(node* head, int value)
{
	int i;
	int sum = value + convert(head);
	int len = numLength(sum);
	int power = pow(10, len - 1);

	node* ptr = head;
	for (i = 0; i < len; i++)
	{
		int curr = (sum / power) % 10;
		power /= 10;

		ptr->value = curr;
		if (i < len - 1 && ptr->next == NULL)
			ptr->next = (node*)calloc(1, sizeof(node));
		ptr = ptr->next;
	}

}

int main()
{
	int arr[4] = { 9, 9, 9, 4 };
	node* head = createListFromArray(arr, 4);

	printList(head);

	sumList(head, 18); //[1]->[0]->[0]->[1]->[2]->NULL

	printList(head);

	return 0;
}