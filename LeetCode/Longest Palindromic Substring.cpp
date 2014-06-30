class Solution {
public:
    /**
    * 从每一个点出发，往外扩展判断，记录最长回文串
    * O(N^2), O(1)
    */
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;

        int maxStart = 0;
        int maxEnd = 0;

        for (int i = 1; i < s.size(); i++){
            //odd
            //[0, i], [i, s.size() - 1]
            int width = expandAndCal(s, i, i);
            if (width * 2 - 1 > maxEnd + 1 - maxStart){
                //注意左右两边的长度都是width
                maxStart = i - width + 1;
                maxEnd = i + width - 1;
            }
            //even
            //[0, i - 1], [i, s.size() - 1]
            width = expandAndCal(s, i - 1, i);
            if (width * 2 > maxEnd + 1 - maxStart){
                maxStart = i - width;
                maxEnd = i + width - 1;
            }
        }
        return s.substr(maxStart, maxEnd + 1 - maxStart);
    }
private:
    //从中心往两边扩展判断，返回最长的扩展长度
    int expandAndCal(const string &s, int leftStart, int rightStart){
        int start = leftStart;
        int end = rightStart;
        while (start >= 0 && end < s.size() && s[start] == s[end]){
            start--;
            end++;
        }
        return leftStart - start;
    }
};