//Write a program in c to display details of student structure by passing to a function.
#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    char name[20];
    int age;
    int section;
    float cgpa;
}student;

int main()
{
    student s1;
    student* ptr;
    ptr=&s1;
    int n;
    printf("How many students do you have?\n");
    scanf("%d",&n);
    ptr=(student *) malloc(n*sizeof(s1));
    for(int i=0;i<n;i++)
    {
        printf("Give the name of student %d\n",i+1);
        scanf("%s",&(ptr+i)->name);
        printf("Give the CGPA of %s\n",(ptr+i)->name);
        scanf("%f",&(ptr+i)->cgpa);
        printf("Give the age and section of %s\n",(ptr+i)->name);
        scanf("%d %d",&(ptr+i)->age,&(ptr+i)->section);
    }
    
    for(int i=0;i<n;i++)
    {
        printf("Number of student= %d+1\n, name=> %s\n Age= %d\n Section=%d\n CGPA=%.2f",i+1,(ptr+i)->name,(ptr+i)->age,(ptr+i)->section,(ptr+i)->cgpa);
        printf("\n");
    }
    int upd;
    printf("Give the student number you want to update\n");
    scanf("%d",&upd);
    printf("Give the name:");
    scanf("%s",&(ptr+upd-1)->name);
    printf("Give the age, section and CGPA respectively\n");
    scanf("%d %d %f",&(ptr+upd-1)->age,&(ptr+upd-1)->section,&(ptr+upd-1)->cgpa);
    for(int i=0;i<n;i++)
    {
        printf("Number of student= %d\n name=> %s\n Age= %d\n Section=%d\n CGPA=%.2f",i+1,(ptr+i)->name,(ptr+i)->age,(ptr+i)->section,(ptr+i)->cgpa);
        printf("\n");
    }
    return 0;
}