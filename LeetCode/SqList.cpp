#include <iostream>
using namespace std;
#define MAXSIZE 100
#define ERROR 0
#define OVERFLOW -2
#define OK 1
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType* elem;
    int length;
}SqList;

Status InitList(SqList& L) {
    L.elem = new ElemType[MAXSIZE];
    if (L.elem == NULL) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status ListInsert(SqList& L, int i, ElemType e) {
    if ((i < 1) || (i > L.length + 1)) return ERROR;
    if (L.length == MAXSIZE) return ERROR;
    L.length++;
    int j;
    for (j = L.length - 1;j >= i;j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    return OK;
}

Status ListDelete(SqList& L, int i) {
    if (L.elem == NULL) return ERROR;
    if ((i < 1) || (i > L.length)) return ERROR;
    int j;
    for (j = i;j < L.length;j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return OK;
}

Status GetElem(SqList L, int i, ElemType& e) {
    if ((i < 1) || (i > L.length)) return ERROR;
    e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0;i < L.length;i++) {
        if (L.elem[i] == e) return i + 1;
    }
    return 0;
}

void ListPrint(SqList L) {
    int i;
    int e;
    if (L.elem == NULL) {
        cout << "NULL\n";
        return;
    }
    for (i = 1;i <= L.length;i++) {
        GetElem(L, i, e);
        cout << e << " ";
    }
    cout << endl;
}

//int main() {
//    SqList L;
//    int i, n, x;
//    InitList(L);
//    cin >> n;
//    for (i = 1;i <= n;i++) {
//        cin >> x;
//        ListInsert(L, i, x);
//    }
//    cin >> i;
//    ListDelete(L, i);
//    ListPrint(L);
//    cin >> x;
//    cout << "Locate=" << LocateElem(L, x);
//    return 0;
//}