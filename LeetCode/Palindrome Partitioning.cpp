class Solution {
public:
    /**
     * DP，从后往前算（自底向上），用二维vector指针数组: pars[i]存str.substring[i, n-1]的所有partition
     */
    vector<vector<string> > partition(string s) {
        vector<vector<string> > *pars = new vector<vector<string> >[s.size()];
        //从后往前访问字符串
        for(int i = s.size() - 1; i >= 0; i--){
            //加入新字符后，循环判断可否与剩余字符组成新的回文串
            for(int end = i; end < s.size(); end++){
                string newStr = s.substr(i, end + 1 - i);
                //组成的新串不是回文串则继续尝试
                if(!isPalindrome(newStr)){
                    continue;
                }
                //若组成新回文串以后没有剩余字符，则直接保存
                if(end >= s.size() - 1){
                    vector<string> newPar;
                    newPar.push_back(newStr);
                    pars[i].push_back(newPar);
                }
                //有剩余字符，若剩余字符有可行partition，则保存所有新partition组合
                //assert: (end + 1) < s.size()
                else if(pars[end + 1].size() > 0){
                    vector<vector<string> > remainPars = pars[end + 1];
                    //生成新的partition组合
                    perm(newStr, remainPars, pars[i]);
                }
            }
        }//for
        return pars[0];
    }//partition
    
    //组合新字串与所有旧的partition，生成新的partition组合
    void perm(const string str, const vector<vector<string> > oldPars, vector<vector<string> > &newPars){
        for(vector<vector<string> >::const_iterator it = oldPars.begin(); it != oldPars.end(); it++){
            vector<string> partition;
            partition.push_back(str);
            for(vector<string>::const_iterator strIt = it->begin(); strIt != it->end(); strIt++){
                partition.push_back(*strIt);
            }
            
            newPars.push_back(partition);
        }
    }
    
    //判断s是否是回文
    bool isPalindrome(string s){
        int head = 0;
        int tail = s.size() - 1;
        while(head < tail){
            if(s[head] != s[tail])
                break;
            head++;
            tail--;
        }
        return head >= tail;
    }
};
