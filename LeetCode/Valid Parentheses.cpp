class Solution {
public:
    bool isValid(string s) {
        stack<char> perStack;
        for(size_t i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                perStack.push(s[i]);
            } else{
                if(perStack.empty())
                    return false;
                char c = perStack.top();
                if((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}'))
                    perStack.pop();
                else
                    return false;
            }
        }
        return perStack.empty();
    }
};