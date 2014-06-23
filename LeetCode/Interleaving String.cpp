class Solution {
public:
	/**
	* 注意中间交叉顺序的选择会影响到最终结果
	* 穷举，找出可行方案 => DP:
	*
	* f(i1, i2) = (f(i1 - 1, i2) + 1), s1[i1 - 1] == s3[i1 + i2 - 1]
	*          || (f(i1, i2 - 1) + 1 ), s2[i2 - 1] == s3[i1 + i2 - 1]
	*
	* O(N1*N2), O(N1*N2)
	*/
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())
			return false;
		if (s1.size() <= 0)
			return s2 == s3;
		if (s2.size() <= 0)
			return s1 == s3;

		bool **inter = new bool*[s1.size() + 1];
		for (int i = 0; i <= s1.size(); i++){
			inter[i] = new bool[s2.size() + 1];
			memset(inter[i], false, sizeof(bool) * (s2.size() + 1));
		}
		//初始值
		for (int i = 0; i <= s1.size(); i++){
			if (s1.substr(0, i) == s3.substr(0, i))
				inter[i][0] = true;
			else
				break;
		}
		for (int i = 0; i <= s2.size(); i++){
			if (s2.substr(0, i) == s3.substr(0, i))
				inter[0][i] = true;
			else
				break;
		}
		//dp，填表
		for (int i1 = 1; i1 <= s1.size(); i1++){
			for (int i2 = 1; i2 <= s2.size(); i2++){
				if (s1[i1 - 1] == s3[i1 + i2 - 1])   //注意字符串下标
					inter[i1][i2] |= inter[i1 - 1][i2];
				if (s2[i2 - 1] == s3[i1 + i2 - 1])
					inter[i1][i2] |= inter[i1][i2 - 1];
			}
		}
		return inter[s1.size()][s2.size()];
	}
};