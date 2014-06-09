class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        //DP，类似Word Break
        //用二维vector:segResult存中间结果，segResult[i]存s[i,n-1]的所有可能分词结果（完整的）
        vector<string> *segResult = new vector<string>[s.size()];
        //从后往前，一个个字符加入并判断
        for(int pos = s.size() - 1; pos >= 0; pos--){
            //计算并保存新串的所有seg结果
            for(int j = pos; j < s.size(); j++){
                //判断新组成的子串能不能被seg
                string newStr = s.substr(pos, j + 1 - pos);
                if(dict.end() != dict.find(newStr)){    //yes
                    //若还有剩余串: 判断剩余串能不能被seg
                    if(j < s.size() - 1){
                        //能则保存所有组合结果
                        if(segResult[j + 1].size() >= 0){
                            string newSeg = newStr + " ";
                            for(vector<string>::iterator it = segResult[j + 1].begin();
                                it != segResult[j + 1].end(); it++){
                                //ps: C++容器是值传递
                                segResult[pos].push_back(newSeg + *it);
                            }
                        //不能则继续找
                        } else{
                            continue;
                        }
                    //无剩余串(j == len - 1)则可直接保存结果
                    } else{
                        segResult[pos].push_back(newStr);
                    }
                }
            }
        }
        return segResult[0];
    }
};