class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(x == 1) return 1;
        unsigned int m;
        m = n;
        if(n < 0){
            m = -(unsigned int)n;
            x = 1/x;
        }
        double res = 1;
        while(m){
            if( m % 2 == 1){
                res = res * x;
            } 
            x *= x;
            m = m/2;
        }

    
        return res;
    }
};