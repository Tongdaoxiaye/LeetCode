#include <iostream>
using namespace std;

//��ջ���Ľṹ
typedef struct LNode{//ע�������LNode������ʡ��
	int data;
	LNode *next;
}LNode, * LinkStack;

//��ʼ��(��ͷ���)
void InitLinkStack(LinkStack &L) {
	L = new LNode();//������Ծ��Բ�Ҫ���Ƿ����ڴ�ռ䣡
	L->next = NULL;
}

//�п�
bool IsEmpty(LinkStack L) {
	return L->next == NULL;
}

//��ջ
void PushStack(LinkStack& L, int e) {
	LNode* p = new LNode();
	p->data = e;
	p->next = L->next;
	L->next = p;
}

//��ջ
void OutStack(LinkStack &L,int &e) {
	if (!IsEmpty(L)) {
		LNode* p = L->next;
		e = p->data;//���汻ɾ����ֵ
		L->next = p->next;
		free(p);
	}
}

//����ջ����
int GetLength(LinkStack L) {
	int length = 0;
	LNode* p = L;//��ͷ��㿪ʼ
	while (p->next) {
		p = p->next;
		length++;
	}
	return length;
}

//�����ջ(��ջ����ʼ���)
void PrintLinkStack(LinkStack L) {
	LNode* p = L;
	while (p->next) {
		p = p->next;
		cout << p->data << " ";//�������˳��Ҫ���ˣ���Ȼ������ͷ������Чֵ
	}
	cout << endl;
}

//����
int main() {
	//������ջ
	LinkStack L;
	//���������������
	int e;

	//��ʼ��
	InitLinkStack(L);

	//��������
	cout << "������5�����ݣ�";
	for (int i = 0;i < 5;i++) {
		cin >> e;
		PushStack(L,e);
	}
	//�������
	cout << "��ջ�ĳ���Ϊ��"<<GetLength(L) << endl;//�����ջ����
	PrintLinkStack(L);

	//ɾ������-ɾ��ջ��Ԫ��
	OutStack(L, e);
	//�����ջ����
	cout << "��ջ�ĳ���Ϊ��"<<GetLength(L) << endl;
	PrintLinkStack(L);//�������

	return 0;
}