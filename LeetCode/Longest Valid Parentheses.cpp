class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int lastRight = -1;  //store last index of ')', initially -1
        stack<int> leftStack;   //store all unmatched index of '('
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                leftStack.push(i);
            } else{
                if(leftStack.empty()){
                    lastRight = i;
                } else{
                    leftStack.pop();
                    if(leftStack.empty())
                        maxLen = max(maxLen, i - lastRight);
                    else
                        maxLen = max(maxLen, i - leftStack.top());
                }
            }
        }
        return maxLen;
    }
};