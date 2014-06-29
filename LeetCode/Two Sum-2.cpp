class Solution {
public:
    /**
     * 排序，先在前面确定第一个数，然后从后面找剩余的需要的第二个数，交替
     * 前后和太大则后面往前移，太小则前面往后移
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> nodes;
        for(int i = 0; i < numbers.size(); i++)
            nodes.push_back(Node(numbers[i], i + 1));
        
        sort(nodes.begin(), nodes.end());
        int i = 0;
        int j = nodes.size() - 1;
        
        while(i < j){
            if(nodes[i].val + nodes[j].val > target)
                j--;
            else if(nodes[i].val + nodes[j].val < target)
                i++;
            else
                break;
        }
        vector<int> re;
        if(nodes[i].position < nodes[j].position){
            re.push_back(nodes[i].position);
            re.push_back(nodes[j].position);
        } else{
            re.push_back(nodes[j].position);
            re.push_back(nodes[i].position);
        }
        return re;
    }
private:
    struct Node{
        int val;
        int position;
        Node(int val, int position): val(val), position(position){}
        bool operator <(const Node& b) const{
            return val < b.val;
        }
    };
};