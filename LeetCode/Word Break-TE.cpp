/*
BF会超时
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        //循环词典
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++){
            //若全词匹配，返回true
            if(s == *it){
                return true;
            } else{
                //若前端匹配
                if(0 == s.find(*it, 0)){
                    //对s的剩余部分递归调用
                    int isFound = wordBreak(s.substr((*it).size()), dict);
                    //若递归调用返回true，则可直接返回
                    if(isFound)
                        return true;
                }
            }
        }
        //循环结束未找到，返回false
        return false;
    }
};