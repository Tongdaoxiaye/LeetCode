#include <iostream>
using namespace std;

#define maxsize 100

//˳��ջ�Ľṹ
typedef struct SeqStack{
	int data[maxsize];
	int top;
	int length;
}SeqStack;

//��ʼ��
void InitSeqStack(SeqStack& S) {
	S.length = 0;
	S.top = -1;
}

//�п�
bool isEmpty(SeqStack S) {
	return S.length == 0;
}

//��ջ
bool PushStack(SeqStack& S,int e) {
	if (S.length == maxsize) return false;
	S.data[++S.top] = e;
	S.length++;
	return true;
}

//��ջ
bool PopStack(SeqStack& S, int e) {
	if (isEmpty(S)) return false;
	e = S.data[S.top--];
	S.length--;
	return true;
}

//��ӡ���(�������)
void PrintSeqStack(SeqStack S) {
	for (int i = 0;i < S.length;i++) {
		cout << S.data[i] << " ";
	}
	cout << endl;
}

//������
int main() {
	//��Ҫ������
	int e;
	SeqStack S;

	//��ʼ��
	InitSeqStack(S);

	//��ջ
	for (int i = 0;i < 5;i++) {
		cin >> e;
		PushStack(S, e);
	}

	//��ջ
	PopStack(S, e);
	cout << "�������ݣ�" << e << endl;

	//��ӡ���
	PrintSeqStack(S);
}