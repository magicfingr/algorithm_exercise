class Solution {
public:
    /**
     * dfs, 参考Permutations 与 Subsets II
     * 去重：规定不能往回走重复的点
     */
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > re;
        bool *used = new bool[num.size()];
        memset(used, false, sizeof(bool) * num.size());
        vector<int> perm;

        sort(num.begin(), num.end());
        dfs(num, used, perm, re);

        return re;
    }
private:
    void dfs(const vector<int> &num, bool *used, vector<int> &perm, vector<vector<int> > &re){
        if (perm.size() == num.size()){
            re.push_back(perm);
            return;
        }
        for (int i = 0; i < num.size(); i++){
            if (!used[i]){
                // 检测到重复点，且可能往回走，则可直接避免生成此次排列
                // 1,1,1,2
                if(i - 1 >= 0 && num[i - 1] == num[i] && !used[i - 1])
                    continue;
                
                used[i] = true;
                perm.push_back(num[i]);
                dfs(num, used, perm, re);
                perm.pop_back();
                used[i] = false;
            }
        }
    }
    /*
    // 旧的去重方法：
    void dfs(const vector<int> &num, bool *used, vector<int> &perm, vector<vector<int> > &re){
        if (perm.size() == num.size()){
            re.push_back(perm);
            return;
        }
        for (int i = 0; i < num.size(); i++){
            if (!used[i]){
                // 去重
                int j = i;
                vector<int> edited;
                while (j >= 0 && num[j] == num[i]){
                    if (!used[j]){
                        used[j] = true;
                        edited.push_back(j);
                    }
                    j--;
                }

                perm.push_back(num[i]);
                dfs(num, used, perm, re);
                perm.pop_back();

                for (int j = 0; j < edited.size(); j++)
                    used[edited[j]] = false;
            }
        }
    }
    */
};