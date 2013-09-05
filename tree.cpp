#include <stdio.h>
#include <stdlib.h>
#include <stack> 


#define OK 1
#define ERROR -1
#define OVERFLOW -2
#define DataType int

using namespace std; 

typedef struct BiTNode {
	DataType val;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

void visit(BiTNode *node) {
	printf("%d", node->val);
}

void preOrder(BiTNode *root) {
	if(root != NULL) {
		visit(root);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

void inOrder(BiTNode *root) {
	if(root != NULL) {
		inOrder(root->lchild);
		visit(root);
		inOrder(root->rchild);
	}
}

void postOrder(BiTNode *root) {
	if(root != NULL) {
		postOrder(root->lchild);
		postOrder(root->rchild);
		visit(root);
	}
}

/*�ǵݹ�*/
void preOrder1(BiTNode *root) {
	stack<BiTNode*> s;
	while(root != NULL || !s.empty()) {
		while(root != NULL) {
			visit(root);
			s.push(root);
			root = root->lchild;
		}
		if(!s.empty()) {
			root = s.top();
			s.pop();
			root = root->rchild;
		}
	}
}

void inOrder1(BiTNode *root) {
	stack<BiTNode*> s;
	while(root != NULL || !s.empty()) {
		while(root != NULL) {
			s.push(root);
			root = root->lchild;
		}
		if(!s.empty()) {
			root = s.top();
			visit(root);
			s.pop();
			root = root->rchild;
		}
	}
}

void postOrder1(BiTNode *root) {
	stack<BiTNode*> s;
	BiTNode *cur;
	BiTNode *pre = NULL;
	s.push(root);
	while(!s.empty()) {
		cur = s.top();
		if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild) )) {
			visit(cur);
			s.pop();
			pre = cur;
		}
		else {
			if(cur->rchild != NULL)
				s.push(cur->rchild);
			if(cur->lchild != NULL)
				s.push(cur->lchild);
		}
	}
}

BiTree createBiTree() {
	BiTree t;
	DataType ch;
	scanf("%d", &ch);
	if(ch == 0)
		t = NULL;
	else {
		if(!(t = (BiTNode*)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		t->val = ch;
		printf ("\n������%d�������ӽ��:", t->val);
		t->lchild = createBiTree();
		printf ("\n������%d�������ӽ��:", t->val);
		t->rchild = createBiTree();
	}
	return t;
}

int main() {
	BiTree t;
	printf("�������Ľ����������롰0����ʾ��������\n");
    printf ("���������㣺\n");
	t = createBiTree();
	printf("%s\n", "create success!");
	
	printf("%s\n", "�ݹ�ǰ��");
	preOrder(t);
	printf("\n");
	printf("%s\n", "�ݹ�����");
	inOrder(t);
	printf("\n");
	printf("%s\n", "�ݹ����");
	postOrder(t);
	printf("\n");
	
	printf("%s\n", "�ǵݹ�ǰ��");
	preOrder1(t);
	printf("\n");
	printf("%s\n", "�ǵݹ�����");
	inOrder1(t);
	printf("\n");
	printf("%s\n", "�ǵݹ����");
	postOrder1(t);
	printf("\n");
	system("pause");
	return 0;
}
