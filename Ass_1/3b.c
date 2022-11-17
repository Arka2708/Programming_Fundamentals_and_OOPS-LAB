#include<stdio.h>
#include<stdlib.h>

void display(int **arr,int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void createArrayByArrayofPtr(int *arr[],int r,int c){
 int i,j;
 for(i=0;i<r;i++){
 	arr[i] = (int*)malloc(c*sizeof(int));
 	for(int j=0;j<c;j++){
      printf("arr[%d][%d] =", i+1,j+1);
      scanf("%d", &arr[i][j]);
 	}
 }
}
int main(){
	int i,j;
    int **arr;
	int r,c;
    printf("Enter no. of rows of the array : ");
    scanf("%d",&r);
    printf("Enter no. of coloumns of the array : ");
    scanf("%d",&c);
    int *a[r];
	createArrayByArrayofPtr(a,r,c);
	display(a,r,c);
	return 0;
}