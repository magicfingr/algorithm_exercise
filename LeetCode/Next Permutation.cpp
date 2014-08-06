class Solution {
public:
    /**
     * 先找最后面的非升序序列
     * 从序列中选一个刚好比序列左边的邻接数大的一个数，与左边的邻接数交换，然后将序列反转即可
     */
    void nextPermutation(vector<int> &num) {
        int index= -1;
        for(int i = num.size() - 1; i >= 1; i--){
            if(num[i - 1] < num[i]){
                index = i;
                break;
            }
        }
        
        if(index - 1 >= 0){
            //reverse the decreasing sequence
            for(int i = index, j = num.size() - 1; i < j; i++, j--)
                swap(num[i], num[j]);
            //swap
            for(int i = index; i < num.size(); i++){
                if(num[i] > num[index - 1]){
                    swap(num[i], num[index - 1]);
                    break;
                }
            }
        } else{
            sort(num.begin(), num.end());
        }
    }
private:
    void swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }
};