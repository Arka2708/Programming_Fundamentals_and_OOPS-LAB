#include<stdio.h>
#include<stdlib.h>

int main(){
	int x ,*p,**pp;
	printf("Enter your number : "); scanf("%d",&x);
	p = &x; pp = &p;
	printf("\nPrinting the number using pointer %d\n",*p);
	printf("Printing the number using pointer to pointer %d\n\n",**pp);
	return 0;
}