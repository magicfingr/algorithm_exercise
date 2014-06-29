class Solution {
public:
    /**
     * 题目理解错
     * 要找的是一段最长的子串，这段子串中不存在重复的字符
     * 用一个bool数组(ASC II码，最大为256)作集合存当前区间中存在的字符，从前往后扫，
     *     若新的字符不在集合中，则继续扫
     *     否则暂定，从前端收缩，从集合中删除遇到的字符，直至碰到与当前字符相同的字符
     * 记录过程中集合存在的最大元素个数
     * O(N),O(1)
     */
    int lengthOfLongestSubstring(string s) {
        const int CHAR_NUM = 256;
        bool ch[CHAR_NUM];
        memset(ch, false, sizeof(bool) * CHAR_NUM);
        
        int maxCount = 0;
        int start = 0;  //当前不重复串的起始点
        int pos = 0;
        while(pos < s.size()){
            if(!ch[s[pos]]){  //新字符
                ch[s[pos]] = true;
                pos++;
            } else{     //重复
                if(maxCount < pos - start)
                    maxCount = pos - start;
                while(s[start] != s[pos]){     //删除直至重复的字符
                    assert(start < pos);
                    ch[s[start]] = false;
                    start++;
                }
                assert(s[start] == s[pos]);
                assert(ch[s[pos]] == true);
                start++;
                pos++;
            }
        }
        //最后一段
        if(maxCount < pos - start)
            maxCount = pos - start;
        return maxCount;
    }
};