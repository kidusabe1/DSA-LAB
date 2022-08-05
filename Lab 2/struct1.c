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
    printf("Give the name of student\n");
    scanf("%s",s1.name);
    printf("Give the CGPA of %s\n",s1.name);
    scanf("%f",&s1.cgpa);
    printf("Give the age and section of %s\n",s1.name);
    scanf("%d %d",&s1.age,&s1.section);
    
    printf("The details of your student are:\n");
    printf("Name: %s\n",s1.name);
    printf("Age: %d\n",s1.age);
    printf("Section: %d\n",s1.section);
    printf("CGPA: %.2f\n",s1.cgpa);
    return 0;
}