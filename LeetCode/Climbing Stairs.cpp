class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        int *step = new int[n + 1];
        step[n] = 0;
        step[n - 1] = 1;
        step[n - 2] = 2;
        for(int i = n - 3; i >= 0; i--)
            step[i] = step[i + 1] + step[i + 2];
        return step[0];
    }
};