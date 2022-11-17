#include <stdio.h>
#include<stdlib.h>
void print_array(int *arr, int n)
{
    printf("\tGiven array -->\n");
    for(int i=0 ; i<n ;i++)
    {
       printf("%d ", *(arr+i));
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter size of the array : ");
    scanf("%d",&n);
    int *arr= (int *)malloc(n*sizeof(int*));
    for(int i=0 ; i<n ;i++)
    {
            printf("arr[%d] =", i+1);
            scanf("%d", &arr[i]);
    }
    print_array(arr,n);
    free(arr);
    return 0;
}
