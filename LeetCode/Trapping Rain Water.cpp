class Solution {
public:
    // 对每个点，保存它左边的最大值与右边的最大值，则此点容量为min(maxs) - cur
    int trap(int A[], int n) {
        int *leftMax = new int[n];
        int *rightMax = new int[n];
        int max = -1;
        for(int i = 0; i < n; i++){
            if(max < A[i])
                max = A[i];
            leftMax[i] = max;
        }
        max = -1;
        for(int i = n - 1; i >= 0; i--){
            if(max < A[i])
                max = A[i];
            rightMax[i] = max;
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            int bound = min(leftMax[i], rightMax[i]);
            if(bound > A[i])
                sum += bound - A[i];
        }
        return sum;
    }
};