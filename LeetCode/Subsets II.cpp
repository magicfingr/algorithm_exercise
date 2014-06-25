class Solution {
public:
    /**
    * DFS
    * 注意排除重复，画演化树帮助理解
    */
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > sets;
        if (S.size() <= 0)
            return sets;

        sort(S.begin(), S.end());
        vector<int> empty;
        dfs(S, 0, empty, sets);
        return sets;
    }
private:
    void dfs(const vector<int> &s, const int cur, vector<int> &curSet, vector<vector<int> > &sets){
        if (cur >= s.size()){   //访问完毕
            sets.push_back(curSet);
            return;
        }
        //如果cur重复了k次（包括当前），那么只处理已经加入过k-1次cur点的集合（最长重复），其余重复的集合直接保持
        //判断集合是否为重复集合中的最长重复集合
        bool flag = true;
        int i = cur - 1;
        int j = curSet.size() - 1;
        while (i >= 0 && s[i] == s[cur]){   //有重复
            //集合中必须含有同样数目的重复元素
            if (j >= 0 && curSet[j] == s[cur]){
                i--;
                j--;
            }
            else{
                flag = false;
                break;
            }
        }

        //不加入当前点
        dfs(s, cur + 1, curSet, sets);
        if (flag){
            //加入当前点
            curSet.push_back(s[cur]);
            dfs(s, cur + 1, curSet, sets);
            curSet.pop_back();
        }
    }
};