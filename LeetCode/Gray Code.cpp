class Solution {
public:
    /**
     * 注意到，当n = 3时，Gray Code：0,1,3,2,[...]
     * 第一段是与n = 2时完全相同的；而第二段，如果反向接上第一段，在加上最高位，那么刚好就每次只改变了1位，
     * 即：0,1,3,2, 4 + [2,3,1,0] => 0,1,3,2,6,7,5,4
     * 往下类推即可，O(2^N), O(2^N)
     */
    vector<int> grayCode(int n) {
        //循环生成1 ~ n的Gray Code
        vector<int> re;
        re.push_back(0);
        int weight = 1;
        for(int i = 1; i <= n; i++){
            int curSize = re.size();
            for(int j = curSize - 1; j >= 0; j--){
                re.push_back(re[j] + weight);
            }
            weight *= 2;
        }
        return re;
    }
};