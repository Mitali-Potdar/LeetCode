class Solution {
public:
    int num(string s){
        int x = 0;
        for(int i = 0; i < s.size(); i++){
            x += int(s[i] - '0');
            x *= 10;
        }
        return x/10;
    }
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> v;
        vector<int> res;
        int m = 0;
        int n  = words.size();
        int prev_cnt = 0;
        for(int i = 0; i < n; i++){
            if(words[i] == "prev"){
                prev_cnt++;
                int k = prev_cnt;
                if((m-k) < 0) res.push_back(-1);
                else res.push_back(v[m-k]);
            }
            else {
                prev_cnt = 0;
                v.push_back(num(words[i]));
                m++;
            }
        }
        return res;
    }
};