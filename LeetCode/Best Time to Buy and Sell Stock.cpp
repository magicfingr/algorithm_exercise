class Solution {
public:
    //DP，从前往后遍历，新加入一个点后，maxprofit(i+1) = max{maxprofit(i), max{0, price[i+1] - min[0...i]} }
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 0)
            return 0;
        
        int maxProfit = 0;
        int min = prices[0];
        for(int i = 1; i < prices.size(); i++){
            int newProfit = max(0, prices[i] - min);
            maxProfit = max(maxProfit, newProfit);
            if(min > prices[i])
                min = prices[i];
        }
        return maxProfit;
    }
};