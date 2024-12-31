#include <iostream>
using namespace std;

//������Ľṹ
typedef struct LinkNode{
	int val;
	LinkNode* next;
}LinkNode;

//�����еĽṹ
typedef struct{
	LinkNode* front;
	LinkNode* rear;
	int size;
}LinkQueue;

//��ʼ��
void InitLinkQueue(LinkQueue &q) {
	q.front = q.rear = nullptr;
	q.size = 0;
}

//�����ڵ�
LinkNode* BuyLinkNode(int e) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	if (p == NULL) return NULL;//malloc �������ڴ����ʧ��ʱ�᷵�� NULL�����û�жԷ���ֵ p ���м�飬
	p->next = NULL; //ֱ�Ӷ� p ���н����ã��� p->next = NULL �� p->val = e�����ᵼ�¿�ָ������õĴ���
	p->val = e;
	return p;
}

//�п�
bool IsEmpty(LinkQueue q) {
	return q.size == 0;
}

//���
void EnQueue(LinkQueue &q,int e) {
	LinkNode* p = BuyLinkNode(e);
	if (IsEmpty(q)) q.rear = q.front = p;
	else {
		q.rear->next = p;
		q.rear = p;
	}
	q.size++;
}

//����
int DeQueue(LinkQueue& q) {
	if (IsEmpty(q)) return -1;
	LinkNode* temp = q.front;
	int e = temp->val;
	q.front = q.front->next;
	free(temp);
	q.size--;
	return e;
}


//��������
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