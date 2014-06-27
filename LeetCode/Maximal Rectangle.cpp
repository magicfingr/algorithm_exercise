class Solution {
public:
    /**
     * 可以利用Largest Rectangle in Histogram的算法
     * 把整个matrix看成N个直方图，每层一组，计算所有直方图的最大面积，然后取最大值即可
     * O(N*M), O(M)
     */
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() <= 0)
            return 0;
        //先把matrix[N*M]转成一个N维的直方图histo[N][M] 
        int **histo = new int*[matrix.size()];
        for(int i = 0; i < matrix.size(); i++){
            histo[i] = new int[matrix[i].size() + 1];   //最后一位留作哨兵
            memset(histo[i], 0, sizeof(int) * (matrix[i].size() + 1));
        }
        //init histograms
        for(int i = 0; i < matrix[0].size(); i++)
            histo[0][i] = matrix[0][i] - '0';
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == '1')
                    histo[i][j] = histo[i - 1][j] + 1;
            }
        }
        //find max rec in each histogram, then update the result
        int maxRec = 0;
        for(int i = 0; i < matrix.size(); i++){
            int rec = maxRecInHistogram(histo[i], matrix[i].size() + 1);
            maxRec = max(rec, maxRec);
        }
        return maxRec;
    }
private:
    /**
     * histo最后一位必须为哨兵0，否则算法上要多些判断处理
     * 若栈为空或栈顶元素小于histo[i]，则入栈，继续遍历
     * 否则出栈，计算当前矩形面积，并更新最大值
     *     当前矩形左边界为栈顶前一个元素：[s.top() - 1, i - 1]
     *                                  or [0, i - 1], 栈为空
     */
    int maxRecInHistogram(int *histo, int n){
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        while(i < n){
            if(s.empty() || histo[s.top()] <= histo[i]){
                s.push(i);
                i++;
            } else{
                int cur = s.top();
                s.pop();
                int len = s.empty() ? i : i - s.top() - 1;
                int area = histo[cur] * len;
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};