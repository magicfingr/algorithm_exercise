class Solution {
public:
    /**
     * 类似快排的partition方法
     */
    int removeElement(int A[], int n, int elem) {
        int low = 0;
        int high = n - 1;
        while(low < high){
            if(A[low] != elem){
                low ++;
            } else{
                while(low < high && A[high] == elem)
                    high--;
                if(low < high){
                    A[low] = A[high];
                    low++;
                    high--;
                }
            }
        }
        if(low <= high && A[low] != elem)
            return low + 1;
        else
            return low;
    }
};