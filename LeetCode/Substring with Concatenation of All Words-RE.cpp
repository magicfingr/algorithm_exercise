class Solution {
public:
    /**
    * 缓存中间结果：对S中的每个位置的字符串，计算其能否match到L中的某串，并记录
    * 然后在中间结果中找连续match所有L中串的位置
    * O(nm), O(m)
    */
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> re;
        if (L.size() == 0)
            return re;

        int strLen = L[0].size();
        if (S.size() < (strLen * L.size()))
            return re;

        //init cache
        int *matches = new int[S.size()];
        for (int i = 0; i < S.size(); i++){
            matches[i] = -1;
            if (S.size() - i >= strLen){
                string curStr = S.substr(i, strLen);
                for (int j = 0; j < L.size(); j++){
                    if (curStr == L[j]){
                        matches[i] = j;
                        break;
                    }
                }
            }
        }
        //find result
        bool *used = new bool[L.size()];
        for (int i = 0; i < S.size(); i++){
            //memset(used, false, sizeof(bool) * L.size());
            for(int j = 0; j < L.size(); j++)
                used[j] = false;
            if (matches[i] >= 0){
                used[matches[i]] = true;
                bool isSubstr = true;
                for (int j = 1; j < L.size(); j++){
                    int nextMatchIndex = i + j * strLen;
                    if (matches[nextMatchIndex] >= 0 && !used[matches[nextMatchIndex]]){
                        used[matches[nextMatchIndex]] = true;
                    } else{
                        isSubstr = false;
                        break;
                    }
                }
                if (isSubstr)
                    re.push_back(i);
            }
        }
        return re;
    }
};