#include <stdio.h>
#include<stdlib.h>
void print_array(int **arr, int r, int c)
{
    for(int i=0 ; i<r ;i++)
    {
        for(int j=0 ; j<c ;j++)
        {
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
}
int** readArray(int r, int c){
	printf("Enter your array\n");
    int **arr= (int **)malloc(r*sizeof(int*));
    for(int i=0 ; i<r ;i++)
    {
        arr[i]=(int*)malloc(c*sizeof(int));
         for(int j=0 ; j<c ;j++)
        {
            printf("arr[%d][%d] =", i+1,j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    return arr;
}
int main()
{
    int r,c;
    printf("Enter no. of rows of the array : ");
    scanf("%d",&r);
    printf("Enter no. of coloumns of the array : ");
    scanf("%d",&c);
    int **a;
    a=readArray(r,c);
    print_array(a,r,c);
    free(a);
    return 0;
}
