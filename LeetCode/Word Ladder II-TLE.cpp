#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	/**
	* BSF
	* 用与Word Ladder相同的优化，但还是TLE
	* 优化：
	* 删除词典中已列举过的词（会改变词典内容）
	*/
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> re;	//保存返回的结果

		dict.erase(start);
		vector<vector<string>> curRe;	//保存当前的转化结果
		vector<string> ladder;
		ladder.push_back(start);
		curRe.push_back(ladder);
		if (start == end){
			return curRe;
		}
		vector<vector<string>> newRe;   //保存新的转化结果
		bool isReached = false;
		//若还可以继续变换，且未到达end则一直循环
		while (curRe.size() > 0){
			newRe.clear();
			//遍历当前结果
			for (vector<vector<string>>::iterator ladderIt = curRe.begin(); ladderIt != curRe.end(); ladderIt++){
				//取末尾待变换的串
				string curStr = (*ladderIt)[ladderIt->size() - 1];
				//保存新的未列举过的变换结果
				for (int i = 0; i < curStr.size(); i++){
					string newStr = curStr;
					for (char c = 'a'; c <= 'z'; c++){
						newStr[i] = c;
						if (newStr == end){
							isReached = true;
							vector<string> newLadder = *ladderIt;
							newLadder.push_back(newStr);
							
							newRe.push_back(newLadder);
							re.push_back(newLadder);
						}
						//字典中存在，则保存为新的变换结果
						else if (dict.find(newStr) != dict.end()){
							vector<string> newLadder = *ladderIt;
							newLadder.push_back(newStr);
							newRe.push_back(newLadder);
						}
						else{}
					}
				}
				//列举完毕后，从字典中删除已列举的旧串
				dict.erase(curStr);
			}
			//更新结果
			curRe.clear();
			curRe.swap(newRe);
			if (isReached)
				return re;
		}
		//cannot reach, return is not specified?
		return re;
	}
};