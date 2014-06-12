class Solution {
public:
    /**
     * BST(map)，O(NlogN)
     * hash(unordered_map)可以做到近似O(N)，不过最坏是O(N^2)
     */
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> hashMap;
        //先扫一遍插入hashmap，再扫一遍找子序列
        for(int i = 0; i < num.size(); i++){
            hashMap[num[i]] = 1;
        }
        
        int maxLen = 0;
        //循环hashmap，判断包含当前元素的最长序列
        for(unordered_map<int, int>::iterator it = hashMap.begin(); it != hashMap.end(); it++){
            if(it->second <= 0){
                //当前元素已判断过
                continue;
            }
            //标记当前元素已判断
            it->second = 0;
            //保存当前序列长度
            int len = 1;
            //判断当前元素+1、-1的元素是否存在
            int cur = it->first;
            while(hashMap[cur + 1] > 0){
                //标记已判断
                hashMap[cur + 1] = 0;
                len++;
                cur++;
            }
            cur = it->first;
            while(hashMap[cur - 1] > 0){
                //标记已判断
                hashMap[cur - 1] = 0;
                len++;
                cur--;
            }
            //保存最大长度
            if(maxLen < len){
                maxLen = len;
            }
        }
        return maxLen;
    }
};
