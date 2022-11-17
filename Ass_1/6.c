#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct personTable{
	int age;
	char name[31];
}person;

void swap(person *data, int i){  
    person temp = data[i];                    
	data[i]=data[i+1];
	data[i+1]=temp;
}
void sort(person *data,int n){
	int i,j;
	for(i=0;i+1<n;i++){
			if(data[i].age>data[i+1].age){
                swap(data,i);
			}
	}
}
int main(){
	int n,i,j;
     printf("Enter the number of data for a person you want to store : ");
     scanf("%d",&n);
      person *data;
     data = (person*) malloc(n*sizeof(person));
      for(int i=0;i<n;i++){
    	printf("Enter name of %dth data :",i+1);
    	scanf("%s",data[i].name);
    	printf("Enter age of %dth data :",i+1);
    	scanf("%d",&data[i].age);
    }
    sort(data,n);
      printf("\n\tNames in increasing order of age are\n");
    for(i=0;i<n;i++){
      puts(data[i].name);
    }
	return 0;
}