class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int flag = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ' && flag == 1){
                break;
            }
            if(s[i] != ' '){
                flag = 1;
                l++;
            }
        }
        // int j = s.size()-1;
        // int k;
        // if(s[s.size()-1] == ' '){
        //     for(int i = s.size()-1; i >= 0; i--){
        //         if(s[i] != ' '){
        //             j = i;
        //             break;
        //         }               
        //     }
        // }
        // for(k = j; k >= 0; k--){
        //     if(s[k] == ' '){
        //         break;
        //     }
        //     l++;
        // }
        return l;
    }
};