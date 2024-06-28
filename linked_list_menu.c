#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}link;
void traverse(link *start)
{
    int count=0;
    if(start==NULL)
    printf("\n\nThe list is empty.");
    link* ptr=start;
    
     printf("\n\n\nThe linked list is: ");
    while (ptr!=NULL)
    {
        count++;
        
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
    printf("\n\nThe no. of nodes in linked list are %d",count);
    
}
link* insert_at_begin(link*start,int data)
{
    link* temp=malloc(sizeof(link));
    temp->data=data;
    temp->next=start;
    start = temp;
    return start;

}
link* insert_at_end(link* ptr,int data)
{
    link *temp;
    temp=malloc(sizeof(link));
    temp->data=data;
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
    temp->next=NULL;
    if(pos==1)
    {
        temp->next=start;
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
    temp->next=ptr->next;
    ptr->next=temp;
    }
    return start;
}
link* delete_at_begin(link*start)
{
    if(start==NULL)
    printf("\n\nLIST IS EMPTY.\n.");
    link*ptr=start;
    if (start->next==NULL)
    {
        free(start);
        start=NULL;
        return start;
    }
    start=start->next;
    free(ptr);
    ptr = NULL;
    return start;

}
link* delete_at_end(link*start)
{ 
    if(start==NULL)
    printf("\n\nLIST IS EMPTY\n.");
    link*ptr=start,*temp;
    if (start->next==NULL)
    {
        free(start);
        start=NULL;
        return start;
    }
    else
    {
    while(ptr->next->next!=NULL)
    ptr=ptr->next;
    free(ptr->next);
    ptr->next=NULL;
    }
return start;
}
link* delete_at_pos(link*start,int pos)
{
    link*ptr=start,*temp;
    if(pos==1)
    start=delete_at_begin(start);
    else
    {
    pos--;
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    }
    free(temp);
    temp = NULL;
    return start;
}
void search(link*start,int item)
{
    link*ptr=start;
    int count=0;
    while(ptr!=NULL)
    {
    count++;  
    if(ptr->data==item)
    {
        printf("\n\nThe data %d is found at postion:%d ",item,count);
        return;
    }
    else
        ptr=ptr->next;
    
    }
    printf("\nData is not in list");
    
}
int main(){
    int n,data,pos ;
    printf("enter the no of nodes in linked list:\n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("\n\nNo node in list. You need atleast 1 node to start. ");
        exit(1);
    }
    printf("enter the data for first node:\n");
    scanf("%d",&data);
    link *start=NULL;
    start=(link*)malloc(sizeof(link));
    start->data=data;
    start->next=NULL;
    
    
    link* ptr =start;
    for(int i=2; i<=n;i++)
    {int num;
    printf("enter data for node %d\n",i);
    scanf("%d",&num);
    ptr= insert_at_end(ptr,num);
    }
    
int opt;
    do{ 
         printf("\n\n\033[4m                                                                               . \033[24m");
        printf("\n\n**************\033[4m MENU FOR LINKED LIST OPERATIONS \033[24m**************");
    
        printf("\n\n1. Traverse the Linked list.");
        printf("\n2. Insert the node in linked list at begining.");
        printf("\n3. Insert the node in linked list at ending.");
        printf("\n4. Insert the node in linked list at any position.");
        printf("\n5. Delete the node from linked list at begining");
        printf("\n6. Delete the node from linked list at ending");
        printf("\n7. Delete the node from linked list at any position.");
        printf("\n8. Search a node in linked list.");
        printf("\n9. EXIT");
       
        printf("\n\nSelect an operation to be performed on linked list: ");
        scanf("%d",&opt);
         printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        traverse(start);
        break;
    case 2:
        printf("\n\nEnter data to be inserted:\n");
        scanf("%d",&data);
        start=insert_at_begin(start,data);
        traverse(start);
        break;
    case 3:
        printf("\n\nEnter data to be inserted:\n");
        scanf("%d",&data);
        ptr=insert_at_end(ptr,data);
        traverse(start);
        break;

    case 4:
        printf("\n\nEnter position at which data should be inserted:\n");
        scanf("%d",&pos);
        printf("\n\nEnter data to be inserted:\n");
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
        printf("\n\nEnter position at which data should be deleted:\n");
        scanf("%d",&pos);
        start=delete_at_pos(start,pos);
        traverse(start);
        break;
    case 8:
        printf("\n\nEnter data to be searched:");
        scanf("%d",&data);
        search(start,data);
        traverse(start);
        break;
   
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=9);
    
    return 0;
}