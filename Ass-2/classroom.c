#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char roll[10];
    char name[20];
    int score[5];
    int total;
};

char roll[10];
char name[20];
int score[5];
int total;
struct student s;

void display(){
    FILE* fp;
    fp=fopen("student","rb");
    printf("\nRoll\tName\tTotal\n");
    while(fread(&s, sizeof(s),1, fp))
    {
        printf("\n%s\t%s\t%d",s.roll,s.name,s.total);
    }
    printf("\n\n");
    fclose(fp);
}
void Add(){
    FILE* fp;
    s.total=0;
    fp=fopen("student","ab+");
    printf("\nEnter the roll:");
    scanf("%s",roll);
    printf("\nEnter the name:");
    scanf("%s",name);
    printf("\nEnter the score in 5 subject:");
    for(int i=0;i<5;i++){
        scanf("%d",&score[i]);
        s.total+=score[i];
    }
    strcpy(s.roll,roll);
    strcpy(s.name,name);
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
}
void search(){
    FILE* fp;
    fp=fopen("student","rb");
    printf("\nEnter the roll to be searched:");
    scanf("%s",roll);
    while(fread(&s, sizeof(s),1, fp))
    {
        if(strcmp(roll,s.roll)==0)
        {
            printf("\nRecord Found");
            printf("\nRoll\tName\tTotal\n");
            printf("%s\t%s\t%d\n",s.roll,s.name,s.total);
            break;
        }
    }
    fclose(fp);
}
void edit(){
    FILE* fp;
    fp=fopen("student","rb+");
    printf("\nEnter the roll to be searched:");
    scanf("%s",roll);
    while(fread(&s, sizeof(s),1, fp))
    {
        if(strcmp(roll,s.roll)==0)
        {
            printf("\nRecord Found");
            printf("\nRoll\tName\tTotal\n");
            printf("%s\t%s\t%d\n",s.roll,s.name,s.total);
            s.total=0;
            printf("\nEnter the roll:");
            scanf("%s",roll);
            printf("\nEnter the name:");
            scanf("%s",name);
            printf("\nEnter the score in 5 subject:");
            for(int i=0;i<5;i++){
                scanf("%d",&score[i]);
                s.total+=score[i];
            }
            strcpy(s.roll,roll);
            strcpy(s.name,name);
            fseek(fp,-1*sizeof(s),SEEK_CUR);
            fwrite(&s,sizeof(s),1,fp);

            break;
        }
    }
    fclose(fp);
}
void delete(){
    FILE* fp; FILE* fptemp;
    fp=fopen("student","rb+");
    fptemp=fopen("student_temp","wb+");
    printf("\nEnter the roll to be deleted:");
    scanf("%s",roll);
    while(fread(&s, sizeof(s),1, fp))
    {
        if(strcmp(roll,s.roll)!=0)
        {
            /*
            printf("\nRecord Found");
            printf("\nRoll\tName\tTotal\n");
            printf("%s\t%s\t%d\n",s.roll,s.name,s.total);
            s.total=-1;
            fseek(fp,-1*sizeof(s),SEEK_CUR);
            */
            fwrite(&s,sizeof(s),1,fptemp);
        }
    }
    fclose(fp);
    fclose(fptemp);
    char n1[]="student"; char n2[]="student_temp"; char n3[]="temp";
    rename(n1,n3);
    rename(n2,n1);
    remove(n3);

}
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Add Record");
        printf("\n2.Display all Record");
        printf("\n3.Search Record");
        printf("\n4.Edit Record");
        printf("\n5.Delete Record");
        printf("\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        fflush(stdin);

        switch(ch)
        {
        case 1:
            Add();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;

        case 4:
            edit();
            break;

        case 5:
            delete();
            break;
        case 6:
            exit(1);
        default:
            printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}
