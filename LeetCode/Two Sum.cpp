class Solution {
public:
    /**
     * hash，边扫边存，一遍就知
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> re;
        unordered_map<int, int> numberMap;
        for(int i = 0; i < numbers.size(); i++){
            unordered_map<int, int>::iterator pos = numberMap.find(target - numbers[i]);
            if(numberMap.end() == pos){     //not found, add as new element
                numberMap[numbers[i]] = i + 1;
            } else{
                if(i + 1 < pos->second){
                    re.push_back(i + 1);
                    re.push_back(pos->second);
                } else{
                    re.push_back(pos->second);
                    re.push_back(i + 1);
                }
                return re;
            }
        }
        //not found, return empty vector
        return re;
    }
};