class Solution {
public:
//[[1,2,10],[2,3,20],[2,5,25]]
// Our stops array: [0,0,0,0,0,0] )(last =(6th)stop is destination stop 
// Consider 1st booking: +10 at 1st stop and -10 at 3rd stop => [10,0,-10,0,0]
// Consider 2nd booking: +20 at 2nd stop and -20 at 4th stop => [10,20,-10,-20,0]
// Consider 3rd booking: +25 at 2nd stop and -25 at 6th stop=>[10,45,-10,-20,0,-25]
// So total passengers at each stop: [10,10+45,10+45-10,10+45-10-20,10+45-10-20+0,10+45-10-20+0-25]=[10,55,45,25,25,0]
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n+1, 0);
        
        for(auto it: bookings){
            res[it[0]-1] += it[2];
            res[it[1]] -= it[2];
        }
        
        for(int i = 1; i < n; i++)
            res[i] += res[i-1];
            
        res.pop_back();
        return res;
    }
};