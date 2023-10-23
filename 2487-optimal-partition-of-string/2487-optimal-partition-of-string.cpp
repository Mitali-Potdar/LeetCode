class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> m;
        int cnt = 1;
        for(int i = 0; i < s.size(); i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]]++;
            } else{
                cnt++;
                m.clear();
                m[s[i]]++;
            }
        }
        return cnt;
    }
};