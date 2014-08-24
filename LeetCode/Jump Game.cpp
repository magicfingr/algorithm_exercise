class Solution {
public:
    // dp超时，可直接贪心
    bool canJump(int A[], int n) {
        int furthest = 0;
        for(int i = 0; i < n; i++){
            if(furthest >= i && furthest < A[i] + i)
                furthest = A[i] + i;
            if(furthest >= n - 1)
                return true;
        }
        return false;
    }
};