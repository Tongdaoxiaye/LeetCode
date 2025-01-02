#include <iostream>
using namespace std;

#define MaxSize 100

//ջ���еĽṹ
typedef struct QNode {
	int data;
	QNode* next;//���ﲻҪд��int*next������ָ��������ṹ��Ľṹ��ָ�룡
}QNode, * QueuePtr;

//ʹ������ָ��Ψһȷ���ö���
typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//��ʼ��
void InitQueue(LinkQueue &Q){
	//��Ҫ��һ��ͷ�ڵ�
	QNode* q = new QNode();
	q->next = NULL;
	//ָ����ͷ��β���ָ��
	Q.front = Q.rear = q;
}

//�п�
bool isEmpty(LinkQueue Q) {
	return Q.front->next == NULL;
}

//���
void EnQueue(LinkQueue& Q, int e) {
	//�����µĶ��н��
	QNode* p = new QNode();
	p->data = e;
	p->next = NULL;
	//���뵽��β�����¶�βָ��
	Q.rear->next = p;
	Q.rear = p;
}

//����
bool OutQueue(LinkQueue &Q, int &e) {
	if (isEmpty(Q)) return false;
	QNode* p = Q.front ->next;//����ͷ�ڵ����һ�����,����һ�����ݽڵ�
	e = p->data;
	Q.front->next = p->next;
	free(p);
	return true;
}

//��ӡ���
void PrintQueue(LinkQueue Q) {
	QueuePtr p = Q.front->next;
	while (p!= Q.rear) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}

//������
int main() {
	//��Ҫ������
	int e;
	LinkQueue Q;

	//��ʼ��
	InitQueue(Q);

	//���
	for (int i = 0;i < 5;i++) {
		cin >> e;
		EnQueue(Q, e);
	}

	//����
	OutQueue(Q, e);
	cout << "������һ�����ݣ�" << e << endl;

	//�����һ��Ԫ��
	int x = 6;
	EnQueue(Q, x);

	//��ӡ���
	PrintQueue(Q);

	return 0;
}