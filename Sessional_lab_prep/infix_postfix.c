#include <stdio.h>
#include <string.h>
#define N 15
char stack1[N];
char postfix[N];
int top1=-1;
void push1(char data)
{
    if(top1==N-1)
    {
        printf("Overflow1\n");
        return ;
    }
    top1++;
    stack1[top1]=data;
}

char pop1()
{
    int temp;
    if(top1==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    temp=stack1[top1];
    top1--;
    return temp;
}

void display1()
{
    int it=top1;
    while(it>=0)
    {
        printf("%c ",stack1[it]);
        it--;
    }
}
int precedence(char ch)
{
    if(ch=='/' || ch=='*')
        return 2;
    else if(ch=='^')
        return 3;
    else if(ch=='+' || ch=='-')
        return 1;
    else 
        return -1;
}

void inf_post(char inf_expression[])
{
    int k=0;
    int h=0;
    for(int i=0;i<strlen(inf_expression);i++)
    {
        if(inf_expression[i]=='(')
        {
            push1(inf_expression[i]);
        }
        else if(inf_expression[i]==')')
        {
            while((stack1[top1]!='(') && (top1!=-1))
            {
                char temp=pop1();
                postfix[k++]=temp;
            }
            pop1();
        }
        else if(inf_expression[i]=='^')
        {
            push1(inf_expression[i]);
        }
        else if(inf_expression[i]=='+'||inf_expression[i]=='-'||inf_expression[i]=='*'||inf_expression[i]=='/')
        {
            if(top1==-1)
            {
                push1(inf_expression[i]);
            }
            else
            {
                if(precedence(inf_expression[i])>precedence(stack1[top1]))
                {
                    push1(inf_expression[i]);
                }
                else 
                {
                    while(precedence(inf_expression[i])<=precedence(stack1[top1]) && top1!=-1)
                    {
                        char temp=pop1();
                        postfix[k++]=temp;
                    }
                    push1(inf_expression[i]);
                }
            }
        }
        else{
            postfix[k++]=inf_expression[i];
        }
    }
    while(top1!=-1)
    {
        char temp=pop1();
        postfix[k++]=temp;
    }
}

int main()
{
    char inf_expression[]="(A+B)+C-(D-E)^F";
    inf_post(inf_expression);
    for(int i=0;i<strlen(postfix);i++)
    {
        printf("%c ", postfix[i]);
    }
    printf("\n");
    return 0;
}