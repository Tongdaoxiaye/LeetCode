#include <iostream>
using namespace std;

#define ERROR 0
#define OK 1
#define MAXSIZE 100
typedef int Status;
//顺序栈还是链栈？
//首先回顾一下顺序栈
typedef struct {
	int* top;
	int* base;
	int stacksize;
}SqStack;

//初始化
Status InitSqStack(SqStack& S) {
	//首先分配一个可用的数组空间
	S.base = new int[MAXSIZE];
	//然后初始化为空栈
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//入栈
Status Push(SqStack& S, int e) {
	if (S.top - S.base == MAXSIZE) return ERROR;
	*S.top = e;
	S.top++;
	return OK;
}
//出栈
Status Pop(SqStack& S, int e) {
	if (S.top == S.base) return ERROR;
	e = *S.top;
	S.top--;
	return OK;
}
//取栈顶元素
int GetElem(SqStack S) {
	return *(S.top - 1);
}
//打印输出
void PrintSqStack(SqStack S) {
	while (S.top - S.base != 0)
		cout << *--S.top << " ";
}
//判断是不是空栈
bool IsEmpty(SqStack S) {
	if (S.top == S.base) return true;
	return false;
}
int main() {
	SqStack S;
	InitSqStack(S);
	for (int i = 0;i < 5;i++) {
		Push(S, i);
	}
	PrintSqStack(S);
	cout << endl;
	cout << GetElem(S) << endl;
	cout << IsEmpty(S);
}
