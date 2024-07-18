// Creating Stack using LinkedList:

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTravarsel(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow!!");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow!!");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow!!");
    }
    else
    {
        printf("Top element : %d", top->data);
    }
}

int main()
{
    int ch, n;
    struct Node *top = NULL;
    printf("\n1: Push\n2: Pop\n3: Peek\n4: Show all Elements\n5: Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    while (ch != 5)
    {
        switch (ch)
        {
            case 1:
                if (isFull(top))
                {
                    printf("Stack is Overflow!!\n");
                }
                else
                {
                    printf("Enter a number : ");
                    scanf("%d", &n);
                    top = push(top, n);
                }
                printf("\n1: Push\n2: Pop\n3: Peek\n4: Show all Elements\n5: Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            case 2:
                if (isEmpty(top))
                {
                    printf("Stack is Underflow!!\n");
                }
                else
                {
                    int element = pop(&top);
                    printf("Popped Element : %d \n", element);
                }
                printf("\n1: Push\n2: Pop\n3: Peek\n4: Show all Elements\n5: Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            case 3:
                peek(top);
                printf("\n1: Push\n2: Pop\n3: Peek\n4: Show all Elements\n5: Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            case 4:
                if (isEmpty(top))
                {
                    printf("Stack is Underflow!!\n");
                }
                else
                {
                    linkedListTravarsel(top);
                }
                printf("\n1: Push\n2: Pop\n3: Peek\n4: Show all Elements\n5: Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            default:
                printf("Invalid Choice!!!\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;
        }
    }

    return 0;
}