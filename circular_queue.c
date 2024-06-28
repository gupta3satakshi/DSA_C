#include<stdio.h>
#include<conio.h>
#define size 51
int queue[size];
int front = -1, rear = -1;
void create_queue()
{
    front = -1;
    rear = -1;
}
void is_empty()
{
    if(front == -1 && rear == -1)
        printf("\nQueue is empty.");
    else 
        printf("\nQueue is not empty.");
}
void is_full()
{
    if(front == 0 && rear == size-1)
        printf("\nQueue is full.");
    else 
        printf("\nQueue is not full.");
}
void enqueue(int val)
{
    if(front == 0 && rear == size-1)
    {
        printf("\nQUEUE IS FULL. can not insert.");
    }
    else if(front ==-1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear]=val;  
    }
    else if(rear == (size-1) && front != 0)
    {
        rear=0;
        queue[rear]=val;
    }
    else
    {
        rear=rear+1;
        queue[rear]=val;
    }
    printf("\nInserted %d into the queue.", val);
}
int dequeue()
{
    int val;
    if(front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY! Can not delete.");
        return -1;
    }
    val = queue[front];
    if(front == rear)
    {    
        front =rear = -1;
    }
    else
    { 
        if(front == (size - 1))
            front=0;
        else
            front=front+1;
    }
    return val;
}
int peek()
{
    if(front == -1 && rear == -1)
        {
            printf("\nQUEUE IS EMPTY!");
            return -1;
        } 
    else   
    return queue[front];

}
void display()
{
    int i;
    printf("\n");
    if(front == -1 && rear == -1)
    printf("\n QUEUE IS EMPTY!");
    else
    {   
        printf("\nQueue elements = ");
        if(front<rear)
        {
            for (i = front ; i<=rear ; i++)
            {
                printf("%d\t",queue[i]);
            }
        }
        else
        {
            for(i=front ; i < size; i++)
            {
                printf("\t %d",queue[i]);
            }
            for ( i = 0; i <= rear; i++)
            {
                printf("\t%d",queue[i]);
            }
            
        }
    }
}
int main()
{
    int opt,val;
    do
    {     
        printf("\n\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4m MENU FOR CIRCULAR QUEUE OPERATIONS \033[24m**************");
    
        printf("\n1. Create queue.");
        printf("\n2. Is empty.");
        printf("\n3. Is full.");
        printf("\n4. Enqueue.");
        printf("\n5. Dequeue.");
        printf("\n6. Peek.");
        printf("\n7. Display.");
        printf("\n8. EXIT.");
       
        printf("\nSelect an operation to be performed on Queue: ");
        scanf("%d",&opt);
        printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        create_queue();
        printf("\nQueue is created.");
        break;
    case 2:
        is_empty();
        break;
    case 3:
        is_full();
        break;
    case 4:
        printf("\nEnter element to insert: ");
        scanf("%d", &val);
        enqueue(val);
        break;
    case 5:
        val = dequeue();
        if(val != -1)
            printf("\nDeleted %d from the queue.", val);
        break;
    case 6:
        val= peek();
        if(val != -1)
            printf("\nThe value at front is : %d",val);
        break;
    case 7:
        display();
        break;
    default:
        printf("\nPlease select a valid opration to perform.");
    }
    }while (opt!=8);
    return 0;
}

