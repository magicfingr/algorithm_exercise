class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > group;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            group[s].push_back(strs[i]);
        }
        vector<string> re;
        for(map<string, vector<string> >::iterator it = group.begin(); it != group.end(); it++){
            if(it->second.size() >= 2)
                re.insert(re.end(), it->second.begin(), it->second.end());
        }
        return re;
    }
};