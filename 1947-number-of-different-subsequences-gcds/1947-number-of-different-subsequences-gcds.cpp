class Solution {
public:
    int gcd(int a, int b){
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        int LIMIT = 0;
        
        int ans = 0;
        
        vector<bool> hash(2e5 + 1, false);
        for(auto num:nums){
            hash[num] = true;
            LIMIT = max(LIMIT, num);
        }
        
        for(int i=1;i<=LIMIT; i++){
            // to check if i is a valid gcd of subsequence.
            
            int g = 0;
            
            for(int j=i;j<=LIMIT;j+=i){
                if(hash[j]){
                    g = gcd(g, j);
                }    
            }
            
            if(g == i)
                ans++;
            
        }
        
        return ans;
    }
};