/*
假设无非法输入，不考虑溢出，不可修改vector数组，正数没有'+'号
错误：
string转int没考虑负号。。。
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++){
            if(*it == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);
            } else if(*it == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);
            } else if(*it == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);
            } else if(*it == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);
            } else{
                s.push(stringToInt(*it));
            }
        }
        return s.top();
    }
private:
    int stringToInt(const string &s){
        int re = 0;
        int sig = 1;
        string::const_iterator it = s.begin();
        if(*it == '-'){
            sig = -1;
            it++;
        } else if(*it == '+'){
            it++;
        }
        for(; it != s.end(); it++){
            re = re * 10 + *it - '0';
        }
        return re * sig;
    }
};