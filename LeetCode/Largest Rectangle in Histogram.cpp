class Solution {
public:
    /**
     * O(N)的VERY tricky算法：
     * 若栈为空或栈顶元素小于histo[i]，则将下标入栈，继续遍历
     * 否则出栈，计算当前矩形面积，并更新最大值
     *     当前矩形左边界为栈顶前一个元素：[s.top() - 1, i - 1]
     *                                  or [0, i - 1], 栈为空
    */
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        height.push_back(0);    //哨兵
        while (i < height.size()){
            if (s.empty() || height[s.top()] <= height[i]){
                s.push(i);
                i++;
            }
            else{
                int cur = s.top();
                s.pop();
                //area: [s.top - 1, i - 1]
                int len = s.empty() ? i : i - s.top() - 1;
                int area = len * height[cur];
                maxArea = max(area, maxArea);
            }
        }
        height.pop_back();
        return maxArea;
    }
};