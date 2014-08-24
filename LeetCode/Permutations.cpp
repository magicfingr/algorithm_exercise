class Solution {
public:
    // dfs
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > re;
        bool *used = new bool[num.size()];
        memset(used, false, sizeof(bool) * num.size());
        vector<int> perm;
        
        dfs(num, used, perm, re);
        
        return re;
    }
private:
    void dfs(const vector<int> &num, bool *used, vector<int> &perm, vector<vector<int> > &re){
        if(perm.size() == num.size()){
            re.push_back(perm);
            return;
        }
        for(int i = 0; i < num.size(); i++){
            if(!used[i]){
                used[i] = true;
                perm.push_back(num[i]);
                dfs(num, used, perm, re);
                perm.pop_back();
                used[i] = false;
            }
        }
    }
};