#include <stdio.h>
typedef struct complex
{
    int real;
    int im;
}complex;

int main()
{
    complex complex1[2];
    for(int i=0;i<2;i++)
    {
        printf("Give the real and imaginary part of your complex number %d\n",i+1);
        scanf("%d %d",&(complex1+i)->real,&(complex1+i)->im);
    }
    for(int i=0;i<2;i++)
    {
        printf("Complex number #%d=> %d+(%di)\n",i+1,(complex1+i)->real,(complex1+i)->im);
    }
    //adding the two numbers
    complex add;
    add.real= (complex1+0)->real+(complex1+1)->real;
    add.im=(complex1+0)->im+(complex1+1)->im;
    printf("The sum of the complex numbers is %d+(%di)\n",add.real,add.im);
    //subtracting the two numbers
    complex sub;
    sub.real= (complex1+0)->real-(complex1+1)->real;
    sub.im=(complex1+0)->im-(complex1+1)->im;
    printf("Subtracting the complex numbers is %d+(%di)\n",sub.real,sub.im);
    return 0;
}