class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1 || s.size() <= nRows)
            return s;
        string newStr;
        int offset = nRows + nRows - 2;
        //按层遍历ziggag s，计算具体位置的字符并赋给新串
        for (int level = 0; level < nRows; level++){
            int len = s.size();     //将size()转成带符号数
            for (int shift = 0; shift - level < len; shift += offset){
                if (level != 0 && level != nRows - 1 && shift > 0){
                    newStr += s[shift - level];
                }
                if (shift + level < s.size())
                    newStr += s[shift + level];
            }
        }
        assert(newStr.size() == s.size());
        return newStr;
    }
};