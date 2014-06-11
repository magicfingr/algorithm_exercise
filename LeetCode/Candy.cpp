/*
测试：
1,1,1 - 3
2,2,1 - 4
1,2,4,4,3 - 9
4,2,3,4,1 - 9
*/
class Solution {
public:
    /**
     * 只有遇到ratings增大时才需增加candy，不管是比左边邻居大或是比右边邻居大。O(N), O(N)
     * 从左往右扫，再从右往左扫
    */
    int candy(vector<int> &ratings) {
        if(ratings.size() <= 0)
            return 0;
        
        int *candy = new int[ratings.size()];
        candy[0] = 1;
        //从左往右
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1])
                candy[i] = candy[i - 1] + 1;
            else
                candy[i] = 1;
        }
        //从右往左，同时求和
        int sum = candy[ratings.size() - 1];
        for(int i = ratings.size() - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
                candy[i] = candy[i + 1] + 1;
            sum += candy[i];
        }
        return sum;
    }
};