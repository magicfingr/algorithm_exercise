/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * 与clone链表类似，可用map保存新旧节点地址的映射
     * O(N),O(N)
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(NULL == node)
            return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        //深搜旧图，复制每个节点，并保存新-旧节点地址映射
        map<UndirectedGraphNode*, bool> oldVisit;
        dfsAndCopy(node, oldVisit, nodeMap);
        
        //深搜旧图，更新旧邻居地址
        map<UndirectedGraphNode*, bool> newVisit;
        dfsAndUpdate(node, newVisit, nodeMap);
        
        return nodeMap[node];
    }
    
    //深搜图，复制每个节点，并保存新-旧节点地址映射
    void dfsAndCopy(UndirectedGraphNode* node,
        map<UndirectedGraphNode*, bool> &visit,
        map<UndirectedGraphNode*, UndirectedGraphNode*> &nodeMap){
        //标记已访问
        visit[node] = true;
        //复制节点，保存映射
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        nodeMap[node] = newNode;
        //深搜其所有未访问的邻居
        for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin();
            it != node->neighbors.end(); it++){
            if(!visit[*it]){
                dfsAndCopy(*it, visit, nodeMap);
            }
        }
    }
    
    //深搜旧图，更新旧邻居地址
    void dfsAndUpdate(UndirectedGraphNode* node,
        map<UndirectedGraphNode*, bool> &visit,
        map<UndirectedGraphNode*, UndirectedGraphNode*> &nodeMap){
        //标记已访问
        visit[node] = true;
        //取旧节点对应的新节点地址，并新建neighbors表
        UndirectedGraphNode* newNode = nodeMap[node];
        vector<UndirectedGraphNode*> neighbors;
        //循环复制所有neighbors对应的新地址，同时对未访问的邻居继续深搜
        for(vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin();
            it != node->neighbors.end(); it++){
            //复制
            neighbors.push_back(nodeMap[*it]);
            //深搜
            if(!visit[*it]){
                dfsAndUpdate(*it, visit, nodeMap);
            }
        }
        //复制完毕
        newNode->neighbors = neighbors;
    }
};