#include <iostream>
using namespace std;

#define ERROR 0
#define OK 1

typedef int ElemType;
typedef int Status;

// 定义节点
typedef struct LNode {
	ElemType data;
	LNode* next;
} LNode, * LinkList;

// 初始化单链表
void InitLinkList(LinkList& L) {
	L = NULL; // 将链表头指针置为空
	//如果是有亚头节点的单链表
	//L = new LNode;
	//L->next = NULL;
}

// 创建单链表
void CreateLinkList(LinkList& L, int n) {
	LNode* p, * q;
	L = new LNode; // 创建头节点
	L->next = NULL; // 头节点的next指针初始化为NULL
	q = L; // q指向头节点
	cout << "Please input " << n << " elements: ";
	for (int i = 0; i < n; ++i) {
		p = new LNode; // 创建新节点
		cin >> p->data; // 输入节点数据
		p->next = NULL; // 新节点的next指针初始化为NULL
		q->next = p; // 将新节点插入到链表中
		q = p; // 更新q指向新节点
	}
}

// 插入节点
Status InsertLinkList(LinkList& L, int i, ElemType e) {
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return ERROR; // 插入位置不合法

	LNode* s = new LNode; // 创建新节点
	s->data = e; // 设置新节点数据
	s->next = p->next; // 将新节点插入到链表中
	p->next = s;
	return OK;
}

// 删除节点
Status DeleteLinkList(LinkList& L, int i, ElemType& e) {
	LNode* p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) return ERROR; // 删除位置不合法

	LNode* q = p->next; // 待删除节点
	e = q->data; // 获取待删除节点数据
	p->next = q->next; // 删除节点
	delete q; // 释放被删除节点的内存
	return OK;
}

// 获取元素
Status GetElem(LinkList L, int i, ElemType& e) {
	LNode* p = L->next; // 跳过头节点
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR; // 查找位置不合法

	e = p->data;
	return OK;
}

// 打印链表
void PrintLinkList(LinkList L) {
	LNode* p = L->next; // 跳过头节点
	cout << "LinkList: ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//int main() {
//	LinkList L;
//	InitLinkList(L);
//	CreateLinkList(L, 5);
//	PrintLinkList(L);
//
//	// 测试插入
//	InsertLinkList(L, 3, 10);
//	PrintLinkList(L);
//
//	// 测试删除
//	ElemType deleted;
//	DeleteLinkList(L, 2, deleted);
//	PrintLinkList(L);
//
//	// 测试获取元素
//	ElemType elem;
//	GetElem(L, 3, elem);
//	cout << "Element at position 3: " << elem << endl;
//
//	return 0;
//}