#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define Stack_Size 100
#define ElemType char

#include <iostream>

using namespace std;

typedef struct Stack
{
    ElemType base[Stack_Size];
    int top;
}SqStack;

int InitStack(SqStack *S)/* ��ʼ��ջ */
{
     S->top=-1;
    return OK;
}

int Push(SqStack *S,ElemType e)/* ��ջ���� */
{
    if(S->top>=Stack_Size-1)
        return ERROR;
    S->top++;
    S->base[S->top]=e;
    return OK;
}

int Pop(SqStack *S, ElemType &e)/* ��ջ���� */
{
    if(S->top==-1)
        return ERROR;
    e = S->base[S->top--];
    return OK;
}

int ClearStack(SqStack *S) {
	S->top = -1;
	return OK;
}

char convert(ElemType e)/* �����������ת�����ҷ��� */
{
    if(e=='{')
        e='}';
    if(e=='[')
        e=']';
    if(e=='(')
        e=')';
    return e;

}

int Check(SqStack *S,ElemType *p)/* ���ƥ�����ź��� */
{
	ElemType c;
     while(*p!='\0')
    {
        if(*p=='{'||*p=='['||*p=='(')/* �������������ת���������Ŵ���ջ�� */
            if(Push(S,convert(*p))==0)
                return ERROR;
        if(*p=='}'||*p==']'||*p==')')/* ����������������������ջ�е�������ͬ���ջһ��Ԫ�أ���ͬ��ƥ�䡣������������������ƥ�� */
        {
            if(*p==S->base[S->top])
            {
                if(Pop(S,c)==0)
                    return ERROR;
            }
            else
                return ERROR;

        }
        p++;        
    }
    if(S->top==-1)/* ���S->top==-1���ʾ��������ƥ���꣬����ȫƥ�䡣���򣬻���δƥ����� */
        return OK;
    else
        return ERROR;
}


int main()
{
    SqStack S;
    char p[50];
    InitStack(&S);
    
    scanf("%s",p);
    if(Check(&S,p)==0)
        printf("\nmismatch\n");
    else 
        printf("\nmatched\n");
    
    while(1);
}
