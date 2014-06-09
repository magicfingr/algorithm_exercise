class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        //DP，从后往前一个个加字母判断
        //用isSeg[i]保存s.substring[i, len-1]能不能被seg
        bool *isSeg = new bool[s.size() + 1];
        memset(isSeg, false, sizeof(bool) * s.size());
        isSeg[s.size()] = true;     //空串能被seg
        //从后往前循环string
        for(int i = s.size() - 1; i >= 0; i--){
            //每加一个字符，判断新串能否被seg
            for(int j = i; j < s.size(); j++){
                //判断dict中是否存在部分string且剩余部分能被seg
                if(dict.end() != dict.find(s.substr(i, j + 1 - i)) && isSeg[j + 1]){
                    //保存判断结果
                    isSeg[i] = true;
                    break;
                }
            }
        }
        return isSeg[0];
    }
};