#include <stdio.h>
#include <stdlib.h>
typedef struct term{
    int expo;
    float coeff;
}term;

typedef struct poly{
    int n;
    term* terms;
}poly;

poly* create_polynomial()
{
    poly* p1= (poly*) malloc(sizeof(poly));
    printf("How many terms does ur poly have?\n");
    scanf("%d",&p1->n);
    p1->terms=(term*) malloc(p1->n*sizeof(term));

    for(int i=0;i<p1->n;i++)
    {
        printf("Give coefficient and exponent of %dth term respectively: ",i+1);
        scanf("%f",&p1->terms[i].coeff);
        scanf("%d",&p1->terms[i].expo);
        printf("\n");
    }
    return p1;
}

void display_polynomial(poly* p)
{
    printf("P(X)=");
    for(int i=0;i<p->n;i++)
    {
        printf(" %.1fx^%d ",p->terms[i].coeff,p->terms[i].expo);
        if(i>=0 && i<(p->n)-1)
            printf("+");
    }
}


poly* add_poly(poly* p1, poly* p2)
{
    poly* sum=(poly*)malloc(sizeof(poly));
    sum->terms= (term*) malloc((p1->n+p2->n)*sizeof(term));
    int i=0,j=0,k=0;
    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].expo > p2->terms[j].expo)
        {
            sum->terms[k++]=p1->terms[i++];
        }
        else if(p1->terms[i].expo < p2->terms[j].expo)
        {
            sum->terms[k++]=p2->terms[j++];
        }
        else
        {
            sum->terms[k].expo=p1->terms[i].expo;
            sum->terms[k++].coeff= p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    } 
    while(i<p1->n)
    {
        sum->terms[k++]=p1->terms[i++];
    }
    while(j<p2->n)
    {
        sum->terms[k++]=p2->terms[j++];
    }
    sum->n=k;
    return sum;
}

poly* multiply_poly(poly* p1, poly* p2)
{
    poly* prod=(poly*) malloc(sizeof(poly));
    prod->terms=(term*)malloc((p1->n * (p2->n))*sizeof(term));
    int i=0,j=0,k=0;
    for(int i=0;i<p1->n;i++)
    {
        for(int j=0;j<p2->n;j++)
        {
            prod->terms[k].expo= p1->terms[i].expo+p2->terms[j].expo;
            prod->terms[k++].coeff=p1->terms[i].coeff*p2->terms[j].coeff;
        }
    }
    prod->n=k;
    return prod;
}


int main()
{
    poly* p1;
    p1=create_polynomial();
    poly* p2=create_polynomial();
    poly* p3= multiply_poly(p1,p2);
    display_polynomial(p3);
    return 0;
}

