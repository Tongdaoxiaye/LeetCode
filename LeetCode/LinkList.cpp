#include <iostream>
using namespace std;

//链表的结构
typedef struct LNode {
	int data;
	LNode* next;
}LNode,*LinkList;

//初始化(带头结点)
void InitLinkList(LinkList& L) {
	L = new LNode();
	L->next = NULL;
}

////初始化(不带头结点)
//void InitLinkList(LinkList& L) {
//	L = NULL;
//}

//判空(带头结点)
bool isEmpty(LinkList L) {
	return L->next == NULL;//不是哥们这能写成"="？我就说怎么一使用判空整个程序就出错
}

////判空(不带头结点)
//bool isEmpty(LinkList L) {
//	return L == NULL;
//}

//求表长(带头结点)
int Length(LinkList L) {
	int length=0;
	LNode* p = L;
	while (p->next != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

////求表长(不带头结点)
//int Length(LinkList L) {
//	int length = 0;
//	LNode* p = L;
//	while (p != NULL) {
//		length++;
//		p = p->next;
//	}
//	return length;
//}

//插入数据结点
bool InsertNode(LinkList &L,int i,int e) {

	//判断插入位置i的合法性
	if (i < 1) return false;

	//创建新的结点指针并指向头结点
	LNode* p = L;

	////如果是从头部插入，那么就需要更新头结点
	//if (i == 1) {
	//	//创建新的数据结点并传入数据
	//	LNode* s = new LNode();
	//	s->data = e;

	//	//插入结点
	//	s->next = p;

	//	//更新头结点
	//	L = s;

	//	return true;
	//}

	//通过while循环找到待插入结点的前一个结点
	int j = 1;//带头结点j=2，否则为1

	while (j < i && p) {//这里的&&请不要写成|| ！！！
		j++;
		p = p->next;
	}

	//如果p为NULL，说明即使遍历完了所有结点都没有到第i个位置，即i为不合法位置
	if (!p) return false;

	//创建新的数据结点并传入数据
	LNode* s = new LNode();
	s->data = e;
	
	//插入结点
	s->next = p->next;
	p->next = s;

	return true;
}

//通过头插法建立链表
void FrontCreate(LinkList& L,int x) {
	int e;
	for (int i = 1;i <= x;i++) {
		cout << "请输入第"<<i<<"个数据：" << endl;
		cin >> e;
		InsertNode(L, 1, e);
	}
}

//通过尾插法建立链表
void RearCreate(LinkList& L, int x) {
	int e;
	for (int i = 1;i <= x;i++) {
		cout << "请输入第" << i << "个数据：" << endl;
		cin >> e;
		InsertNode(L, i, e);
	}
}

//删除结点
bool DeleteNode(LinkList& L, int i, int& e) {

	//判断删除位置的合理性
	if (i<1 || isEmpty(L)) return false;

	//创建新结点指针并指向头结点
	LNode* p = L;

	////如果删除的是第一个结点，就需要更新头结点
	//if (i == 1) {
	//	//记录被删除的值
	//	e = p->data;

	//	//执行删除操作,即更新头结点
	//	L = L->next;
	//	free(p);

	//	return true;
	//}

	//通过while循环找到待删除结点的前一个结点
	int j = 1;//如果是带头结点要改成j = 1,否则为2
	while (j < i && p) {
		j++;
		p = p->next;
	}

	//如果p为NULL，说明即使遍历完了所有结点都没有到第i个位置，即i为不合法位置
	if (!p) return false;

	//暂存待删除结点，后续释放内存空间
	LNode* temp = p->next;

	//记录被删除的值
	e = temp->data;

	//执行删除操作
	p->next = temp->next;
	free(temp);

	return true;
}

//打印输出
void PrintLinkList(LinkList L) {
	LNode* p = L->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

////打印输出(不带头结点)
//void PrintLinkList(LinkList L) {
//	LNode* p = L;
//	while (p) {
//		cout << p->data << " ";
//		p = p->next;
//	}
//	cout << endl;
//}

//测试类
int main() {
	//必要的声明
	int e;
	LinkList L;

	//初始化
	InitLinkList(L);

	////输入数据1
	//FrontCreate(L, 5);
	
	//输入数据2
	RearCreate(L, 5);

	//删除数据
	DeleteNode(L, 2, e);
	cout << "被删除的数据是：" << e << endl;

	//打印输出
	PrintLinkList(L);
	cout << "表长为：" << Length(L) << endl;

	return 0;
}