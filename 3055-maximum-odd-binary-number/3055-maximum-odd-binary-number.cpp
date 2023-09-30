class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string res = "";
        int one = 0;
        for(int i = 0; i < s.size(); i++){
            if(one == 1 && s[i] == '1')res += '1';
            if(s[i] == '1') one = 1;
        }
        int n = s.size() - res.size() - 1;
        while(n--){
            res += '0';
        }
        res += '1'; 
        return res;
    }
};