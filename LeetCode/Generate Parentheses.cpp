class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> perms;
        generate(n - 1, n, "(", perms);
        return perms;
    }
private:
    void generate(const int remainBegins, const int remainEnds, string s, vector<string> &perms){
        if(remainEnds == 0){
            assert(remainBegins == 0);
            perms.push_back(s);
            return;
        }
        if(remainBegins > 0)
            generate(remainBegins - 1, remainEnds, s + "(", perms);
        if(remainEnds > remainBegins)
            generate(remainBegins, remainEnds - 1, s + ")", perms);
    }
};