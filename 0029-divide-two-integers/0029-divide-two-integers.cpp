class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        long int dd = abs(dividend), dv = abs(divisor);
        long long res = 0;
        while(dv<=dd) {
            long int mul=dv, tmp=1;
            while(mul<=dd-mul) {
                mul+=mul;
                tmp+=tmp;
            }
            res+=tmp;
            dd-=mul;
        }
        if(res > INT_MAX) return INT_MAX;
       if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)){
            if(-res < INT_MIN) return INT_MIN;
            return -res;
        } 
        return res;
    }
};