#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r,c;
    printf("Enter no. of rows of the array : ");
    scanf("%d",&r);
    printf("Enter no. of coloumns of the array : ");
    scanf("%d",&c);
    int(*ptr)[c]; //Pointer to an array 
	int arr[r][c]; 
	int i, j;  
	ptr = arr; 
	for (i = 0; i < r; i++) { 
		for (j = 0; j < c; j++) { 
            printf("arr[%d][%d] =", i+1,j+1);
			scanf("%d", (*(ptr + i) + j)); 
		} 
	} 
     for(int i=0 ; i<r ;i++)
    {
        for(int j=0 ; j<c ;j++)
        {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
    free(ptr);
    return 0;
}