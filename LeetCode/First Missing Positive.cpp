/*
Test:
[3,4,-1,1]
[1,1]
*/
class Solution {
public:
    // 类似桶排序
    // 先把每个数放到数组中对应序号的位置，然后遍历，不在的数即为缺少的
    int firstMissingPositive(int A[], int n) {
        for(int i = 0; i < n; i++){
            if(A[i] != i + 1){
                while((A[i] != i + 1) && 1 <= A[i] && A[i] <= n && (A[i] != A[A[i] - 1]))
                    swap(A[i], A[A[i] - 1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(A[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
private:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
};