class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            maxSum = max(maxSum, sum);
            if(sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};