// class Solution {
// public:
//     bool isVowel(char c) {
//         return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//     }
//     int solve(string str, int start, int end){
//         unordered_map<char, int> m;
//         for(int i = start; i <= end; i++){
//             m[str[i]]++;

//         }
//     }
//     int countVowelSubstrings(string str) {
//         int n = str.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             if(isVowel(str[i])){
//                 int j = i+1;
//                 while(isVowel(str[i]) && j < n) j++;
//                 count += solve(str, i, j-1); //solving for entire block of all vowels
//                 i = j;
//             }
//         }
//         // for(int i = 0; i < n; i++){
//         //     unordered_set<char> s;
            
//         //     for(int j = i; j < n; j++){
//         //         if(isVowel(str[j])){
//         //             s.insert(str[j]);
//         //         }
//         //         else
//         //             break;
                
//         //         if(s.size() == 5){
//         //             count++;
//         //         }
//         //     }
//         // }
//         return count;
//     }
// };




class Solution {
public:
    int countVowelSubstrings(string word) {
        
        unordered_map<char,int>m;
        int n=word.size();
        int ans=0;
        
        for(int i=0,cnt=0,j=0,pref=0;i<n;i++){
            if((word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'))
            {
                if(m[word[i]]++==0)
                     cnt++;
                
                while(m[word[j]]>1)
				m[word[j++]]--,pref++;
                
            if(cnt==5)ans+=(1+pref);
            }
               else{
               
                   cnt=0;
                   pref=0;
                   m.clear();
                   j=i+1;
               }
                   
            
            
        }
        return ans;
    }
};

