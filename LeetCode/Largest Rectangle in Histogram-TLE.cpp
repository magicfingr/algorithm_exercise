class Solution {
public:
    /**
     * 类似找数组最大子序列的题，同样可用分治：找出当前直方图中最短的一块，那么最大矩形面积：
     * 1. 就是高为min，长为图长的矩形
     * 2. 在[low, min - 1]中
     * 3. 在[min + 1, high]中
     * 从最小点切，是因为以最小点为高构成的矩形面积非常容易计算，即 min * lenght！
     * O(NlogN), O(N)
     * TLE...
     */
    int largestRectangleArea(vector<int> &height) {
        return m_largestRectangleArea(height, 0, height.size() - 1);
    }
private:
    int m_largestRectangleArea(const vector<int> &height, const int low, const int high){
        if(low > high)
            return 0;
        
        int minIndex = low;
        for(int i = low + 1; i <= high; i++){
            if(height[minIndex] > height[i])
                minIndex = i;
        }
        int curArea = height[minIndex] * (high + 1 - low);
        int leftMaxArea = m_largestRectangleArea(height, low, minIndex - 1);
        int rightMaxArea = m_largestRectangleArea(height, minIndex + 1, high);
        return max(curArea, max(leftMaxArea, rightMaxArea));
    }
};