#include <iostream>
using namespace std;

//����Ľṹ
typedef struct LNode {
	int data;
	LNode* next;
}LNode,*LinkList;

//��ʼ��(��ͷ���)
void InitLinkList(LinkList& L) {
	L = new LNode();
	L->next = NULL;
}

//�п�
bool isEmpty(LinkList L) {
	return L->next == NULL;//���Ǹ�������д��"="���Ҿ�˵��ôһʹ���п���������ͳ���
}

//���
int Length(LinkList L) {
	int length=0;
	LNode* p = L;
	while (p->next != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

//�������ݽ��
bool InsertNode(LinkList &L,int i,int e) {

	//�жϲ���λ��i�ĺϷ���
	if (i < 1) return false;

	//�����µĽ��ָ�벢ָ��ͷ���
	LNode* p = L;

	//ͨ��whileѭ���ҵ����������ǰһ�����
	int j = 1;
	while (j < i && p) {//�����&&�벻Ҫд��|| ������
		j++;
		p = p->next;
	}

	//���pΪNULL��˵����ʹ�����������н�㶼û�е���i��λ�ã���iΪ���Ϸ�λ��
	if (!p) return false;

	//�����µ����ݽ�㲢��������
	LNode* s = new LNode();
	s->data = e;
	
	//������
	s->next = p->next;
	p->next = s;

	return true;
}

//ͨ��ͷ�巨��������
void FrontCreate(LinkList& L,int x) {
	int e;
	for (int i = 1;i <= x;i++) {
		cout << "�������"<<i<<"�����ݣ�" << endl;
		cin >> e;
		InsertNode(L, 1, e);
	}
}

//ͨ��β�巨��������
void RearCreate(LinkList& L, int x) {
	int e;
	for (int i = 1;i <= x;i++) {
		cout << "�������" << i << "�����ݣ�" << endl;
		cin >> e;
		InsertNode(L, i, e);
	}
}

//ɾ�����
bool DeleteNode(LinkList& L, int i, int& e) {

	//�ж�ɾ��λ�õĺ�����
	if (i<1 || isEmpty(L)) return false;

	//�����½��ָ�벢ָ��ͷ���
	LNode* p = L;

	//ͨ��whileѭ���ҵ���ɾ������ǰһ�����
	int j = 1;
	while (j < i && p) {
		j++;
		p = p->next;
	}

	//���pΪNULL��˵����ʹ�����������н�㶼û�е���i��λ�ã���iΪ���Ϸ�λ��
	if (!p) return false;

	//�ݴ��ɾ����㣬�����ͷ��ڴ�ռ�
	LNode* temp = p->next;

	//��¼��ɾ����ֵ
	e = temp->data;

	//ִ��ɾ������
	p->next = temp->next;
	free(temp);

	return true;
}

//��ӡ���
void PrintLinkList(LinkList L) {
	LNode* p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//������
int main() {
	//��Ҫ������
	int e;
	LinkList L;

	//��ʼ��
	InitLinkList(L);

	//��������1
	FrontCreate(L, 5);
	////��������2
	//RearCreate(L, 5);

	//ɾ������
	DeleteNode(L, 2, e);
	cout << "��ɾ���������ǣ�" << e << endl;

	//��ӡ���
	PrintLinkList(L);
	cout << "��Ϊ��" << Length(L) << endl;

	return 0;
}