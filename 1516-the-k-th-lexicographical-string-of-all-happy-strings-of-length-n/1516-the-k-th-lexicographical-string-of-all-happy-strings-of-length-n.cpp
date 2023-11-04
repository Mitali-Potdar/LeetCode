class Solution {
public:
    string getHappyString(int n, int k) {

        // Out of bound condition
        if(k>3*pow(2,n-1)) return "";
        string s = "";
        int prev = 4;
        string mapping = "abc";

        int m = n - 1, i = k - 1;
        while(m >= 0){
            int power = pow(2, m);
            int q = i / power;
            i %= power;
            m -= 1;

            if(prev <= q) q += 1;
            s += mapping[q];
            prev = q;
        }
        return s;
    }
};