// class Solution {
// public:
//     vector<vector<int>> dp;
// 	vector<vector<int>> dp1;

//     bool isPal(string s, int i, int j) {
// 		if (i >= j) return true;
// 		if (dp1[i][j] != -1) return dp1[i][j];
// 		if (s[i] == s[j]) return dp1[i][j] = isPal(s, i + 1, j - 1);
// 		return dp1[i][j] = false;
// 	}
//     int solve(string s, int i, int j){
//         if(i >= j) return dp[i][j] = 0;
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         if(isPal(s, i, j)) return dp[i][j] = 0;
//         dp[i][j] = INT_MAX;
//         for(int k = i; k < j; k++){
//             int left, right;
//             if(isPal(s, i, k) == false)
//                 continue;
//             if(dp[i][k] != -1){
//                 left = dp[i][k];
//             } else{
//                 left = solve(s, i, k);
//                 dp[i][k] = left;
//             } 
//             if(dp[k+1][j] != -1){
//                 right = dp[k+1][j];
//             } else{
//                 right = solve(s, k+1, j);
//                 dp[k+1][j] = right;
//             } 
//             dp[i][j] = min(dp[i][j], left + right + 1);
//         }
//         return dp[i][j];
//     }
//     int minCut(string s) {
//         dp.resize(s.size(),vector<int> (s.size(),-1));
// 		dp1.resize(s.size(),vector<int> (s.size(),-1));
//         return solve(s, 0 , s.size()-1);
//     }
// };

class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        
        while(start < end) {
            
            if(s[start] != s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    
    int solve(string &s, int start, int end,vector<vector<int>> &dp) {
        
        if(dp[start][end] != -1) return dp[start][end];
        
        if(start >= end) return dp[start][end] = 0 ;
        
        if(isPalindrome(s,start,end) == true)
            return dp[start][end] = 0;
        
        int ans = INT_MAX;
        
        for(int ctr = start ; ctr < end ; ctr ++ ) {
            
            if(isPalindrome(s,start,ctr)==false)
                continue;
            
            int tempAns = solve(s,start,ctr,dp) + solve(s,ctr+1,end,dp) + 1;
            
            if(tempAns < ans) ans = tempAns;
        }
        
        return dp[start][end] = ans;
        
    }
    
    int minCut(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
        return solve(s,0,s.length()-1,dp);
    }
};