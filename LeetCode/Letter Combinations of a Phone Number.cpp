class Solution {
public:
    /**
    * 先构造词典，然后DFS
    */
    vector<string> letterCombinations(string digits) {
        //init dict
        map<char, vector<string> > dict;
        dict['0'] = dict['1'] = vector<string>();
        char c = 'a';
        for(int i = 2; i <= 9; i++) {
            vector<string> letters;
            for (int j = 0; j < 3; j++)
                letters.push_back(string(1, c++));
            if (i == 7 || i == 9){
                letters.push_back(string(1, c++));
            }
            dict['0' + i] = letters;
        }
        //DFS
        vector<string> re;
        permutate(dict, digits, "", re);
        return re;
    }
private:
    void permutate(const map<char, vector<string> > &dict, const string digits, const string curPerm, vector<string> &re){
        if (digits == ""){
            re.push_back(curPerm);
            return;
        }
        vector<string> letters = dict.find(digits[0])->second;
        for (size_t i = 0; i < letters.size(); i++){
            permutate(dict, digits.substr(1), curPerm + letters[i], re);
        }
    }
};