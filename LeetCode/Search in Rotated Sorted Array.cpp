/*
Testc case:
[2,3,4,5,1], 2,5,1
[5,1,2,3,4], 5,1,3
 */
class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + ((high - low >> 1));
            if(A[mid] == target){
                return mid;
            } else if(A[low] <= A[mid]){
                if(A[low] <= target && target <= A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else{
                if(A[mid] <= target && target <= A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};