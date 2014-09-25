/*
.1 - true
3. - true
e9 - false
46.e3 - true
*/
class Solution {
public:
    bool isNumber(const char *s) {
        while(*s == ' ')
            s++;
        if(*s == '-' || *s == '+')
            s++;
        int len = strlen(s);
        while(s[len - 1] == ' ')
            len--;
        if(len <= 0)
            return false;
        
        int i = 0;
        bool isFact = false;
        bool isScience = false;
        while(i < len){
            if('0' <= s[i] && s[i] <= '9'){
                i++;
            } else if(s[i] == '.'){
                if(isFact || isScience)
                    return false;
                isFact = true;
                if(!hasDigit(s, i - 1, len) && !hasDigit(s, i + 1, len))
                    return false;
                i++;
            } else if(s[i] == 'e' || s[i] == 'E'){
                if(isScience)
                    return false;
                isScience = true;
                if(i - 1 < 0 || i + 1 >= len)
                    return false;
                i++;
                if(s[i] == '-' || s[i] == '+')
                    i++;
                if(i >= len)
                    return false;
            } else{
                return false;
            }
        }
        return true;
    }
private:
    bool hasDigit(const char*s, int i, int len){
        if(i < 0 || i >= len)
            return false;
        return '0' <= s[i] && s[i] <= '9';
    }
};