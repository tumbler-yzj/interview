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

int InitStack(SqStack *S)/* 初始化栈 */
{
     S->top=-1;
    return OK;
}

int Push(SqStack *S,ElemType e)/* 进栈操作 */
{
    if(S->top>=Stack_Size-1)
        return ERROR;
    S->top++;
    S->base[S->top]=e;
    return OK;
}

int Pop(SqStack *S, ElemType &e)/* 出栈操作 */
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

char convert(ElemType e)/* 如果左括号则转换成右返回 */
{
    if(e=='{')
        e='}';
    if(e=='[')
        e=']';
    if(e=='(')
        e=')';
    return e;

}

int Check(SqStack *S,ElemType *p)/* 检查匹配括号函数 */
{
	ElemType c;
     while(*p!='\0')
    {
        if(*p=='{'||*p=='['||*p=='(')/* 如果是左括号则转换成右括号存入栈中 */
            if(Push(S,convert(*p))==0)
                return ERROR;
        if(*p=='}'||*p==']'||*p==')')/* 如果是右括号且与最近存入栈中的括号相同则出栈一个元素，不同则不匹配。不是右括号则继续检查匹配 */
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
    if(S->top==-1)/* 如果S->top==-1则表示所有括号匹配完，即完全匹配。否则，还有未匹配完的 */
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
