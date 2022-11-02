#include <stdio.h>
#include <string.h>
int stack[21];
int top=-1;
int size=21;
char expression[21];
void push(int data)
{
    if(top==size-1)
    {
        printf("Overflow\n");
        return ;
    }
    top++;
    stack[top]=data;
}

char pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return '1';
    }   
    char temp=stack[top];
    top--;
    return temp;
}

void display()
{
    int it=top;
    while(it>=0)
    {
        printf("%d ",stack[it]);
        it--;
    }
}

int precedence_operator(char op)
{
    if(op=='+' || op=='-')
    {
        return 2;
    }
    else if(op=='*' || op=='/')
    {
        return 1;
    }
    else if(op=='^')
    {
        return 3;
    }
    else 
    return -1;
}

int isoperator(char op)
{
    if (op=='+'||op=='-'||op=='*'||op=='/'||op=='%')
    {
        return 1;
    }
    else
        return 0;
}



void convert(char in[],int n)
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(in[i]=='(')
        {
            push(in[i]);
        }

        else if(in[i]==')')
        {
            while(stack[top]!='(' && top!=-1)
            {
                char temp=pop();
                expression[j]=temp;
                j++;
            }
            if(stack[top]=='(')
            {
                pop();
            }
            
        }
        else if((in[i]>='a' && in[i]<='z') || (in[i]>='A' && in[i]<='Z'))
        {
            expression[j]=in[i];
            j++; 
        }

        else if(isoperator(in[i])==1)
        {
            if(top==-1)
            {
                push(in[i]);
            }
            else
            {
                if(precedence_operator(in[i])==precedence_operator(stack[top]) && in[i]=='^')
                {
                    push(in[i]);
                }
                else if(precedence_operator(in[i])>precedence_operator(stack[top]))
                {
                    push(in[i]);
                }
                else
                {
                    while((precedence_operator(in[i])<=precedence_operator(stack[top])) && top!=-1)
                    {
                        char temp=pop();
                        expression[j]=temp;
                        j++;
                    }
                    push(in[i]);
                    
                }
            }
        }
    }
    while(top!=-1)
    {
        char temp=pop();
        expression[j]=temp;
        j++;
    }
}

void is_parenthesis_balanced(char hehe[],int n)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(hehe[i]=='(')
        {
            x++;
            printf("%c ",hehe[i]);
        }
        else if(hehe[i]==')')
        {
            x--;
            printf("%c ",hehe[i]);
        }
    }
    if(x==0)
    {
        printf("Parenthesis is balanced\n");
    }
    else
        printf("Parenthesis not balanced\n");
}

int main()
{
    char infix[]="2 * ( ( 4/2 ) + 5)";
    int n=strlen(infix);
    char postfix_exp[n];
    //convert(infix,n);
    for(int i=0;i<21;i++)
    {
        printf("%c",expression[i]);
    }
    is_parenthesis_balanced(infix,n);
    return 0;
}