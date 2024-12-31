#include <iostream>
using namespace std;

//链栈结点的结构
typedef struct LNode{//注意这里的LNode不可以省略
	int data;
	LNode *next;
}LNode, * LinkStack;

//初始化(带头结点)
void InitLinkStack(LinkStack &L) {
	L = new LNode();//这里绝对绝对不要忘记分配内存空间！
	L->next = NULL;
}

//判空
bool IsEmpty(LinkStack L) {
	return L->next == NULL;
}

//入栈
void PushStack(LinkStack& L, int e) {
	LNode* p = new LNode();
	p->data = e;
	p->next = L->next;
	L->next = p;
}

//出栈
void OutStack(LinkStack &L,int &e) {
	if (!IsEmpty(L)) {
		LNode* p = L->next;
		e = p->data;//保存被删除的值
		L->next = p->next;
		free(p);
	}
}

//求链栈长度
int GetLength(LinkStack L) {
	int length = 0;
	LNode* p = L;//从头结点开始
	while (p->next) {
		p = p->next;
		length++;
	}
	return length;
}

//输出链栈(从栈顶开始输出)
void PrintLinkStack(LinkStack L) {
	LNode* p = L;
	while (p->next) {
		p = p->next;
		cout << p->data << " ";//这两句的顺序不要反了，不然你会输出头结点的无效值
	}
	cout << endl;
}

//测试
int main() {
	//声明链栈
	LinkStack L;
	//声明待存入的数据
	int e;

	//初始化
	InitLinkStack(L);

	//输入数据
	cout << "请输入5个数据：";
	for (int i = 0;i < 5;i++) {
		cin >> e;
		PushStack(L,e);
	}
	//输出数据
	cout << "链栈的长度为："<<GetLength(L) << endl;//输出链栈长度
	PrintLinkStack(L);

	//删除数据-删除栈顶元素
	OutStack(L, e);
	//输出链栈长度
	cout << "链栈的长度为："<<GetLength(L) << endl;
	PrintLinkStack(L);//输出测验

	return 0;
}