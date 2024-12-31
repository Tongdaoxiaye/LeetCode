#include <iostream>
using namespace std;

//单链表的结构
typedef struct LinkNode{
	int val;
	LinkNode* next;
}LinkNode;

//链队列的结构
typedef struct{
	LinkNode* front;
	LinkNode* rear;
	int size;
}LinkQueue;

//初始化
void InitLinkQueue(LinkQueue &q) {
	q.front = q.rear = nullptr;
	q.size = 0;
}

//建立节点
LinkNode* BuyLinkNode(int e) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL) return NULL;//malloc 函数在内存分配失败时会返回 NULL。如果没有对返回值 p 进行检查，
	p->next = NULL; //直接对 p 进行解引用（如 p->next = NULL 或 p->val = e），会导致空指针解引用的错误。
	p->val = e;
	return p;
}

//判空
bool IsEmpty(LinkQueue q) {
	return q.size == 0;
}

//入队
void EnQueue(LinkQueue &q,int e) {
	LinkNode* p = BuyLinkNode(e);
	if (IsEmpty(q)) q.rear = q.front = p;
	else {
		q.rear->next = p;
		q.rear = p;
	}
	q.size++;
}

//出队
int DeQueue(LinkQueue& q) {
	if (IsEmpty(q)) return -1;
	LinkNode* temp = q.front;
	int e = temp->val;
	q.front = q.front->next;
	free(temp);
	q.size--;
	return e;
}


//遍历队列
void PrintQueue(LinkQueue q) {
	int e=0;
	while (!IsEmpty(q)) {
		cout<<DeQueue(q)<<" ";
	}
}

int main03() {
	LinkQueue q;
	InitLinkQueue(q);
	for (int i = 1;i <= 5;i++) {
		LinkNode* p = BuyLinkNode(i);
		EnQueue(q,p->val);
	}
	PrintQueue(q);
	return 0;
}