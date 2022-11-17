#include <stdio.h>
#include<stdlib.h>
void readArray(int **arr,int n){
	int i;
	*arr = (int *) malloc(n*sizeof(int));
	printf("Enter your array\n");
	for(i=0;i<n;i++){
		scanf("%d",*arr+i);
    }
}
void printArray(int *arr,int n){
	int i;
	printf("Here is your array\n");
    for(i=0;i<n;i++){printf("%d ",arr[i]);}
    	printf("\n");
}
int main(){
	int n,i;int *arr;
	printf("Enter your number\n");
	scanf("%d",&n);
	readArray(&arr,n);
	printArray(arr,n);
	free(arr);
	return 0;
}