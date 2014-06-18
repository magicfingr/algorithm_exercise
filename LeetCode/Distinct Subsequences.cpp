class Solution {
public:
    /**
     * 题目描述不准确，参见 Discuss -> Task clarification
     * BF:先找出T中所有字符在S中出现的位置，然后统计这些字符的合法组合数，O(N^2 * M)，negative
     * 用DP降维：
     * 设f(i, j)表示长度为i的S，与长度为j的T的解，则
     * f(i, j) = f(i - i, j) + f(i - 1, j - 1) (S[i] == T[j])
     *                    or + 0 (S[i] != T[j])
     * f(0, j) = 0, f(i, 0) = 1, f(0, 0) = 1
     * 求f(S.size(), T.size());
     * 最终复杂度为O(N*M), O(M)
     */
    int numDistinct(string S, string T) {
        int *result = new int[T.size() + 1];    //reuse and store results from f(1, j) ~ f(S.size(), j)
        memset(result, 0, sizeof(int) * (T.size() + 1));
        result[0] = 1;      //f(0, 0) = 1
        
        //calculate f(1, j) ~ f(S.size(), j)
        for(int i = 1; i <= S.size(); i++){
            int lastResult = result[0];     //store f(i - 1, j - 1)
            for(int j = 1; j <= T.size(); j++){
                if(i < j)
                    break;
                int curResult = result[j];  //store f(i - 1, j)
                if(S[i - 1] == T[j - 1])    //note the index of i's character in S is S[i - 1], so does in T
                    result[j] += lastResult;    //update f(i, j)
                lastResult = curResult;     //j++, so f(i - 1, j) becomes f(i - 1, j - 1)
            }
        }
        return result[T.size()];
    }
};
