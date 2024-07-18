// Stack using Array:

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is Overflow!!\n");
    }
    else
    {
        stack->array[++stack->top] = item;
        printf("%d is Pushed to Stack!!\n", item);
    }
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Underflow!!\n");
    }
    else
    {
        return stack->array[stack->top--];
    }
}

void show(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Underflow!!\n");
    }
    else
    {
        int i;
        printf("Stack Elements : \n");
        for (i = stack->top; i >= 0; i--)
        {
            printf("%d\n", stack->array[i]);
        }
    }
}

void peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Underflow!!\n");
    }
    else
    {
        printf("Top Element is : %d", stack->array[stack->top]);
    }
}

int main()
{

    int ch, n, len;
    printf("Enter the length of the stack : ");
    scanf("%d", &len);
    struct Stack *stack = createStack(len);
    printf("\n1 : Push\n2 : Pop\n3: Peek\n4 : Show all Elements\n5 : Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    while (ch != 5)
    {
        switch (ch)
        {
            case 1:
                if (isFull(stack))
                {
                    printf("Stack is Overflow!!\n");
                }
                else
                {
                    printf("Enter a number : ");
                    scanf("%d", &n);
                    push(stack, n);
                }
                printf("\n1 : Push\n2 : Pop\n3 : Peek\n4 : Show all Elements\n5 : Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            case 2:
                if (isEmpty(stack))
                {
                    printf("Stack is Underflow!!\n");
                }
                else
                {
                    printf("%d is Popped from Stack!!\n", pop(stack));
                }
                printf("\n1 : Push\n2 : Pop\n3: Peek\n4 : Show all Elements\n5 : Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            case 3:
                peek(stack);
                printf("\n1 : Push\n2 : Pop\n3: Peek\n4 : Show all Elements\n5 : Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            case 4:
                show(stack);
                printf("\n1 : Push\n2 : Pop\n3: Peek\n4 : Show all Elements\n5 : Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;

            default:
                printf("Invalid Choice!!\n");
                printf("\n1 : Push\n2 : Pop\n3: Peek\n4 : Show all Elements\n5 : Exit\n");
                printf("Enter your choice : ");
                scanf("%d", &ch);
                break;
        }
    }
    return 0;
}