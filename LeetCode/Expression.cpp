#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 定义操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 计算操作符 op 的两个操作数 left 和 right 的结果
int applyOperator(int left, int right, char op) {
    switch (op) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
    default: return 0;
    }
}

int evaluateExpression(const string& expression) {
    stack<int> values;
    stack<char> ops;

    for (char c : expression) {
        if (c == ' ') // 忽略空格
            continue;

        if (isdigit(c)) { // 如果是数字字符
            values.push(c - '0');
        }
        else if (c == '(') { // 如果是左括号
            ops.push(c);
        }
        else if (c == ')') { // 如果是右括号
            while (!ops.empty() && ops.top() != '(') {
                int right = values.top();
                values.pop();
                int left = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOperator(left, right, op));
            }
            ops.pop(); // 弹出左括号
        }
        else { // 如果是操作符
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                int right = values.top();
                values.pop();
                int left = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOperator(left, right, op));
            }
            ops.push(c);
        }
    }

    // 处理剩余的操作符和操作数
    while (!ops.empty()) {
        int right = values.top();
        values.pop();
        int left = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOperator(left, right, op));
    }

    return values.top(); // 返回最终结果
}

//int main() {
//    string input;
//    getline(cin, input, '#'); // 读取输入直到遇到 #
//
//    int result = evaluateExpression(input);
//    cout << "Result: " << result << endl;
//
//    return 0;
//}
