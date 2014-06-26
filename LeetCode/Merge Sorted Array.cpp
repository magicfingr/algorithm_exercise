class Solution {
public:
    /**
     * 归并，升序。O(N*M),O(M)
     */
    void merge(int A[], int m, int B[], int n) {
        int *C = new int[m];
        for(int i = 0; i < m; i++)
            C[i] = A[i];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m && j < n){
            if(C[i] <= B[j]){
                A[k++] = C[i++];
            } else{
                A[k++] = B[j++];
            }
        }
        while(i < m)
            A[k++] = C[i++];
        while(j < n)
            A[k++] = B[j++];
        delete[] C;
    }
};