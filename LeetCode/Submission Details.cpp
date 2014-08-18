class Solution {
public:
    // dfs, 与找图中两点之间的路径问题相似
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > re;
        if(candidates.size() == 0)
            return re;
        
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        dfs(target, 0, candidates, comb, re);
        return re;
    }
private:
    void dfs(const int remain, const int offset, vector<int> &candidates, vector<int> &comb, vector<vector<int> > &re){
        if(remain < 0)
            return;
        if(remain == 0){
            re.push_back(comb);
            return;
        }
        for(int i = offset; i < candidates.size(); i++){
            comb.push_back(candidates[i]);
            dfs(remain - candidates[i], i, candidates, comb, re);
            comb.pop_back();
        }
    }
};