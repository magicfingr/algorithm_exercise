class Solution {
public:
    //把整个数组分成不相交的两段，分别计算两段上的最大收益
    //先从前往后扫，算第一段所有可能的情况；再从后往前扫，算第二段可能的情况，同时取最大和
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 0)
            return 0;
        
        int *firstMax = new int[prices.size()];
        memset(firstMax, 0, sizeof(int) * prices.size());
        int curProfit = 0;
        //从前往后
        int i = 1;
        for(; i < prices.size(); i++){
            int profit = prices[i] - prices[i - 1];
            if(curProfit + profit >= 0)
                curProfit += profit;
            else
                curProfit = 0;
            firstMax[i] = max(firstMax[i - 1], curProfit);
        }
        
        //从后往前，分成[0, i-1], [i, n-1]两段
        int maxProfit = firstMax[prices.size() - 1];  //保存最大和即可，不需存下第二段的所有结果，初始只买卖一次
        curProfit = 0;
        for(int i = prices.size() - 2; i >= 1; i--){
            int profit = prices[i + 1] - prices[i];
            if(curProfit + profit >= 0)
                curProfit += profit;
            else
                curProfit = 0;
            maxProfit = max(maxProfit, firstMax[i - 1] + curProfit);
        }
        return maxProfit;
    }
};