#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

void swapName(char **name,int i,int j){
	int k;
	char tmp[100];
	for(k=0;k<SIZE;k++)
		tmp[k]=name[i][k];
	for(k=0;k<SIZE;k++)
		name[i][k]=name[j][k];
	for(k=0;k<SIZE;k++)
		name[j][k]=tmp[k];
}
void swap(int *x,int *y){                           
	int tmp = *x;
	*x=*y;
	*y=tmp;
}
void sort(int *age,char **name,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(age[i]>age[j]){
				swapName(name,i,j);
                swap(&age[i],&age[j]);
			}
		}
	}
}
int main(){
	int n,i,j;
     printf("Enter the number of persons : ");
     scanf("%d",&n);
    int age[n];
    char **name;
    name = (char**)malloc(n*sizeof(char *));
	for(i=0;i<n;i++){
		name[i] = (char*)malloc(SIZE*sizeof(char));
	}
    for(int i=0;i<n;i++){
    	printf("Enter name of %dth person :",i+1);
    	scanf("%s[^\n]",name[i]);
    	printf("Enter age of %dth person :",i+1);
    	scanf("%d",&age[i]);
        printf("\n");
    }
    sort(age,name,n);
    printf("\n\tNames in increasing order of age are\n");
    for(i=0;i<n;i++){
      puts(name[i]);
    }
	return 0;
}