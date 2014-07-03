class Solution {
public:
    string intToRoman(int num) {
        int weight[4] = {1000, 100, 10, 1};
        char ch[4][3] = {{'M', ' ', ' '},
                        {'C', 'D', 'M'},
                        {'X', 'L', 'C'},
                        {'I', 'V', 'X'}};
        //找第一个有效位
        int i = 0;
        while(num / weight[i] == 0)
            i++;
        //遍历，从高位到低位依次转换
        string re;
        while(i < 4){
            re += convert(num / weight[i], ch[i]);
            num %= weight[i];
            i++;
        }
        return re;
    }
private:
    string convert(int val, char *ch){
        string re;
        if(0 == val){
            re = "";
        } else if(1 <= val && val <= 3){
            for(int i = 0; i < val; i++)
                re += ch[0];
        } else if(4 == val){
            re = ch[0];
            re += ch[1];
        } else if(5 <= val && val <= 8){
            re = ch[1];
            for(int i = 0; i < val - 5; i++)
                re += ch[0];
        } else{     //9 == val
            re = ch[0];
            re += ch[2];
        }
        return re;
    }
};