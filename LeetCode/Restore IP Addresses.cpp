class Solution {
public:
    /**
     * 穷举，剪枝
     */
    vector<string> restoreIpAddresses(string s) {
        vector<string> re;
        if(s.size() < 4)
            return re;
        /*
        将字符串分为4段：[0, i - 1], [i, j - 1], [j, k - 1], [k, s.size() - 1]
        1 <= i <= s.size() - 3, i < 1 + 3
        i + 1 <= j <= s.size() - 2, j < i + 1 + 3
        j + i <= k <= s.size() - 1, j < j + 1 + 3
        */
        for(int i = 1; i <= s.size() - 3 && i < 4; i++){
            for(int j = i + 1; j <= s.size() - 2 && j < i + 4; j++){
                for(int k = j + 1; k <= s.size() - 1 && k < j + 4; k++){
                    string part1 = s.substr(0, i);
                    string part2 = s.substr(i, j - i);
                    string part3 = s.substr(j, k - j);
                    string part4 = s.substr(k);
                    if(isValidPart(part1) && isValidPart(part2) && isValidPart(part3) && isValidPart(part4)){
                        re.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                    }
                }
            }
        }
        return re;
    }
private:
    //检查s是否是合法IP段
    //注意有效数字必须处在第一位
    //注意"00", "010"的情况！！
    bool isValidPart(string s){
        //assert: 0 < s.size() <= 3
        int val = atoi(s.c_str());
        if(val > 0 && s[0] == '0')
            return false;
        if(val == 0 && s != "0")
            return false;
        return 0 <= val && val <= 255;
    }
};