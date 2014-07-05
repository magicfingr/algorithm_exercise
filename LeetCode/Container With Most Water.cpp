class Solution {
public:
    /**
     * 贪心，每次舍弃短板，同时更新最大值。O(N)
     * 正确性可用反证法证明（参见Discuss）
     */
    int maxArea(vector<int> &height) {
        int low = 0;
        int high = height.size() - 1;
        int m_maxArea = 0;
        while(low < high){
            int area = (high - low) * min(height[low], height[high]);
            m_maxArea = max(area, m_maxArea);
            if(height[low] <= height[high]){
                low++;
            } else{
                high--;
            }
        }
        return m_maxArea;
    }
};