//直接BF会TLE
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        //BF, O(N^2)
        int len = gas.size();
        int *remain = new int[len];
        for(int i = 0; i < len; i++){
            remain[i] = gas[i] - cost[i];
        }
        //循环remain，尝试从所有点出发
        for(int i = 0; i < len; i++){
            //循环累加至起点，若累加和始终 >= 0，则找到此点
            int sum = 0;
            int startPos = i;
            int loopCount = 0;
            for(; loopCount < len; loopCount++){
                sum += remain[(startPos + loopCount) % len];
                if(sum < 0)
                    break;
            }
            if(loopCount >= len)
                return startPos;
        }
        return -1;
    }
};