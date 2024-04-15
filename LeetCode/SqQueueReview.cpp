#include<iostream>
using namespace std;
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int QElemType;

//顺序队列结构
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;

//队列初始化
Status InitQueue(SqQueue &Q) {
	//构造一个空队列
	Q.base = new QElemType[MAXQSIZE];//即创建了一个数组,Q.base就是数组首地址
	if (!Q.base) exit(OVERFLOW);//存储分配失败
	Q.front = Q.rear = 0;//表示队列为空
	return OK;
}

//求队列长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE)% MAXQSIZE;
};

//入队
Status EnQueue(SqQueue& Q, QElemType e) {
	//首先要考虑是否满队列
	if (QueueLength(Q) == MAXQSIZE) return ERROR;
	//入队后，队尾rear指针+1
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;//+1取模-->应对循环队列
	return OK;
};

//出队列
Status DeQueue(SqQueue& Q,QElemType &e) {
	//首先考虑是否空队列
	if (QueueLength(Q) == 0) return ERROR;
	//保留队头元素
	e = Q.base[Q.front];
	//出列后，队首front指针+1
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
};

//取队头元素
QElemType GetHead(SqQueue Q) {
	//首先考虑是否空队列
	if (QueueLength(Q) == 0) return ERROR;
	return Q.base[Q.front];
}


//输出队列
void PrintQueue(SqQueue Q) {
	QElemType e;
	while (QueueLength(Q) != 0) {
		DeQueue(Q, e);
		cout << e << " ";
	}
	cout << endl;
}




////测试
//int main() {
//	//创建一个队列并初始化
//	SqQueue Q;
//	InitQueue(Q);
//	QElemType e;
//	//入队N个元素
//	for (int i = 0;i < 5;i++) {
//		cin >> e;
//		EnQueue(Q, e);
//	}
//	PrintQueue(Q);//输出队列检测是否正确入队，其实也顺带把出队也检测了
//
//	//输出队头元素以及队列长度
//	cout << "队头元素为" << GetHead(Q) << endl;
//	cout << "队列长度为" << QueueLength(Q) << endl;
//
//
//	return 0;
//}