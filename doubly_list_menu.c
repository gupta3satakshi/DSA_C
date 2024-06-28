#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}link;
void traverse(link *start)
{
    if(start==NULL)
    printf("\nThe list is empty");
    link* ptr=start;
    int count=0;
    printf("\nThe linked list is: ");
    printf("NULL <=> ");
    while (ptr!=NULL)
    {
        count++;
        
        printf("%d <=> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
    printf("\nThe no. of nodes in linked list are %d",count);
    
}
link* insert_at_begin(link*start,int data)
{
    link* temp=malloc(sizeof(link));
    temp->data=data;
    temp->prev=NULL;
    temp->next=start;
    start = temp;
    return start;

}
link* insert_at_end(link* ptr,int data)
{
    link *temp;
    temp=malloc(sizeof(link));
    temp->data=data;
    temp->prev=ptr;
    temp->next=NULL;
    ptr->next=temp;
    return temp;
   
}
link* insert_at_position(link*start,int data,int pos)
{   
    link *temp,*ptr;
    ptr=start;
    temp=malloc(sizeof(link));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    if(pos==1)
    {
        temp->next=start;
        temp->prev=NULL;
        start=temp;
    }
    else
    {
    pos--;
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    temp->prev=ptr;
    temp->next=ptr->next;
    ptr->next->prev=temp;
    ptr->next=temp;
    }
    return start;
}
link* delete_at_begin(link*start)
{
    if(start==NULL)
    printf("\nLIST IS EMPTY.");
    link*ptr=start;
    if (ptr->next==NULL)
    {
        free(start);
        start=NULL;
        ptr=NULL;
        return start;   
    }
    start=start->next;
    start->prev=NULL;
    free(ptr);
    ptr=NULL;
    return start;

}
link* delete_at_end(link*start)
{ 
    if(start==NULL)
    printf("\nLIST IS EMPTY.");
    link*ptr=start,*temp;
    if (ptr->next==NULL)
    {
        free(start);
        start=NULL;
        ptr=NULL;
        return start;   
    }
    else
    {
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->prev->next=NULL;
    ptr->prev=NULL;
    free(ptr);
    ptr=NULL;
    }
return start;
}
link* delete_at_pos(link*start,int pos)
{
    link*ptr=start,*temp;
    if(pos==1)
    {
        start=delete_at_begin(start);
        return start;
    }
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    if(ptr->next==NULL)
    {
       start  = delete_at_end(start);
    }
    else
    {
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    ptr->prev=NULL;
    ptr->next=NULL;
    }
    free(ptr);
    ptr=NULL;
    return start;
}

int main(){
    int n,data,pos ;
    printf("Enter the no of nodes in linked list:");
    scanf("%d",&n);
    if(n==0)
    {
        printf("\nNo node in list. You need atleast 1 node to start.\n ");
        exit(1);
    }
    printf("\nEnter the data for first node:");
    scanf("%d",&data);
    link *start=NULL;
    start=(link*)malloc(sizeof(link));
    start->data=data;
    start->next=NULL;
    start->prev=NULL;
    
    
    link* ptr =start;
    for(int i=2; i<=n;i++)
    {int num;
    printf("enter data for node %d: ",i);
    scanf("%d",&num);
    ptr= insert_at_end(ptr,num);
    }
    
int opt;
    do{ 
         printf("\n\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4m MENU FOR DOUBLY LINKED LIST OPERATIONS \033[24m**************");
    
        printf("\n1. Traverse the Linked list.");
        printf("\n2. Insert the node in linked list at beginning.");
        printf("\n3. Insert the node in linked list at ending.");
        printf("\n4. Insert the node in linked list at any position.");
        printf("\n5. Delete the node from linked list at beginning.");
        printf("\n6. Delete the node from linked list at ending");
        printf("\n7. Delete the node from linked list at any position.");
        printf("\n8. EXIT");
       
        printf("\nSelect an operation to be performed on linked list: ");
        scanf("%d",&opt);
         printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        traverse(start);
        break;
    case 2:
        printf("\nEnter data to be inserted:");
        scanf("%d",&data);
        start=insert_at_begin(start,data);
        traverse(start);
        break;
    case 3:
        printf("\nEnter data to be inserted:");
        scanf("%d",&data);
        ptr=insert_at_end(ptr,data);
        traverse(start);
        break;
    case 4:
        printf("\nEnter position at which data should be inserted: ");
        scanf("%d",&pos);
        printf("\nEnter data to be inserted: ");
        scanf("%d",&data);
        start=insert_at_position(start,data,pos);
        traverse(start);
        break;
    case 5:
        start=delete_at_begin(start);
        traverse(start);
        break;
    case 6:
        start = delete_at_end(start);
        traverse(start);
        break;
    case 7:
        printf("\nEnter position at which data should be deleted: ");
        scanf("%d",&pos);
        start=delete_at_pos(start,pos);
        traverse(start);
        break;
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=8);
    
    return 0;
}