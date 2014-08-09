class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> re;
        re.push_back(-1);
        re.push_back(-1);
        
        int left = firstIndexOf(A, n, target);
        if(left == -1)
            return re;
        int right = left;
        while(right < n && A[right] == target)
            right++;
        re[0] = left;
        re[1] = right - 1;
        
        return re;
    }
private:
    int firstIndexOf(int A[], int n, int key){
        if(n == 0)
            return -1;
        int low = 0;
        int high = n - 1;
        while(low < high){
            int mid = low + ((high - low) >> 1);
            if(A[mid] < key){
                low = mid + 1;
            } else{
                high = mid;
            }
        }
        return A[high] == key ? high : -1;
    }
};