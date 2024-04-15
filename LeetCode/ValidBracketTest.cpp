#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef char SElemType;
typedef int Status;
//顺序栈的结构
typedef struct {
    SElemType* base;    //栈底
    SElemType* top;     //栈顶
    int stacksize;
}SqStack;


//初始化顺序栈
Status InitStack(SqStack& S) {
    S.base = new SElemType[MAXSIZE];
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

//入栈
Status Push(SqStack& S, SElemType e) {
    if (S.top - S.base == S.stacksize) return ERROR;    //栈满返回错误
    *S.top++ = e;
    return OK;
}

//出栈
Status Pop(SqStack& S) {
    if (S.top == S.base) return ERROR;    //空栈返回错误
    S.top--;
    return OK;
}

//获取栈顶元素
SElemType GetElem(SqStack S) {
    if (S.top == S.base) return ERROR;    //空栈返回错误
    SElemType e = *(S.top - 1);
    return e;
}


//判断是否为左括号
bool IsLBracket(char c) {
    if (c == '{' || c == '[' || c == '(') return true;
    else return false;
}

//括号匹配函数
bool matchBracket(char c1, char c2) {
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '{' && c2 == '}') return true;
    if (c1 == '(' && c2 == ')') return true;
    return false;
}


//int main() {
//    //创建并初始化一个栈
//    string str;
//    SqStack S;
//    InitStack(S);
//    int flag = 1;
//    cin >> str;
//    for (auto c : str) {
//        //什么情况要入栈呢？当检测到时左括号的时候要入栈,为了防止太乱，所以另外写一个匹配函数会比较好
//        if (IsLBracket(c)) { Push(S, c); }              //当检测到时左括号的时候要入栈
//        else {
//            if (matchBracket(GetElem(S), c)) { Pop(S); }    //如果是右括号的话就进行比较，如果匹配的话，就把栈顶弹出
//            else { flag = 0;break; }
//        }
//    }
//    if (S.top == S.base && flag) cout << 1 << endl;//这表示当栈空以及中间都匹配的情况下是有效的
//    else cout << 0 << endl;
//    return 0;
//}










