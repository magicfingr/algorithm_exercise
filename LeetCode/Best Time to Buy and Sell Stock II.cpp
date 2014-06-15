class Solution {
public:
    //从前往后扫，累加大于0的profit
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 0)
            return 0;
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - prices[i - 1];
            maxProfit += max(0, profit);
        }
        return maxProfit;
    }
};