#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
//链栈的结构定义--不像顺序栈那样需要一个数组空间而是需要一个一个节点连接起来
typedef struct StackNode{
	int data;
	StackNode* next;//后继指针
}StackNode,*LinkStack;
//初始化
Status InitLinkStack(LinkStack &S) {
	//创建一个空链栈,栈顶指针置为NULL
	S = NULL;
	return OK;
}
//入栈
Status Push(LinkStack &S,int e) {
	//创建一个新节点用于存放新数据
	StackNode *p = new StackNode;
	p->data = e;
	p->next = S;//其实类似于头插法
	S = p;
	return OK;
}
//出栈
Status Pop(LinkStack& S, int e) {
	//获取并释放栈顶元素
	e = S->data;
	LinkStack p = S;
	S = S->next;
	delete p;
	return OK;
}
//打印链栈
void PrintLinkStack(LinkStack S) {
	//从栈顶元素开始打印一直到栈底
	while (S) {
		cout << S->data << " ";
		S = S->next;
	}
}
//获取链栈顶元素
int GetElem(LinkStack S) {
	return S->data;
}
//测试
/*
int main() {
	LinkStack S;
	InitLinkStack(S);
	for (int i = 1;i <= 5;i++) {
		Push(S,i);
	}
	PrintLinkStack(S);
	cout << endl;
	cout << GetElem(S) << endl;

}
*/