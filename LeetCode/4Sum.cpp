class Solution {
public:
    /**
     * 类似3Sum，O(N^3)
     * 注意去重
     */
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > re;
        sort(num.begin(), num.end());
        for(int i = 0; i < (int) (num.size() - 3); i++){
            for(int j = i + 1; j < (int) (num.size() - 2); j++){
                int p = j + 1;
                int q = num.size() - 1;
                while(p < q){
                    if(num[p] + num[q] < target - num[i] - num[j]){
                        p++;
                    } else if(num[p] + num[q] > target - num[i] - num[j]){
                        q--;
                    } else{
                        addToResult(num[i], num[j], num[p], num[q], re);
                        int c = num[p];
                        int d = num[q];
                        while(p < q && num[p] == c)
                            p++;
                        while(p < q && num[q] == d)
                            q--;
                    }
                }
                while((j < num.size() - 2) && num[j] == num[j + 1])
                    j++;
            }
            while((i < num.size() - 3) && num[i] == num[i + 1])
                i++;
        }
        return re;
    }
private:
    void addToResult(const int a, const int b, const int c, const int d, vector<vector<int> > &re){
        assert(a <= b && b <= c && c <= d);
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        re.push_back(v);
    }
};