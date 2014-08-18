class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        string next = "";
        while(--n){
            int i = 0;
            while(i < cur.size()){
                int j = i;
                while(j < cur.size() && cur[j] == cur[i])
                    j++;
                next += (j - i) + '0';  //count
                next += cur[i];   //char
                i = j;
            }
            cur = next;
            next = "";
        }
        return cur;
    }
};