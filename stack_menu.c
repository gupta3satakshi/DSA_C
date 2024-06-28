#include <stdio.h>
#include<conio.h>
#define size 10
int stack [size] , top = -1;
void traverse(int stack[])
{
    if(top==-1)
    {
        printf("\nSTACK IS EMPTY.");
    }
    else
    {
        printf("\nThe elements of stack is:\n");
        for(int i=top ; i>=0 ; i--)
        {
            printf("%d",stack[i]);
            printf("\n");
        }
    }
}
void push(int stack[], int val)
{
    if(top==size-1)
    {
        printf("\nStack overflow");
    }
    else
    {
        top++;
        stack[top]=val;
    }
}
int pop(int stack[])
{
    if(top==-1)
    {
        printf("\nStack underflow");
        return -1;
    }
    else
    {
        int val = stack[top];
        top--;
        return val;
    }
}
int peek(int stack[])
{
    if(top == -1)
    {
        printf("\n Stack is empty");
        return -1;
    }
    else 
    return (stack[top]);
}
int is_empty(int stack[])
{
    if (top == -1)
    {
        printf("\n Stack is empty.");
        return -1;
    }
    else
    printf("\nstack is not empty.");
}
void is_full(int stack[])
{
    if (top == size-1)
    {
        printf("\n Stack is full.");
    }
    else
    printf("\nstack is not full.");
}
int main()
{
    int opt, val;
    do
    {
        printf("\n\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4m MENU FOR STACK OPERATIONS \033[24m**************");
        printf("\n1. Traverse the stack.");
        printf("\n2. PUSH.");
        printf("\n3. POP.");
        printf("\n4. PEEK.");
        printf("\n5. IS EMPTY.");
        printf("\n6. IS FULL.");
        printf("\n7. EXIT");
        printf("\nSelect an operation to be performed on Stack: ");
        scanf("%d",&opt);
        printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        traverse(stack);
        break;
    case 2:
        printf("\nEnter the value to be pushed on stack : ");
        scanf("%d",&val);
        push(stack,val);
        break;
    case 3:
        val = pop(stack);
        if(val != -1)
        printf("\nThe value popped from stack is : %d", val);
        break;
    case 4:
        val = peek(stack);
        if(val != -1)
        printf("\nThe value stored at top of stack is : %d", val);
        break;
    case 5:
        is_empty(stack);
        break;
    case 6:
        is_full(stack);
        break;
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=7);
    
   return 0; 
}
