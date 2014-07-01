class Solution {
public:
    /**
     * 错误：未考虑负数溢出的情况
     * 错误：题目根本不把负数当成palindrome的。。。
     */
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        /*
        //负数最大值会溢出，且不是palindrome
        if(x == INT_MIN)
            return false;
        //不考虑符号
        x = abs(x);
        */
        //先算整数的长度
        int val = x;
        int len = 0;
        while(val > 0){
            val /= 10;
            len++;
        }
        //然后从两边往中间循环比较
        int weight = pow(10, len - 1);
        while(len >= 2){
            if(x / weight != x % 10)
                break;
            x = (x % weight) / 10;
            len -= 2;
            weight /= 100;
        }
        if(len <= 1)
            return true;
        else
            return false;
    }
};