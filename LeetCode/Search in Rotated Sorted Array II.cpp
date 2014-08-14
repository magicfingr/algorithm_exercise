class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0;
        int high = n -1;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(A[mid] == target){
                return true;
            } else if(A[low] < A[mid]){ //left half is sorted
                if(A[low] <= target && target <= A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else if(A[low] > A[mid]){ //right half is sorted
                if(A[mid] <= target && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else{
                //in this situation, like "13111", we cannot decide whether to go left or right
                //and have to move low one step right and loop again
                low++;
            }
        }
        return false;
    }
};