#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
}LNode, * LinkList;

void CreateList(LinkList& L, int N) {
    L = new LNode;
    L->next = NULL;
    LNode* r = L;//保存当前的节点
    for (int i = 0;i < N;i++) {
        LNode* p = new LNode;
        p->data = i + 1;
        r->next = p;
        p->next = NULL;
        r = p;
    }
    r->next = L->next;//这一步是为了建立循环链表
}



Status ListDelete(LinkList& L, int i, ElemType& e) {
    LNode* p = L;
    int j = 1;
    while (p->next != L && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    LNode* s = p->next;
    p->next = s->next;
    e = s->data;
    delete s;
    return OK;
}

void ListPrint(LinkList L) {
    LNode* p = L->next;
    if (!p) cout << "NULL";
    while (p != L) {
        if (!p) break;
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


//int main() {
//    int N, n, m;//n为从第几个人开始报数,m为出圈间隔
//    ElemType e;
//    cin >> N;
//    int N2 = N;
//    if (N == 0) return ERROR;
//    LNode* L = new LNode;
//    CreateList(L, N);
//    // ListPrint(L);
//
//    cin >> n >> m;
//    int i = n;
//    int j = 1;
//    while (N2) {
//        if (i > N2) i = i - N2;
//        if (j == m) {
//            ListDelete(L, i, e);
//            j = 1;
//            cout << e << " ";
//            N2--;
//        }
//        else {
//            ++i;
//            ++j;
//        }
//    }
//    return 0;
//}
