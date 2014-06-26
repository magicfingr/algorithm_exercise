class Solution {
public:
    /**
    * 必然存在一个切割，使得s1与s2分成两段，且这两部分也都是scramble。
    * 穷举，剪枝可过。
    */
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        if (s1.size() <= 0)
            return false;
        //排序剪枝
        string s1Sorted = s1;
        string s2Sorted = s2;
        sort(s1Sorted.begin(), s1Sorted.end());
        sort(s2Sorted.begin(), s2Sorted.end());
        if(s1Sorted != s2Sorted)
            return false;
        //递归尝试所有切割方法
        //s1: [0, split - 1], [split, len - 1]
        //s2: [0, split - 1], [split, len - 1]  or  [0, len - split - 1], [len - split, len - 1]
        int len = s1.size();
        for(int split = 1; split <= len - 1; split++){
            string s1Left = s1.substr(0, split);
            string s1Right = s1.substr(split);
            string s2Left = s2.substr(0, split);
            string s2Right = s2.substr(split);
            string s2RevLeft = s2.substr(len - split);
            string s2RevRight = s2.substr(0, len - split);
            
            //bool seq = isScramble(s1Left, s2Left) && isScramble(s2Right, s2Right);
            //bool rev = isScramble(s1Left, s2RevLeft) && isScramble(s1Right, s2RevRight);
            if( (isScramble(s1Left, s2Left) && isScramble(s1Right, s2Right)) ||
                (isScramble(s1Left, s2RevLeft) && isScramble(s1Right, s2RevRight)) )
                return true;
        }
        
        return false;
    }
};