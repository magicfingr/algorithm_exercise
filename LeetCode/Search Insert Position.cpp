class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(A[mid] < target){
                low = mid + 1;
            } else if(A[mid] > target){
                high = mid - 1;
            } else{
                return mid;
            }
        }
        return low;
    }
};