class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        //int flag = 0;
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[j]){
                //flag = 1;
                j++;
                if(j == needle.size()){
                    return i + 1 - j;
                }
            }
            else if(haystack[i] != needle[j] ){
                //flag = 0;
                i = i - j;
                j = 0;
            }
        }
        return -1;
    }
};