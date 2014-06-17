class Solution {
public:
    /**
     * BFS，一层层变换，把每次可能的变化结果存下来，到达end则结束
     * 直接搜会TLE
     * 优化：
     * dict中访问过的串就不需再继续列举
     * 列举所有可能的改变结果，然后查hash表，而不是直接遍历词典（在字符串长度远小于字典长度时更为有效） - vital
     */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end)
            return 1;
        vector<string> curResult;
        int ladderLen = 1;
        unordered_set<string> visitedStr;  //已列举过的串
        //计算每次所有可能的变换结果
        curResult.push_back(start);
        while(curResult.size() > 0){
            //更新变换长度
            ladderLen++;
            //遍历当前所有的字符curResult，计算新变换结果
            vector<string> newTransResult;
            for(vector<string>::const_iterator strIt = curResult.begin(); strIt != curResult.end(); strIt++){
                //已列举过则跳过
                if(visitedStr.find(*strIt) != visitedStr.end())
                    continue;
                //保存串的所有变换结果
                //逐个改变
                for(int i = 0; i < strIt->size(); i++){
                    string newStr = *strIt;
                    for(char c = 'a'; c <= 'z'; c++){
                        newStr[i] = c;
                        if(newStr == end)
                            return ladderLen;
                        //保存新的变换结果：字典中存在且未列举过
                        if(dict.find(newStr) != dict.end() && visitedStr.find(newStr) == visitedStr.end())
                            newTransResult.push_back(newStr);
                    }
                }
                //记录已列举
                visitedStr.insert(*strIt);
            }
            //更新当前结果至curResult
            curResult.swap(newTransResult);
        }
        return 0;
    }
};