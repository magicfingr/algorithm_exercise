class Solution {
public:
    //从前往后遍历，累加大于0的profit，取累加达到的最大值
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 0)
            return 0;
        
        int maxProfit = 0;
        int curProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - prices[i - 1];
            //只要保持盈利就可继续累加
            if(curProfit + profit >= 0){
                curProfit += profit;
            } else{
                curProfit = 0;
            }
            //保存出现的最大值
            maxProfit = max(maxProfit, curProfit);
        }
        maxProfit = max(maxProfit, curProfit);
        return maxProfit;
    }
};