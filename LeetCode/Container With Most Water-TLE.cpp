class Solution {
public:
    /**
     * DP，求f(n - 1)
     * f(i) = max(f(i - 1), max((0, i), (1, i), ..., (i - 1, i)))
     * O(N^2), O(N)
     */
    int maxArea(vector<int> &height) {
        if(height.size() == 0)
            return 0;
            
        int *m_maxArea = new int[height.size()];
        m_maxArea[0] = 0;
        for(size_t i = 1; i < height.size(); i++){
            int area = 0;
            for(size_t j = 0; j < i; j++){
                int tArea = (i - j) * min(height[i], height[j]);
                area = max(area, tArea);
            }
            m_maxArea[i] = max(area, m_maxArea[i - 1]);
        }
        return m_maxArea[height.size() - 1];
    }
};