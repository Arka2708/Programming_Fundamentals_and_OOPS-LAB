#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[30];
    int score;
}s[10];

void display_sorted_roll(struct student s[], int n, int choice)
{
    printf("\nSorting by Roll -----> \n");
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if( s[i].roll > s[j].roll )
            {
                struct student temp; 
                temp = s[i];
                s[i] = s[j]; 
                s[j] = temp;
            }
        } 
    }
    if(choice ==1){
        for(int i = 0; i<n; i++)
        {
            printf("%s : %d - score : %d\n", s[i].name,s[i].roll, s[i].score);
        }
    }
    else{
    for(int i = n-1; i>=0; i--)
    {
        printf("%s : %d - score : %d\n", s[i].name,s[i].roll, s[i].score);
    }
    }
}
void display_sorted_score(struct student s[], int n, int choice)
{
    printf("\nSorting by Score -----> \n");
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if( s[i].score > s[j].score )
            { 
                struct student temp; 
                temp = s[i];
                s[i] = s[j]; 
                s[j] = temp; 
            }
        }
    }
    if(choice ==3){
        for(int i = 0; i<n; i++)
        {
            printf("%s : %d - score : %d\n", s[i].name,s[i].roll, s[i].score);
        }
    }
    else{
    for(int i = n-1; i>=0; i--)
    {
        printf("%s : %d - score : %d\n", s[i].name,s[i].roll, s[i].score);
    }
    }
}

int main()
{
    int n,choice;
    printf("Enter the no. of students(max 10): ");
    scanf("%d", &n);
    for(int i=1 ; i<=n; i++)
    {
      printf("\n\t\t********Information of Student %d********", i);
      printf("\nEnter Name: ");scanf("%s", s[i-1].name);
      printf("Enter Roll No.: ");scanf("%d", &s[i-1].roll);
      printf("Enter score: ");scanf("%d", &s[i-1].score);
    }
    printf("\t\t **********MENU**********\n");
    printf("\tsort by roll in increasing order = 1\n");
    printf("\tsort by roll in decreasing order = 2\n");
    printf("\tsort by score in increasing order = 3\n");
    printf("\tsort by score in decreasing order = 4\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: display_sorted_roll(s,n,choice);
                break;
        case 2: display_sorted_roll(s,n,choice);
                 break;
        case 3: display_sorted_score(s,n,choice);
                 break;
        case 4:  display_sorted_score(s,n,choice);
                 break;
    }

        FILE *f;
        f = fopen("student_data.txt", "w");
        for(int i = 0; i<n; i++){
        fprintf(f, "Student roll no. : %d\n", s[i].roll);
        fprintf(f, "Student name : %s\n", s[i].name);
        fprintf(f, "Student score : %d\n", s[i].score);
        fprintf(f, "\n");
         }
        fclose(f);
        return 0;
}