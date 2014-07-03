class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> valueMap;
        valueMap['I'] = 1;
        valueMap['V'] = 5;
        valueMap['X'] = 10;
        valueMap['L'] = 50;
        valueMap['C'] = 100;
        valueMap['D'] = 500;
        valueMap['M'] = 1000;
        
        int value = 0;
        size_t i = 0;
        while(i < s.size()){
            if(i + 1 < s.size() && valueMap[s[i]] < valueMap[s[i + 1]]){
                value += valueMap[s[i + 1]] - valueMap[s[i]];
                i += 2;
            } else{
                value += valueMap[s[i]];
                i++;
            }
        }
        return value;
    }
};