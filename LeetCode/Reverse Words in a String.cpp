/*
错误：
注意迭代器指向的位置！
注意：迭代器的算术运算会判断其结果的有效性！

以清晰为第一目的，然后是简洁，然后是效率
*/
class Solution {
public:
	void reverseWords(string &s) {
		//delete extra spaces
		string::iterator newIt = s.begin();     //注意newIt指向的是下一个存放有效字符的位置
		bool flag = false;
		for (string::iterator it = s.begin(); it != s.end(); it++){
			if (*it != ' '){
				*newIt++ = *it;
				flag = true;
			}
			else if (*it == ' ' && flag){
				*newIt++ = ' ';
				flag = false;
			}
		}
		if (newIt == s.begin()){
			s.clear();
			return;
		}
		if (*(newIt-1) == ' ')
			newIt--;
		s = s.substr(0, newIt - s.begin());

        //reverse
		string::iterator lastBegin = s.begin();
		for (string::iterator it = s.begin(); it != s.end(); it++){
			if (*it == ' '){
				reverseString(lastBegin, it - 1);
				lastBegin = it + 1;
			}
		}
		reverseString(lastBegin, s.end() - 1);
		reverseString(s.begin(), s.end() - 1);
	}
private:
	//reverse string in [first, last]
	void reverseString(string::iterator first, string::iterator last){
		for (; first < last; first++, last--){
			char t = *first;
			*first = *last;
			*last = t;
		}
	}
};