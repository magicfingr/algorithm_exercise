class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(p[0] == '\0'){
            return s[0] == '\0';
        } else if(p[0] != '*'){
            if(p[0] == s[0] || p[0] == '?')
                return isMatch(s + 1, p + 1);
            else
                return false;
        } else{
            // skip duplicate '*'
            int index = 0;
            while(p[index] != '\0' && p[index] == '*')
                index++;
                
            if(isMatch(s, p + index))
                return true;
            for(int i = 0; s[i] != '\0'; i++){
                if(isMatch(s + i + 1, p + index))
                    return true;
            }
            return false;
        }
    }
};