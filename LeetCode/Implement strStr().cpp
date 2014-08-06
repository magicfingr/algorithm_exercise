class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!haystack || !needle)
            return NULL;
        if(!*needle)
            return haystack;
        
        int lenHay = strlen(haystack);
        int lenNeedle = strlen(needle);
        
        int loopTime = lenHay - lenNeedle + 1;
        for(int i = 0; i < loopTime; i++){
            if(*(haystack + i) == *needle){
                char *p = haystack + i;
                char *q = needle;
                while(*p && *q && *p == *q){
                    p++;
                    q++;
                }
                if(!*q)
                    return haystack + i;
            }
        }
        return NULL;
    }
};