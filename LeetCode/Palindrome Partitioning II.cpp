class Solution {
public:
    /**
     * 看起来比 Palindrome Partitioning 要简单。。。
     * 不过原来的O(N^3)是无论如何剪枝也过不了的。。。
     * 先用O(N^2)的DP算所有字串的palindrome，然后再用O(N^2)的DP算minCut，此时不剪枝也能过
     */
    int minCut(string s) {
        if(s.size() <= 0){
            return 0;
        }
        //求所有字串的palindrome
        bool **palindrome = calPalindrome(s);
        
        int *minCuts = new int[s.size()];
        memset(minCuts, -1, sizeof(int) * s.size());
        //从后往前循环字符串
        for(int start = s.size() - 1; start >= 0; start--){
            //每加一个字符，循环判断所有可能构成的新串
            //从长到短判断，可以更快得得到最优结果
            for(int end = s.size() - 1; end >= start; end--){
                string newStr = s.substr(start, end + 1 - start);
                //新串不是回文串则继续循环
                if(!palindrome[start][end]){
                    continue;
                }
                //如果组成新串后没有剩余字符，则当前最短cut = 0（无需cut）
                if(end >= s.size() - 1){
                    minCuts[start] = 0;
                    //剪枝，零为最优结果，可停止搜索
                    break;
                }
                //如果有剩余字符，且剩余字符也能partition
                else if(minCuts[end + 1] >= 0){
                    //当前cut=剩余串的最短cut+1
                    int cut = minCuts[end + 1] + 1;
                    //剪枝：注意到minCuts[start]不可能再为零，故最短的可能cut为1，如果找到为1的cut即可停止搜索
                    if(cut == 1){
                        minCuts[start] = cut;
                        break;
                    }
                    ////判断并取最短cut
                    if(minCuts[start] == -1 || minCuts[start] > minCuts[end + 1])
                        minCuts[start] = minCuts[end + 1] + 1;
                }
            }
        }
        return minCuts[0];
    }
    
    //DP，计算字符串的所有可能字串是不是回文串，存到一个二维数组中
    //pal(i, j) = pal(i+1, j-1) && s[i] == s[j]
    bool** calPalindrome(const string str){
        //初始化
        bool **palindrome = new bool*[str.size()];
        for(int i = 0; i < str.size(); i++){
            palindrome[i] = new bool[str.size()];
            memset(palindrome[i], false, sizeof(bool) * str.size());
        }
        //循环判断每一个中心点扩展出的串是否为回文串
        for(int center = 0; center < str.size(); center++){
            //循环，以每一个字符为中心点向两边扩展（注意考虑奇偶），并判断，碰到非回文串即可停止
            //奇回文串
            int oddLeft = center;
            int oddRight = center;
            expandAndCal(str, oddLeft, oddRight, palindrome);
            
            //偶回文串
            int evenLeft = center - 1;
            int evenRight = center;
            expandAndCal(str, evenLeft, evenRight, palindrome);
        }
        
        return palindrome;
    }
    
    //从left、right往str两边扩展直至边界，同时判断产生的串是否为回文串
    //碰到非回文串即可停止
    void expandAndCal(const string &str, int left, int right, bool **palindrome){
        //判断size合法性
        while(left >= 0 && right < str.size()){
            //碰到非回文串则可停止搜索
            if(str[left] != str[right]){
                return;
            }
            if(left + 1 > right - 1){
                palindrome[left][right] = true;
            }
            else if(palindrome[left + 1][right - 1]){
                palindrome[left][right] = true;
            }
            left--;
            right++;
        }
    }
};
