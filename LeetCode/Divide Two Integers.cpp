class Solution {
public:
    int divide(int dividend, int divisor) {
        int re = 0;
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = -1;

        assert(divisor != 0);
        long long ddend = dividend;
        long long dsor = divisor;
        ddend = ddend > 0 ? ddend : -ddend;
        dsor = dsor > 0 ? dsor : -dsor;
        while (ddend >= dsor){
            int factor = 0;
            while (ddend >= dsor << factor){
                ddend -= dsor << factor;
                re += 1 << factor;
                factor++;
            }
        }
        return sign > 0 ? re : -re;
    }
};