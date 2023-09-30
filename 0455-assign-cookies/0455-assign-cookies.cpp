class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int j = 0;
        for(int i = 0; i < g.size(); i++){
            if(j == s.size()) break;
            if(g[i] <= s[j]){
                cnt++;
                j++;
            } else{
                j++;
                i--;
            }
            
        }
        return cnt;
    }
};