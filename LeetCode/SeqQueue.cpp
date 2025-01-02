#include <iostream>
using namespace std;

#define maxsize 5

//˳����еĽṹ(ѭ������)
typedef struct SeqQueue {
	int data[maxsize];
	int front;
	int rear;
	int length;
}SeqQueue;

//��ʼ��
void InitSeqQueue(SeqQueue &Q) {
	Q.rear = Q.front = 0;
	Q.length = 0; //���벻Ҫ��ɵд��int length=0
}

//�п�
bool isEmpty(SeqQueue Q) {
	return Q.length == 0;
}

//���
bool EnQueue(SeqQueue& Q, int e) {
	if (Q.rear==Q.front && Q.length!=0) return false;//�ж϶����Ƿ�����
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % maxsize; //��ע��������ȡģ����'%'��������'/'
	Q.length++;
	return true;
}

//����
bool OutQueue(SeqQueue& Q, int &e) {//��ע�����÷��ŵ�ʹ��
	if (isEmpty(Q)) return false;
	e = Q.data[Q.front++];
	Q.length--;
	return true;
}

//�������
void PrintSeqQueue(SeqQueue Q) {
	int i = 0;
	while (i < Q.length) {
		cout << Q.data[(Q.front + i) % maxsize] << " ";
		i++;
	}
}

//������
int main() {
	//����ѭ�����к���������
	int e;
	SeqQueue Q;

	//��ʼ��
	InitSeqQueue(Q);

	//���
	for (int i = 0;i < 5;i++) {
		cin >> e;
		EnQueue(Q, e);
	}

	//����
	OutQueue(Q, e);
	cout << "����һ�����ݣ�" << e << endl;

	//�����һ��ֵ
	int x = 6;
	EnQueue(Q, x);

	//��ӡ���
	PrintSeqQueue(Q);
}