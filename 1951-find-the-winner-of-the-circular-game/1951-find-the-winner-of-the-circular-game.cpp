class Solution {
public:
//https://cs.stackexchange.com/questions/7048/a-recursive-formula-for-generalized-josephus-problem
//Finally only one zero will be left
//We want the old position of that 0
    int helper(int n, int k){
        if(n == 1)
            return 0;
        return (helper(n-1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        //return helper(n, k) + 1; //since we are taking zero indexed
        queue<int> q;
        for(int i=1; i<=n; i++) q.push(i);
        
        while(q.size() > 1) {
            int i = k;
            while(i > 1) {
                auto f = q.front(); q.pop();
                q.push(f);
                i--;
            }
            q.pop();
        }
        return q.front();
    }
};