#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}stack;
stack *top = NULL;
stack *traverse(stack *top)
{
    stack *ptr;
    ptr =top;
    if(top==NULL)
    {
        printf("\nSTACK IS EMPTY.");
    }
    else
    {
        printf("\nThe elements of stack is: ");
        while(ptr != NULL)
        {
            printf("\n%d", ptr ->data);
            ptr = ptr ->next;
        }
    }
    return top;
}
stack *push(stack *top, int val)
{
    stack *ptr;
    ptr = (stack*)malloc(sizeof(stack));
    ptr -> data = val;
    if(top==NULL)
    {
        ptr -> next = NULL;
        top = ptr;
    }
    else
    {
        ptr -> next = top;
        top=ptr;
    }
    return top;
}
stack *pop(stack *top)
{
    stack *ptr;
    ptr =top;
    if(top==NULL)
    {
        printf("\nStack underflow");
    }
    else
    {
        top = top -> next;
        printf("\n The value being popped is : %d", ptr -> data);
        free(ptr);
    }
    return top;
}
int peek(stack *top)
{
    if(top == NULL)
    {
        return -1;
    }
    else 
    return top -> data;
}
void is_empty(stack *top)
{
    if (top == NULL)
    {
        printf("\n Stack is empty.");
    }
    else
    printf("\n Stack is not empty");
}
int main()
{
    int opt, val;
    do
    {
        printf("\n\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4mMENU FOR LINKED STACK OPERATIONS\033[24m**************");
        printf("\n1. Traverse the stack.");
        printf("\n2. PUSH.");
        printf("\n3. POP.");
        printf("\n4. PEEK.");
        printf("\n5. IS EMPTY.");
        printf("\n6. EXIT");
        printf("\nSelect an operation to be performed on array: ");
        scanf("%d",&opt);
        printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        top = traverse(top);
        break;
    case 2:
        printf("\n Enter the value to be pushed on stack : ");
        scanf("%d",&val);
        top = push(top,val);
        break;
    case 3:
        top = pop(top);
        break;
    case 4:
        val = peek(top);
        if(val != -1)
        printf("\n The value stored at top of stack is : %d", val);
        else
        printf("\n Stack is empty.");
        break;
    case 5:
        is_empty(top);
        break;
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=6);
    
   return 0; 
}
