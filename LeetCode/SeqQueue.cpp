#include <iostream>
using namespace std;

#define maxsize 5

//顺序队列的结构(循环队列)
typedef struct SeqQueue {
	int data[maxsize];
	int front;
	int rear;
	int length;
}SeqQueue;

//初始化
void InitSeqQueue(SeqQueue &Q) {
	Q.rear = Q.front = 0;
	Q.length = 0; //①请不要犯傻写成int length=0
}

//判空
bool isEmpty(SeqQueue Q) {
	return Q.length == 0;
}

//入队
bool EnQueue(SeqQueue& Q, int e) {
	if (Q.rear==Q.front && Q.length!=0) return false;//判断队列是否已满
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % maxsize; //②注意这里是取模运算'%'不是整除'/'
	Q.length++;
	return true;
}

//出队
bool OutQueue(SeqQueue& Q, int &e) {//③注意引用符号的使用
	if (isEmpty(Q)) return false;
	e = Q.data[Q.front++];
	Q.length--;
	return true;
}

//输出队列
void PrintSeqQueue(SeqQueue Q) {
	int i = 0;
	while (i < Q.length) {
		cout << Q.data[(Q.front + i) % maxsize] << " ";
		i++;
	}
}

//测试类
int main() {
	//声明循环队列和输入数据
	int e;
	SeqQueue Q;

	//初始化
	InitSeqQueue(Q);

	//入队
	for (int i = 0;i < 5;i++) {
		cin >> e;
		EnQueue(Q, e);
	}

	//出队
	OutQueue(Q, e);
	cout << "出队一个数据：" << e << endl;

	//再入队一个值
	int x = 6;
	EnQueue(Q, x);

	//打印输出
	PrintSeqQueue(Q);
}