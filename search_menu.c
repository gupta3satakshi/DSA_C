#include<stdio.h>
#include<conio.h>
#define size 100
void linearsrch(int array[],int n);
void binarysrch(int array[],int n);
int main()
{
    int i ,n,opt,arry[size];
    printf("\nEnter the size of array-");
    scanf("%d",&n);
    printf("\nEnter the elements of an array:\n "); 
    for ( i = 0; i <n; i++)
    {
        printf("Elements are: ary[%d]=",i);
        scanf("%d",&arry[i]);
    }
    do
    {
        printf("\n\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4m MENU FOR ARRAY SEARCH OPERATIONS \033[24m**************");
        printf("\n1. LINEAR SEARCH.");
        printf("\n2. BINARY SEARCH.");
        printf("\n3. EXIT");
        printf("\nSelect an operation to be performed on array: ");
        scanf("%d",&opt);
        printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
        case 1:
        linearsrch(arry,n);
        break;
    case 2:
        binarysrch(arry,n);
        break;
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=3);
    
   return 0; 
}
void linearsrch(int arry[100],int n)
{
    int num,i,flag=0;
    printf("\n\nenter the element to be  searched-");
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
    printf("\n\nthe elements  are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
    
}
void binarysrch(int arry[100],int n)
{ 
  int num,strt,mid,end,flag=0;
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
    printf("\n\nthe sorted elements  are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
  printf("\n\nenter the no. that has to be searched: ");
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