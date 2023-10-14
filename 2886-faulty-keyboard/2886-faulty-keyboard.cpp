class Solution {
public:
    string finalString(string s) {
        string res = "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'i'){
                reverse(res.begin(), res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }
};