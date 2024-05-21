#include <iostream>
using namespace std;

#define ERROR 0
#define OK 1
#define MAXSIZE 100

typedef int Status;
typedef struct SqQueue {
	//存储空间的基地址
	int* base;
	int front;
	int rear;
}SqQueue;

//初始化
Status InitSqQueue(SqQueue &S) {
	//分配内存空间
	S.base = new int[MAXSIZE];
	S.front = S.rear = 0;
	return OK;
}

//入队
Status EnQueue(SqQueue &S,int e) {
	if (S.rear - S.front == MAXSIZE) return ERROR;//队满
	S.base[S.rear] = e;
	S.rear = (S.rear + 1) % MAXSIZE;
	return OK;
}

//出队
Status DeQueue(SqQueue& S, int e) {
	if ((S.rear + 1) % MAXSIZE == S.front) return ERROR;//队空
	e = S.base[S.front];//保留队头元素
	S.front = (S.front + 1) % MAXSIZE;
	return OK;
}

//打印顺序队列
void PrintSqQueue(SqQueue S) {
	while (S.front!=S.rear) {
		cout << S.base[S.front++] << " ";
	}
}

//求队列长度
int GetLength(SqQueue S) {
	return (S.rear - S.front + MAXSIZE) % MAXSIZE;
}

//取队头元素
int GetElem(SqQueue S) {
	return S.base[S.front];
}

int main() {
	SqQueue S;
	InitSqQueue(S);
	for (int i = 1;i <= 5;i++) {
		EnQueue(S, i);
	}
	PrintSqQueue(S);
	cout << endl;
	cout << GetLength(S)<<endl;
	cout << GetElem(S)<<endl;
}
