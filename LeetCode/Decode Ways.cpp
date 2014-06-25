/*
测试：
100
110
101
111
*/
class Solution {
public:
    /**
     * DP:
     * f(i) = f(i + 1) + f(i + 2), 若[i, i + 1], [i + 2, len - 1]都是合法的encode
     *     or f(i + 1)
     * 注意判断错误的输入中多余的"0"！，以及10、20中合法的"0"！
     * 假设输入中只包含数字，则非法输入只包含两种，一是开头出现"0"，而是中间出现"00"
     */
    int numDecodings(string s) {
        if(s.size() <= 0)
            return 0;
        if(s[0] == '0')     //数据错误
            return 0;
        
        int *nums = new int[s.size() + 1];  //结果存在 nums[0, s.size() - 1]
        memset(nums, 0, sizeof(int) * (s.size() + 1));
        
        //nums[s.size()] = 0;
        //从后往前算，返回nums[0]
        for(int i = s.size() - 1; i >= 0; i--){
            string encode = s.substr(i, 2);
            if(encode == "00")  //非法输入
                return 0;
            //非法encode，直接跳过，表示这段的解码方式为零
            if(encode[0] == '0')
                continue;
            //若[i, i + 1]是合法encode
            if(isValidRange(encode)){
                if(i + 2 >= s.size()){
                    nums[i] = nums[i + 1] + 1;
                } else{
                    nums[i] = nums[i + 1] + nums[i + 2];
                }
            } else{
                nums[i] = nums[i + 1];
            }
        }
        return nums[0];
    }
private:
    bool isValidRange(const string &s){
        int a = atoi(s.c_str());
        return 1 <= a && a <= 26;
    }
};