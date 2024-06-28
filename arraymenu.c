#include<stdio.h>
#include<conio.h>
#define size 100
void traverse(int arry[],int n);
void insert_at_begin(int arry[],int *n);
void insert_at_end(int arry[],int *n);
void insert_at_pos(int arry[],int *n);
void delete_at_begin(int array[],int *n);
void delete_at_end(int array[],int *n);
void delete_at_pos(int array[],int *n);
void linearsrch(int array[],int n);
void binarysrch(int array[],int n);
void bubblesort(int array[],int n);
int main(){
    int i ,n,opt,arry[size];
    printf("\nEnter the size of array-");
    scanf("%d",&n);
        printf("\nEnter the elements of an array:\n "); 
        for ( i = 0; i <n; i++)
    {
        printf("Elements are: ary[%d]=",i);
        scanf("%d",&arry[i]);
    }
    do{
        printf("\n\n\033[4m                                                                               . \033[24m");
        printf("\n\n**************\033[4mMENU FOR ARRAY OPERATIONS\033[24m**************");
    
        printf("\n\n1. Traverse the array.");
        printf("\n2. Insert the element in array at beginning.");
        printf("\n3. Insert the element in array at ending.");
        printf("\n4. Insert the element in array at given position.");
        printf("\n5. Delete the element from array at beginning.");
        printf("\n6. Delete the element from array at ending.");
        printf("\n7. Delete the element from array at given position.");
        printf("\n8. Search an element in array by linear search");
        printf("\n9. Search an element in array by binary search");
        printf("\n10. Sort the element in array by bubble sort");
        printf("\n11. EXIT");
        printf("\n\nSelect an operation to be performed on array: ");
        scanf("%d",&opt);
        printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        traverse(arry,n);
        break;
    case 2:
        insert_at_begin(arry,&n);
        break;
    case 3:
        insert_at_end(arry,&n);
        break;
    case 4:
        insert_at_pos(arry,&n);
        break;
    case 5:
        delete_at_begin(arry,&n);
        break;
    case 6:
        delete_at_end(arry,&n);
        break;
    case 7:
        delete_at_pos(arry,&n);
        break;
    case 8:
        linearsrch(arry,n);
        break;
    case 9:
        binarysrch(arry,n);
        break;
    case 10:
        bubblesort(arry,n);
        break;
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=11);
    
   return 0; 
}
void traverse(int arry[100],int n)
{
    printf("\n\n\nthe elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
}
void insert_at_begin(int arry[100],int *n)
{
    int num;
    printf("\nenter the value to be inserted-");
    scanf("%d",&num);
    for (int i = *n-1; i >= 0; i--)
        {
            arry[i+1]=arry[i];
        }
        *n=*n+1;
        arry[0]=num;
    printf("\nthe elements after insertion are: ");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t",arry[i]);
    }
    printf("\n\nInsertd element at beginning is = %d",num);
    
}
void insert_at_end(int arry[100],int *n)
{
    int num;
    printf("\nenter the value to insert-");
    scanf("%d",&num);
    arry[*n]=num;
    *n=*n+1;
    printf("\nthe elements after insertion are: ");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t",arry[i]);
    }
    printf("\n\nInsertd element at ending is = %d",num);
}
void insert_at_pos(int arry[100],int *n)
{
    int pos,num;
    printf("\nenter the position at which element should be inserted-");
    scanf("%d",&pos);
    printf("\nenter the value to insert-");
    scanf("%d",&num);
    if (pos>*n)
    {
        printf("\nposition is out of length"); 
    }
    else
    {
        for (int i = *n-1; i >= pos; i--)
        {
            arry[i+1]=arry[i];
        }
        *n=*n+1;
        arry[pos]=num;
    }
    printf("\nthe elements after insertion are: ");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t",arry[i]);
    }
    printf("\n\nInsertd element at given position is = %d",num);
}
void delete_at_begin(int arry[100],int *n)
{
    if (n==0)
    {
        printf("\narray is empty,can not perform deletion."); 
    }
    int num=arry[0];
    for (int i = 0; i <*n-1; i++)
        {
            arry[i]=arry[i+1];
        }
        *n=*n-1;
    printf("\nthe elements after deletion are: ");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t",arry[i]);
    }
    printf("\n\nDeleted element at beginning is = %d",num);
}
void delete_at_end(int arry[100],int *n)
{
    if (n==0)
    {
        printf("\narray is empty,can not perform deletion."); 
    }
    int num=arry[*n-1];
    *n=*n-1;
    printf("\nthe elements after deletion are: ");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t",arry[i]);
    }
    printf("\n\nDeleted element at ending is = %d",num);   
}
void delete_at_pos(int arry[100],int *n)
{
    int pos;
    printf("\nenter the position at which element should be deleted-");
    scanf("%d",&pos);
    
    if (pos>*n)
    {
        printf("\nposition is out of length"); 
    }
    else
    {
        int num=arry[pos-1];
        for (int i = pos-1; i <*n-1; i++)
        {
            arry[i]=arry[i+1];
        }
        *n=*n-1;
        printf("\n\nDeleted element at given position is = %d",num);
    }
    printf("\nthe elements after deletion are: ");
    for (int i = 0; i < *n; i++)
    {
        printf("%d\t",arry[i]);
    }
    
}
void linearsrch(int arry[100],int n)
{
    int num,i,flag=0;
    printf("\nenter the element to be  searched-");
    scanf("%d",&num);
        for (i =0; i <n; i++)
        {
           if (arry[i]==num)
           {
           flag=1;
           printf("\nelement found at position %d",i+1);
           break;
           }
        }    
        if (flag==0)
          
          printf("\nelement is not present in array");
    printf("\nthe elements  are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
    
}
void binarysrch(int arry[100],int n)
{ 
  int num,strt,mid,end,flag=0;
bubblesort(arry,n);
  printf("\nenter the no. that has to be searched: ");
  scanf("%d",&num);
  strt=0, end=n-1;
  while(strt<=end)
  {
    mid=(strt+end)/2;
    if (arry[mid]==num)
    {
        printf("\n %d is present in the array at position %d",num,mid+1);
        flag=1;
        break;
    }
    else if(arry[mid]>num)
            end=mid-1;
    else
            strt=mid+1;
    if (strt>end && flag==0)
        printf("\n %d does not exist in the array",num);
    
  }
}
void bubblesort(int arry[100],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arry[j]>arry[j+1])
            {
                int temp=arry[j];
                arry[j]=arry[j+1];
                arry[j+1]=temp;
            }
        }    
    }
    printf("\nThe sorted array in ascending order is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
}