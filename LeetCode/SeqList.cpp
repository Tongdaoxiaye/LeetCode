#include <iostream>
using namespace std;

//顺序表在分配内存空间时有静态分配和动态分配两种方式(默认展示静态)
#define maxsize 100
//#define InitSize 100

//顺序表的结构(静态)
typedef struct SeqList {
	int data[maxsize];
	int length;
}SeqList;

////顺序表的结构(动态)
//typedef struct SeqList {
//	int* data;
//	int length;
//	int MaxSize;
//}SeqList;

//初始化(静态)
void InitSeqList(SeqList &S) {
	S.length = 0;
}

////初始化(动态)
//void InitSeqList(SeqList& S) {
//	S.data = (int*)malloc(sizeof(int*) * InitSize);//分配内存空间
//	S.length = 0;
//	S.MaxSize = InitSize;
//}

//插入
bool InsertElem(SeqList& S,int i,int e) {
	//判断插入位置i的合法性
	if (i<1 || i>S.length + 1) return false;

	//判断顺序表是否已满
	if (S.length == maxsize) return false;

	//将第i个及其后面所有元素都后移一位腾出位置，即data[i-1]以及之后的所有元素后移一位
	for (int j = S.length;j >= i;j--) {
		S.data[j] = S.data[j-1];
	}

	//腾出位置i-1后，插入数据
	S.data[i - 1] = e;

	//更新表长
	S.length++;

	return true;
}

//删除
bool DeleteElem(SeqList& S,int i,int& e) {
	//判断删除第i个位置的合法性
	if (i<1 || i>S.length) return false;

	//判断顺序表是否为空
	if (S.length == 0) return false;

	//存储被删除的元素
	e = S.data[i - 1];

	//要删除第i个位置，可以采用将data[i-1]覆盖掉的方法
	for (int j = i;j < S.length;j++) {
		S.data[j-1] = S.data[j];
	}

	//更新表长
	S.length--;

	return true;
}

//按值查找
int GetElem(SeqList S,int e) {
	for (int i = 0;i < S.length;i++) {
		if (S.data[i] == e) return i+1;//返回查找元素的位序
	}
	return NULL;
}

//打印输出
void PrintSeqList(SeqList S) {
	for (int i = 0;i < S.length;i++) cout << S.data[i] << " ";
	cout << endl;
}

//测试类
//int main() {
//	//必要的声明
//	int x;
//	int e;
//	SeqList S;
//
//	//初始化
//	InitSeqList(S);
//
//	//插入数据
//	for (int i = 1;i <= 5;i++) {
//		cout << "请输入第"<<i<<"个数据：" << endl;
//		cin >> e;
//		InsertElem(S, i, e);
//	}
//
//	//删除数据
//	cout << "请输入想要删除的位置:"<< endl;
//	cin >> x;
//	DeleteElem(S, x, e);
//	cout << "被删除的数据为：" << e << endl;
//
//	//按值查找
//	cout << "请输入想要查询的值：" << endl;
//	cin >> x;
//	cout << "查找的元素在第" << GetElem(S, x) << "位" << endl;
//
//	//打印输出
//	PrintSeqList(S);
//
//	return 0;
//}
