class Solution {
public:
    /**
     * O(N),O(N)
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        //存两份连续的remain
        int len = gas.size() * 2;
        int *remain = new int[len];
        for(int i = 0, j = gas.size(); i < gas.size(); i++, j++){
            remain[i] = gas[i] - cost[i];
            remain[j] = remain[i];
        }
        //扫数组，累加，累加到负了就清零重新开始，直到累加了gas.size个元素为止
        int sum = 0;
        int startPos = 0;
        for(int curPos = 0; curPos < len; curPos++){
            //非负则直接加
            if(remain[curPos] >= 0){
                sum += remain[curPos];
            }
            //负数
            else{
                //若累加后仍然非负，则继续加
                if(sum + remain[curPos] >= 0){
                    sum += remain[curPos];
                }
                //否则清零，重新开始
                else{
                    sum = 0;
                    startPos = curPos + 1;
                }
            }
            //累加完当前数以后，再判断是否已累加完成
            if(curPos + 1 - startPos >= gas.size())
                return startPos;
        }
        return -1;
    }
};