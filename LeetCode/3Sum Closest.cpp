class Solution {
public:
    /**
     * 类似3Sum
     */
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size() <= 2)
            return 0;
        sort(num.begin(), num.end());
        
        int closestSum = num[0] + num[1] + num[2];
        for(int i = 0; i < num.size() - 2; i++){
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k){
                if(num[j] + num[k] < target - num[i]){
                    if(abs(closestSum - target) > abs(num[j] + num[k] + num[i] - target))
                        closestSum = num[j] + num[k] + num[i];
                    j++;
                } else{
                    if(abs(closestSum - target) > abs(num[j] + num[k] + num[i] - target))
                        closestSum = num[j] + num[k] + num[i];
                    k--;
                }
            }
        }
        return closestSum;
    }
};