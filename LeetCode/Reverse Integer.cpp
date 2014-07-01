class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }
        int re = 0;
        while(x > 0){
            re = re * 10 + x % 10;
            x /= 10;
        }
        return sign * re;
    }
};