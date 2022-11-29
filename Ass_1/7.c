#include <stdio.h>
#include <stdlib.h>

struct student{
    int roll;
    int score;
    char name[31];
    struct student * next; //self-referencing structure
};

void display(struct student *head)
{
    int i=1;
    while(head!=NULL)
    {
     printf("Student %d : Name = %s -> Roll = %d ->Score= %d \n", i,head->name, head->roll,head->score);
     head = head->next;
     i++;
    }
    printf("\n");
}
struct student * Add(struct student *head)
{  
    struct student *s = (struct student *)malloc(sizeof(struct student));
    printf("\nEnter Name: ");scanf("%s", s->name);
    printf("Enter Roll No.: ");scanf("%d", &s->roll);
    printf("Enter score: ");scanf("%d", &s->score);
    if(head==NULL)
    {
        s->next = head;
        return s;
    }
    else{
        struct student *p = head;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = s;
        s->next = NULL;
        return head;
    }
}
struct student *delete(struct student *head, int Roll)
{
    if(head ==NULL) return head;
    struct student *p = head;
    struct student *q = head->next;
    if(p->roll==Roll)
    {
        free(p);
        head=head->next;
        return head;
    }
    while(q !=NULL)
    {
        if(q->roll==Roll) break;
        p = p->next;
        q = q->next;
    }
    if(q->roll!=Roll) printf("Wrong Input!!! Enter Correct Roll Number. Try Again :)\n");
    else
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct student *head=NULL;
    int choice;
    while(1)
    {
    printf("\t\t **********MENU**********\n");
    printf("\tAdd a Record = 1\n");
    printf("\tDelete a Record = 2\n");
    printf("\tDisplay the Record = 3\n");
    printf("\tQuit = 4\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    
        switch(choice)
        {
            case 1: head=Add(head);
                    break;
            case 2: {
                    int Roll;
                    printf("Enter the Roll of the student which needs to be deleted : ");
                    scanf("%d", &Roll);
                    head=delete(head,Roll);
                    break;
            }
            case 3: if(head==NULL) printf("No Record!!! It's Empty\n");
                    else display(head);
                    break;
            case 4:  exit(1);
        }
    }
    return 0;    
}
