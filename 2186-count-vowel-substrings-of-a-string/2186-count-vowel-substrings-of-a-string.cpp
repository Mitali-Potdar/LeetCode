class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int solve(string str, int start, int end){
        unordered_map<char, int> m;
        int cnt = 0;
        for(int i = start; i <= end; i++){
            m[str[i]]++;
            if(m.size() == 5){
                int k = start;
                while(m.size() == 5){
                    m[str[k]]--;
                    if(m[str[k]] == 0){
                        m.erase(str[k]);
                        break;
                    }
                    k++;       
                }
                int prefix = k - start + 1;
                int suffix = end - i + 1;
                cnt += prefix*suffix;
                start = k+1;
            }

        }
        return cnt;
    }
    int atMost(string s, int k){
        if( k < 0) return 0;
        unordered_map<char, int> m;
        int l = 0;
        int cnt = 0;
        for(int r = 0; r < s.size(); r++){
            if(isVowel(s[r])){
                m[s[r]]++;
                while(m.size() > k){
                    m[s[l]]--;
                    if(m[s[l]] == 0) m.erase(s[l]);
                    l++;
                }
                cnt += r-l+1;
            } else {
                l = r+1;
                m.clear();
            }    
        }
        return cnt;
    }
    int countVowelSubstrings(string str) {
        return atMost(str, 5) - atMost(str, 4);
        // int n = str.size();
        // int count = 0;
        // for(int i = 0; i < n; i++){
        //     if(isVowel(str[i])){
        //         int j = i+1;
        //         while(j < n && isVowel(str[j])) j++;
        //         count += solve(str, i, j-1); //solving for entire block of all vowels
        //         i = j;
        //     }
        // }
        // for(int i = 0; i < n; i++){
        //     unordered_set<char> s;
            
        //     for(int j = i; j < n; j++){
        //         if(isVowel(str[j])){
        //             s.insert(str[j]);
        //         }
        //         else
        //             break;
                
        //         if(s.size() == 5){
        //             count++;
        //         }
        //     }
        // }
        //return count;
    }
};

