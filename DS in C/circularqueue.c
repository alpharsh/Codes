// Implementation of circular queue using array
#include<stdlib.h>
#include<stdio.h>
#define max 5
void insertion();
void deletion();
void display();
int front=-1;
int rear=-1;
int a[max];

void main()
{
	int choice;
	
	printf("\n Press 1 for insertion in circular queue\n");
	printf("\n Press 2 for deletion in circular queue\n");
	printf("\n Press 3 for display in circular queue\n");
	printf("\n Press 4 for exit\n");
	while(1)
	{
		printf("\n Enter Choice");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: insertion();
				break;
			case 2: deletion();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
			default: printf("\n Enter right choice\n");
		}
	}
}


//Function for insertion in circular queue
void insertion()
{
	int item;
	printf("\n Enter the value of item\n");
	scanf("%d", &item);
	if((front==0 && rear==max-1) || (front==rear+1))
		printf("\n Queue is Full\n");
	else
	{
		if(front==-1) // when queue is empty
		{
			rear=front=0;
			a[rear]=item;
			printf("\n after insertion value of front: %d and rear: %d", front, rear);
		}
		else
		{
		    if(rear==max-1 && front!=0) //when rear at max position
		    {
		        rear=0;
		        a[rear]=item;
		        printf("\n after insertion value of front: %d and rear: %d", front, rear);
		    }
		    else
		    {
		        rear++;
		        a[rear]=item;
		        printf("\n after insertion value of front: %d and rear: %d", front, rear);
		    }
		}
	}
	
}

//Function for deletion
void deletion()
{
    int item;
    if(front==-1) // underflow condition
        printf("\n queue is empty\n");
    else
    {
        if(front==rear)
        {
            item=a[front];
            printf("\n deleted item: %d", item);
            front=rear=-1;
            printf("\n after insertion value of front: %d and rear: %d", front, rear);
        }
        else
        {
            if(front==max-1) // when front reached at max position
            {
                item=a[front];
                printf("\n deleted 1 exit statusitem: %d", item);
                front=0;
                printf("\n after insertion value of front: %d and rear: %d", front, rear);
            }
            else
            {
                item=a[front];
                printf("\n deleted item: %d", item);
                front++;
                printf("\n after insertion value of front: %d and rear: %d", front, rear);
            }
        }
    }
}

//Function to Display
void display()
{
	int i;
	if(front==-1) // queue is empty
	printf("\n queue is empty");
	else
	{
	    if(front<rear)
	    {
	        for(i=front; i<=rear; i++)
	        printf("\n %d", a[i]);
	    }
	    else
	    {
	        if(front>rear && front<max)
	        {
	            for(i=front; i<=max-1; i++)
	                printf("\n %d", a[i]);
	                front=0;
	            for(i=front; i<=rear; i++)
	                printf("\n %d", a[i]);
	        }
	        else
	        {
	            if(front==rear)
	            printf("\n %d", a[front]);
	        }
	    }
	}
}
