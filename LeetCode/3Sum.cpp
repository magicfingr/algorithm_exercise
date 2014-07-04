class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > re;
        if(num.size() <= 2)
            return re;
        
        sort(num.begin(), num.end());
        //也可不判断size，但在循环判断时一定要注意转成int型判断（默认是都转为unsigned int）
        //for(int i = 0; i < (int) (num.size() - 2); i++){
        for(int i = 0; i < num.size() - 2; i++){
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k){
                if(num[j] + num[k] < -num[i]){
                    j++;
                } else if(num[j] + num[k] > -num[i]){
                    k--;
                } else{
                    addToResult(num[i], num[j], num[k], re);
                    int b = num[j];
                    int c = num[k];
                    while(k > j && num[k] == c)
                        k--;
                    while(j < k && num[j] == b)
                        j++;
                }
            }
            while((i < num.size() - 2) && num[i] == num[i + 1])
                i++;
        }
        return re;
    }
private:
    void addToResult(const int a, const int b, const int c, vector<vector<int> > &re){
        assert(a <= b && b <= c);
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        re.push_back(v);
    }
};