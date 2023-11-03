class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res = 0;
        for(int i = 0; i < n-1; i++){
            if(colors[i] == colors[i+1]){
                int m = neededTime[i];
                while(colors[i] == colors[i+1]){
                    res += min(m, neededTime[i+1]);
                    m = max(m, neededTime[i+1]);
                    i++;
                }
                i--;
            }    
        }
        return res;
    }
};