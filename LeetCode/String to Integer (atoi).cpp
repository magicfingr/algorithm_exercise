/*
test:
123
12300
001
-12300
-001
+12300
-0012a42 （有效！返回-12。。。）
*/
class Solution {
public:
    /**
     * str只要正常结尾就可以了。。。
     * 错误：忘了吞掉前面的空白
     * 错误：判断正、负溢出
     */
    int atoi(const char *str) {
        const int error = 0;
        int sign = 1;
        //吃掉前面的空白
        int pos = 0;
        while(str[pos] && str[pos] == ' ')
            pos++;
        //吃掉前面的+、-号，之后不允许出现数字以外的字符
        if(str[pos] == '-'){
            sign = -1;
            pos++;
        } else if(str[pos] == '+'){
            pos++;
        } else{}
        //吃掉多余的0
        while(str[pos] == '0')
            pos++;
        //之后如果接的不是有效数字，则输入错误
        if(!str[pos] || !isDigit(str[pos]))
            return error;
        //计算数值大小
        unsigned int val = 0;
        while(str[pos] && isDigit(str[pos])){
            int digit = str[pos] - '0';
            if(val > ((INT_MAX - digit) / 10)){
                val = INT_MAX + 1;
                break;
            }
            val = val * 10 + digit;
            pos++;
        }
        //忽略之后的无效字符，结束转换
        //注意负溢出的绝对值比正溢出的绝对值大1，要分开处理
        if(val > INT_MAX){
            if(sign == -1)
                return INT_MIN;
            else
                return INT_MAX;
        } else
            return sign * val;
    }
private:
    bool isDigit(char c){
        return '0' <= c && c <= '9';
    }
};