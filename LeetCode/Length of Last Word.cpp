class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int index = len - 1;
        while(index >= 0 && s[index] == ' ')
            index--;
        int wordLen = 0;
        while(index >= 0 && s[index] != ' '){
            index--;
            wordLen++;
        }
        return wordLen;
    }
};