class Solution {
public:
	/**
	* BSF，实现上可参考树的层次遍历
	* 优化：
	* 删除词典中已列举过的词（会改变词典内容）
    * 用链表存路径前驱，而不是拷贝完整路径
	*/
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> result;	//保存返回的结果
		if(start == end || start.size() <= 0)    //不需要转时的返回值为空？
		    return result;

		queue<Node*> paths;
		Node *startNode = new Node(end);  //从end往start找
		paths.push(startNode);
		paths.push(NULL);     //level tag
		bool isReached = false;
		while(!paths.empty()){
		    Node *cur = paths.front();
		    paths.pop();
		    if(cur != NULL){
    		    //优化：从字典中删除已到达过的点
    		    dict.erase(cur->val);
		        //将当前节点所有子节点加入到队列，即：
		        //遍历当前串每一位，尝试用所有不同字符替代产生新串，若新串合法则将新路径加入队列
		        for(int i = 0; i < (cur->val).size(); i++){
		            for(char c = 'a'; c <= 'z'; c++){
		                string newStr = cur->val;
		                newStr[i] = c;
		                if(newStr == start){
		                    isReached = true;
		                    Node *newNode = new Node(newStr);
		                    newNode->pre = cur;
		                    //cur->next = newNode;
		                    paths.push(newNode);
		                    break;
		                }
		                if(dict.find(newStr) != dict.end()){
		                    Node *newNode = new Node(newStr);
		                    newNode->pre = cur;
		                    //cur->next = newNode;
		                    paths.push(newNode);
		                }
		            }
		        }
		    } else{
		        if(isReached || paths.empty())
		            break;
	            paths.push(NULL);
		    }
		}
		//找到到达start的路径，再从start追溯end找到完整路径
		while(!paths.empty()){
		    Node *cur = paths.front();
		    paths.pop();
		    if(cur->val == start){
		        vector<string> path;
		        do{
		            path.push_back(cur->val);
		            cur = cur->pre;
		        }while(cur != NULL);
		        result.push_back(path);
		    }
		}
		return result;
	}
private:
    //路径链表
    struct Node{
        string val;
        //struct Node *next;
        struct Node *pre;
        Node(string val):val(val), pre(NULL){}
        //Node(string val):val(val), next(NULL), pre(NULL){}
    };
};