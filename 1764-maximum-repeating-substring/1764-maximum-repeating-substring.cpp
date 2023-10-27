class Solution {
public:
    int maxRepeating(string seq, string word) {
        int res = 0;
        int n = seq.size();
        int m = word.size();
        int cnt = 0;
        int i = 0;
        int j = m-1;
        while(j < n){
            if(seq.substr(i, j-i+1) != word){
                if(cnt > 0){ //if prev substring was a match, go to the index after prev substring
                    i -= m;
                    j -= m;
                }
                i++;
                j++;
                cnt = 0;
            } else {
                cnt++;
                res = max(res, cnt);
                i += m;
                j += m;
            }
        } 
        return res;    
    }
};