#include <iostream>
using namespace std;

#define MaxSize 100

//栈队列的结构
typedef struct QNode {
	int data;
	QNode* next;//这里不要写成int*next，这是指向结点这个结构体的结构体指针！
}QNode, * QueuePtr;

//使用两个指针唯一确定该队列
typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化
void InitQueue(LinkQueue &Q){
	//需要有一个头节点
	QNode* q = new QNode();
	q->next = NULL;
	//指定队头队尾结点指针
	Q.front = Q.rear = q;
}

//判空
bool isEmpty(LinkQueue Q) {
	return Q.front->next == NULL;
}

//入队
void EnQueue(LinkQueue& Q, int e) {
	//创建新的队列结点
	QNode* p = new QNode();
	p->data = e;
	p->next = NULL;
	//加入到队尾并更新队尾指针
	Q.rear->next = p;
	Q.rear = p;
}

//出队
bool OutQueue(LinkQueue &Q, int &e) {
	if (isEmpty(Q)) return false;
	QNode* p = Q.front ->next;//保存头节点的下一个结点,即第一个数据节点
	e = p->data;
	Q.front->next = p->next;
	free(p);
	return true;
}

//打印输出
void PrintQueue(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p!= Q.rear) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}

//测试类
int main() {
	//必要的声明
	int e;
	LinkQueue Q;

	//初始化
	InitQueue(Q);

	//入队
	for (int i = 0;i < 5;i++) {
		cin >> e;
		EnQueue(Q, e);
	}

	//出队
	OutQueue(Q, e);
	cout << "出队了一个数据：" << e << endl;

	//再入队一个元素
	int x = 6;
	EnQueue(Q, x);

	//打印输出
	PrintQueue(Q);

	return 0;
}