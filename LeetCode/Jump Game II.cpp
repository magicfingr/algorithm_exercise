class Solution {
public:
    // dp超时，贪心
    int jump(int A[], int n) {
        if(n <= 0)
            return -1;
        int step = 0;
        int cur = 0;
        int next = A[0];
        while(cur < n - 1 && cur < next){
            int max = cur + 1;
            for(int i = cur + 1; i <= next; i++){
                if(max + A[max] < i + A[i])
                    max = i;
            }
            cur = next;
            next = max + A[max];
            step++;
        }
        if(cur < n - 1)
            return -1;
        else
            return step;
    }
};