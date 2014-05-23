/*
RE, Last executed input:	" 1" or "1 "
错误：
开始没有看题，没有去掉多余空格
迭代器的位置操作
循环的判断条件
注意：迭代器进行算术运算时，会判断其结果的有效性！
*/
#include "stdafx.h"

#include "iostream"
#include "cstdio"
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string::iterator lastBegin, it, newIt;
		lastBegin = newIt = it = s.begin();

		while (it != s.end() && *it == ' ') it++;
		while (it != s.end()){
			if (*it == ' '){
				reverseString(lastBegin, newIt - 1);
				while (it != s.end() && *it == ' ') it++;
				if (it != s.end() && newIt != s.end())
					*newIt++ = ' ';
				lastBegin = newIt;
			}
			else{
				*newIt++ = *it++;
			}
		}
		if (newIt == s.begin()){
			s.clear();
			return;
		}
		s = s.substr(0, newIt - s.begin());
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