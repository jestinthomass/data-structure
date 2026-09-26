#include <stdio.h>
#include <stdlib.h>

#define size 10

int queue[size];
int front = 0, rear = 0;

void main()
{
    void enqueue(int);
    int dequeue();
    void display();
    int item, opt;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("Enter your item: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Deleted value = %d", item);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
        }
    }
    while (1);
}


/* Function to delete an item */
int dequeue()
{
    int item;

    if (front == rear)
    {
        printf("Queue is empty!...");
        return -1;
    }
    else
    {
        front = (front + 1) % size;
        return queue[front];
    }
}


/* Function to display an item */
void display()
{
    int i;

    if (front == rear)
        printf("Queue is empty!...");
    else
    {
        i = (front + 1) % size;

        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % size;
        }
        while (i != (rear + 1) % size);
    }
}


/* Function to insert an item */
void enqueue(int item)
{
    int temp;

    temp = (rear + 1) % size;

    if (temp == front)
        printf("Queue is full!...");
    else
    {
        rear = temp;
        queue[rear] = item;
    }

    return;
}
