#include <stdio.h>
#include <stdlib.h>
// Singly List Operations

void create();
void display();
void insertatbeg();
void insertatbet();
void insertatlast();
void delatbeg();
void delatbet();
void delatlast();
void reverselist();
void count();

struct node
{
	int info;
	struct node *next;
} *start = NULL;

int main()
{
	int choice;
	printf("\n Press 1 to create list: ");
	printf("\n Press 2 to display list: ");
	printf("\n Press 3 to insert at beginning: ");
	printf("\n Press 4 to insert at between: ");
	printf("\n Press 5 to insert at last: ");
	printf("\n Press 6 to del at beginning: ");
	printf("\n Press 7 to del at between: ");
	printf("\n Press 8 to del at last: ");
	printf("\n Press 9 to reverse list: ");
	printf("\n Press 10 to count list: ");
	printf("\n Press 11 to Exit Program");

	while (1)
	{
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insertatbeg();
			break;
		case 4:
			insertatbet();
			break;
		case 5:
			insertatlast();
			break;
		case 6:
			delatbeg();
			break;
		case 7:
			delatbet();
			break;
		case 8:
			delatlast();
			break;
		case 9:
			reverselist();
			break;
		case 10:
			count();
			break;
		case 11:
			exit(1);
			break;
		}
	}
}

//Function to Create n no. of Nodes
void create()
{
	int val, i, n;
	struct node *p, *tmp;

	printf(" Enter the no of nodes to be added: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		p = (struct node *)malloc(sizeof(struct node));
		printf("\n Enter the value for node: ");
		scanf("%d", &val);
		p->info = val;
		p->next = NULL;

		if (start == NULL)
			start = p;
		else
		{
			tmp = start;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = p;
		}
	}
}

//Function to Display Nodes
void display()
{
	struct node *tmp;
	tmp = start;
	while (tmp != NULL)
	{
		printf(" %d \n", tmp->info);
		tmp = tmp->next;
	}
}

//Function to insert at Beginning
void insertatbeg()
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->info = 69;
	p->next = NULL;

	if (start == NULL)
		start = p;
	else
	{
		p->next = start;
		start = p;
	}
}

//Function to insert at Between two nodes
void insertatbet()
{
	int i, pos;
	struct node *p, *tmp;
	printf("Enter the position to insert: ");
	scanf("%d", &pos);

	p = (struct node *)malloc(sizeof(struct node));
	p->info = 57;
	p->next = NULL;

	if (start == NULL)
		printf("List is Empty");
	else
	{
		tmp = start;
		for (i = 1; i < pos - 1; i++)
			tmp = tmp->next;
		p->next = tmp->next;
		tmp->next = p;
	}
}

//Function to insert at Last
void insertatlast()
{
	struct node *p, *tmp;
	p = (struct node *)malloc(sizeof(struct node));
	p->info = 68;
	p->next = NULL;

	if (start == NULL)
		start = p;
	else
	{
		tmp = start;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}

//Function to Delete at Beginning
void delatbeg()
{
	struct node *tmp;
	if (start == NULL)
		printf("List is Empty");
	else
	{
		tmp = start;
		start = start->next;
		free(tmp);
	}
}

//Function to Delete at Between two nodes
void delatbet()
{
	int i, pos;
	struct node *p, *tmp;
	printf("Enter the position to delete: ");
	scanf("%d", &pos);

	if (start == NULL)
		printf("List is Empty");
	else
	{
		tmp = start;
		for (i = 1; i < pos - 1; i++)
			tmp = tmp->next;
		p = tmp->next;
		tmp->next = p->next;
		free(p);
	}
}

//Function to Delete at Last
void delatlast()
{
	struct node *p, *tmp;
	if (start == NULL)
		printf("List is Empty");
	else
	{
		tmp = start;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		p = tmp->next;
		tmp->next = NULL;
		free(p);
	}
}

//Function to reverse list
void reverselist()
{
	struct node *prev, *tmp, *next;
	tmp = start;
	prev = NULL;

	while (tmp != NULL)
	{
		next = tmp->next;
		tmp->next = prev;
		prev = tmp;
		tmp = next;
	}
	start = prev;
}

//Function to count no of Nodes
void count()
{
	int c = 0;
	struct node *tmp;
	tmp = start;
	while (tmp != NULL)
	{
		c++;
		tmp = tmp->next;
	}
	printf(" No of Nodes are: %d", c);
}