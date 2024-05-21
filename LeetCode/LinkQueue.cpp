#include <iostream>
using namespace std;
#define ERROR 0
#define OK 1
#define MAXSIZE 100

typedef int Status;
//链队列的存储结构定义 -队列是从队尾入队头出的(先进先出)
typedef struct QNode {
	int data;
	QNode* next;
}QNode,*Queueptr;

typedef struct LinkQueue {
	Queueptr front;
	Queueptr rear;
}LinkQueue;

//初始化-创建一个只有头节点的空队列
Status InitLinkQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	Q.rear->next = NULL;
	return OK;
}

//入队
Status EnQueue(LinkQueue &Q,int e) {
	//创建一个新的节点来存放新数据
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;//更新队尾指针
	return OK;
}

//出队
Status DeQueue(LinkQueue& Q, int &e) {
	if (Q.rear == Q.front) return ERROR;
	QNode* p = Q.front->next;//用于暂存稍后释放内存
	e = p->data;//保存队头元素数据
	Q.front->next = Q.front->next->next;//因为头结点是亚头节点,数据开始存放是在下一个节点开始的
	if (Q.rear == p) Q.rear = Q.front;//删除的是队尾元素,那么队尾指针回归亚头节点
	delete p;
	return OK;
}

//打印链队列
void PrintLinkQueue(LinkQueue Q) {
	QNode *p = Q.front->next;
	while (p != NULL) {//不要使用p != Q.rear，因为Q.rear不一定指向NULL
 		cout << p->data << " ";
		p=p->next;//需要注意指针p指向的是节点，所以不要使用自增
	}
}
//获取队头元素
int GetElem(LinkQueue Q) {
	return Q.front->next->data;
}

//测试
int main() {
	LinkQueue Q;
	InitLinkQueue(Q);
	for (int i = 1;i <= 5; i++) {
		EnQueue(Q, i);
	}
	PrintLinkQueue(Q);
	cout << endl;
	for (int i = 1;i <= 3; i++) {
		DeQueue(Q, i);
	}
	PrintLinkQueue(Q);
	cout << endl << GetElem(Q) << endl;
}