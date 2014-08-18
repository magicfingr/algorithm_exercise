class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > re;
        if(num.size() == 0)
            return re;

        sort(num.begin(), num.end());            
        vector<int> comb;
        dfs(target, 0, num, comb, re);
        return re;
    }
private:
    void dfs(const int remain, const int offset, vector<int> &num, vector<int> &comb, vector<vector<int> > &re){
        if(remain < 0)
            return;
        if(remain == 0){
            re.push_back(comb);
            return;
        }
        int i = offset;
        while(i < num.size()){
            comb.push_back(num[i]);
            dfs(remain - num[i], i + 1, num, comb, re);
            comb.pop_back();
            // skip the same start position
            int j = i;
            while(j < num.size() && num[j] == num[i])
                j++;
            i = j;
        }
    }
};