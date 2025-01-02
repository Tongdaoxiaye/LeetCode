#include <iostream>
using namespace std;

//˳����ڷ����ڴ�ռ�ʱ�о�̬����Ͷ�̬�������ַ�ʽ(Ĭ��չʾ��̬)
#define maxsize 100
//#define InitSize 100

//˳���Ľṹ(��̬)
typedef struct SeqList {
	int data[maxsize];
	int length;
}SeqList;

////˳���Ľṹ(��̬)
//typedef struct SeqList {
//	int* data;
//	int length;
//	int MaxSize;
//}SeqList;

//��ʼ��(��̬)
void InitSeqList(SeqList &S) {
	S.length = 0;
}

////��ʼ��(��̬)
//void InitSeqList(SeqList& S) {
//	S.data = (int*)malloc(sizeof(int*) * InitSize);//�����ڴ�ռ�
//	S.length = 0;
//	S.MaxSize = InitSize;
//}

//����
bool InsertElem(SeqList& S,int i,int e) {
	//�жϲ���λ��i�ĺϷ���
	if (i<1 || i>S.length + 1) return false;

	//�ж�˳����Ƿ�����
	if (S.length == maxsize) return false;

	//����i�������������Ԫ�ض�����һλ�ڳ�λ�ã���data[i-1]�Լ�֮�������Ԫ�غ���һλ
	for (int j = S.length;j >= i;j--) {
		S.data[j] = S.data[j-1];
	}

	//�ڳ�λ��i-1�󣬲�������
	S.data[i - 1] = e;

	//���±�
	S.length++;

	return true;
}

//ɾ��
bool DeleteElem(SeqList& S,int i,int& e) {
	//�ж�ɾ����i��λ�õĺϷ���
	if (i<1 || i>S.length) return false;

	//�ж�˳����Ƿ�Ϊ��
	if (S.length == 0) return false;

	//�洢��ɾ����Ԫ��
	e = S.data[i - 1];

	//Ҫɾ����i��λ�ã����Բ��ý�data[i-1]���ǵ��ķ���
	for (int j = i;j < S.length;j++) {
		S.data[j-1] = S.data[j];
	}

	//���±�
	S.length--;

	return true;
}

//��ֵ����
int GetElem(SeqList S,int e) {
	for (int i = 0;i < S.length;i++) {
		if (S.data[i] == e) return i+1;//���ز���Ԫ�ص�λ��
	}
	return NULL;
}

//��ӡ���
void PrintSeqList(SeqList S) {
	for (int i = 0;i < S.length;i++) cout << S.data[i] << " ";
	cout << endl;
}

//������
//int main() {
//	//��Ҫ������
//	int x;
//	int e;
//	SeqList S;
//
//	//��ʼ��
//	InitSeqList(S);
//
//	//��������
//	for (int i = 1;i <= 5;i++) {
//		cout << "�������"<<i<<"�����ݣ�" << endl;
//		cin >> e;
//		InsertElem(S, i, e);
//	}
//
//	//ɾ������
//	cout << "��������Ҫɾ����λ��:"<< endl;
//	cin >> x;
//	DeleteElem(S, x, e);
//	cout << "��ɾ��������Ϊ��" << e << endl;
//
//	//��ֵ����
//	cout << "��������Ҫ��ѯ��ֵ��" << endl;
//	cin >> x;
//	cout << "���ҵ�Ԫ���ڵ�" << GetElem(S, x) << "λ" << endl;
//
//	//��ӡ���
//	PrintSeqList(S);
//
//	return 0;
//}
