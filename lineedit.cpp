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

int main()
{
    SqStack S;
    char p[50];
    InitStack(&S);
    char ch = getchar();
    char c;
    while(ch != EOF) {
		while(ch != EOF && ch != '\n') {
			switch(ch) {
				case '#':
					Pop(&S, c);
					break;
				case '@':
					ClearStack(&S);
					break;
				default:
					Push(&S, ch);
			}
			ch = getchar();
		}
		char temp;
		while(Pop(&S, temp) == OK) {
				cout << temp;	
		}
		ClearStack(&S);
		if(ch != EOF)
			ch = getchar();
    }
    while(1);
}
