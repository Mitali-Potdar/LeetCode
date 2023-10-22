class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int flag = 0;
        if(x == -pow(2,31)) return 0;
        if(x < 0){
            flag = 1;
            x = -x;
        }
        while(x > 0){
            int t = x % 10;
            res += t;
            res *= 10;
            x /= 10;
        }
        res = res/10;
        if(res > pow(2,31) - 1 || res < -pow(2,31)) return 0;
        if(flag == 0)
            return res;
        return -res;
    }
};