#include <iostream>
using namespace std;

#define maxsize 100

//顺序栈的结构
typedef struct SeqStack{
	int data[maxsize];
	int top;
	int length;
}SeqStack;

//初始化
void InitSeqStack(SeqStack& S) {
	S.length = 0;
	S.top = -1;
}

//判空
bool isEmpty(SeqStack S) {
	return S.length == 0;
}

//入栈
bool PushStack(SeqStack& S,int e) {
	if (S.length == maxsize) return false;
	S.data[++S.top] = e;
	S.length++;
	return true;
}

//出栈
bool PopStack(SeqStack& S, int e) {
	if (isEmpty(S)) return false;
	e = S.data[S.top--];
	S.length--;
	return true;
}

//打印输出(正序输出)
void PrintSeqStack(SeqStack S) {
	for (int i = 0;i < S.length;i++) {
		cout << S.data[i] << " ";
	}
	cout << endl;
}

//测试类
int main() {
	//必要的声明
	int e;
	SeqStack S;

	//初始化
	InitSeqStack(S);

	//入栈
	for (int i = 0;i < 5;i++) {
		cin >> e;
		PushStack(S, e);
	}

	//出栈
	PopStack(S, e);
	cout << "弹出数据：" << e << endl;

	//打印输出
	PrintSeqStack(S);
}