#include<stdio.h>
#include<conio.h>
#define size 100
void bubble_sort(int array[],int n);
void selection_sort(int array[],int n);
void insertion_sort(int array[],int n);
void quick_sort(int array[],int low,int high);
int partition(int array[], int low, int high);
int main()
{
    int i ,n,opt,arry[size];
    do
    {   
    printf("\nEnter the number of elements to be sorted-");
    scanf("%d",&n);
    printf("\nEnter the elements to perform sorting:\n"); 
    for ( i = 0; i <n; i++)
    {
        printf("Elements are: ary[%d]=",i);
        scanf("%d",&arry[i]);
    }
        printf("\033[4m                                                                               . \033[24m");
        printf("\n**************\033[4m MENU FOR ARRAY SORTING \033[24m**************");
        printf("\n1. BUBBLE SORT.");
        printf("\n2. SELECTION SORT.");
        printf("\n3. INSERTION SORT.");
        printf("\n4. QUICK SORT.");
        printf("\n5. EXIT");
        printf("\nSelect a sorting technique to sort elements : ");
        scanf("%d",&opt);
        printf("\033[4m                                                                               . \033[24m");
    switch (opt)
    {
    case 1:
        bubble_sort(arry,n);
        break;
    case 2:
        selection_sort(arry,n);
        break;
    case 3:
        insertion_sort(arry,n);
        break;
    case 4:
        quick_sort(arry,0,n-1);
        printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
        break;
    default:
        printf("\nPlease select a valid opration to perform");
    }
    }while (opt!=5);
    
   return 0; 
}
void bubble_sort(int arry[],int n)
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
    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
}
void selection_sort(int arry[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            if(arry[i]>arry[j+1])
            {
                int temp=arry[i];
                arry[i]=arry[j+1];
                arry[j+1]=temp;
            }
        }    
    }
    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }

}
void insertion_sort(int arry[],int n)
{
     for(int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            if(arry[i]>arry[j+1])
            {
                int temp=arry[j+1];
                for(int k=(j+1); k>i; k--)
                    arry[k]=arry[k-1];
                arry[i]=temp;
            }
        }    
    }
    printf("\nThe sorted elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arry[i]);
    }
}
void quick_sort(int arry[],int low,int high)
{
    if (low < high){
        int pivot_index = partition(arry, low, high);
        quick_sort(arry, low, pivot_index - 1);
        quick_sort(arry, pivot_index + 1, high);
    }
    
}

int partition(int arry[], int low, int high) {
    int pivot = arry[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arry[j] < pivot) {
            i++;
            int temp = arry[i];
            arry[i] = arry[j];
            arry[j] = temp;
        }
    }
    int a = arry[i + 1];
    arry[i + 1]=arry[high];
    arry[high]=a;
    return i + 1;
}
