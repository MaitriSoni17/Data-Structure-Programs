#include <stdio.h>
#include <stdlib.h>

int *items, front = -1, rear = -1, len;
void insert(int value)
{
    if (rear == len - 1)
    {
        printf("Simple Queue is Full!!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        items[rear] = value;
        printf("Inserted: %d\n", value);
    }
}

void delete()
{
    if (front == -1)
    {
        printf("Simple Queue is Empty!!\n");
    }
    else
    {
        printf("Deleted : %d\n", items[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (rear == -1)
    {
        printf("Simple Queue is Empty!!\n");
    }
    else
    {
        int i;
        printf("Elements of Queue : \n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", items[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (rear == -1)
    {
        printf("Simple Queue is Empty!!\n");
    }
    else
    {
        printf("Top Element of Simple Queue : %d\n", items[front]);
    }
}

int main()
{
    if (front == -1 && rear == -1)
    {
        printf("Enter the size of the Simple Queue : ");
        scanf("%d", &len);
        items = (int *)malloc(len * sizeof(int));
        if (items == NULL)
        {
            printf("Memory Allocation Failed!!\n");
            return -1;
        }
    }
    int ch;
    int value;
    printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    while (ch != 5)
    {
        switch (ch)
        {
        case 1:
            if (rear == len - 1)
            {
                printf("Simple Queue is Full!!\n");
            }
            else
            {
                printf("Enter the element you want to insert : ");
                scanf("%d", &value);
                insert(value);
            }
            printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            break;

        case 2:
            if (rear == -1)
            {
                printf("Simple Queue is Empty!!\n");
            }
            else
            {
                delete ();
            }
            printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            break;

        case 3:
            if (rear == -1)
            {
                printf("Simple Queue is Empty!!\n");
            }
            else
            {
                peek();
            }
            printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            break;

        case 4:
            if (rear == -1)
            {
                printf("Simple Queue is Empty!!\n");
            }
            else
            {
                display();
            }
            printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            break;

        case 5:
            printf("Exited!!!\n");
            printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            break;

        default:
            printf("Invalid Choice!!\n");
            printf("1: Insert\n2: Delete\n3: Peek\n4: Display\n5: Exit\n");
            printf("Enter your choice : ");
            scanf("%d", &ch);
            break;
        }
    }

    free(items);
    return 0;
}