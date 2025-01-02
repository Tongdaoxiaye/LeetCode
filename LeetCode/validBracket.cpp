////20. ÓÐÐ§µÄÀ¨ºÅ
//#include <stack>
//class Solution {
//public:
//    bool isValid(string s) {
//        stack<char> str;
//        if (s.size() == 1) return false;
//        for (char c : s) {
//            if ((c == '(') || (c == '[') || (c == '{')) str.push(c);
//            else {
//                if (str.empty()) return false;
//                if ((c == ')') && (str.top() == '(')) str.pop();
//                else if ((c == ']') && (str.top() == '[')) str.pop();
//                else if ((c == '}') && (str.top() == '{')) str.pop();
//                else str.push(c);
//            }
//        }
//        return str.empty();
//    }
//};