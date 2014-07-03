/*
Test:
"ab", ".*c"
"abcabcabc", ".*c"
"a", "ab*"
"bbbba", ".*a*a"
"a", ".*..a*"
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(p[0] == '\0')
            return s[0] == '\0';
        if(p[1] != '*'){
            if(s[0] != '\0' && (s[0] == p[0] || p[0] == '.'))
                return isMatch(s + 1, p + 1);
            else
                return false;
        } else{
            //列举所有匹配长度
            //match 0
            if(isMatch(s, p + 2))
                return true;
            //match 1 ~ x
            int i = 0;
            while(s[i] != '\0' && (s[i] == p[0] || p[0] == '.')){
                if(isMatch(s + i + 1, p + 2))
                    return true;
                i++;
            }
        }
        return false;
    }
};