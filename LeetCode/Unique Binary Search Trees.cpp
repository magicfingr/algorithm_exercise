class Solution {
public:
    /**
     * 可以以1 ~ n中任意点为根，DP。O(N^2),O(N)
     */
    int numTrees(int n) {
        int *numTree = new int[n + 1];
        memset(numTree, 0, sizeof(int) * (n + 1));
        numTree[0] = 1;
        
        for(int i = 1; i <= n; i++){
            //以j为root，计算树的个数
            //tree: [0, j - 1], j, [j + 1, i]
            for(int j = 1; j <= i; j++){
                numTree[i] += numTree[j - 1] * numTree[i - j];
            }
        }
        return numTree[n];
    }
};