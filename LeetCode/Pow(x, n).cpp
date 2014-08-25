class Solution {
public:
    double pow(double x, int n) {
        bool isPositive = true;
        long long exp = n;
        if(exp < 0){
            isPositive = false;
            exp = -exp;
        }
        
        double re = 1;
        while(exp > 0){
            double mul = x;
            int factor = 1;
            while(factor * 2 > 0 && factor * 2 < exp){
                factor += factor;
                mul *= mul;
            }
            re *= mul;
            exp -= factor;
        }
        return isPositive ? re : 1.0 / re;
    }
};