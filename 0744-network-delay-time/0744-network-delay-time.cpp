class Solution {
public:
    int networkDelayTime(vector<vector<int>>& roads, int n, int k) {
        int mod = 1e9+7;
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
        }
        
        vector<int> time(n+1, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); //(time, node)
        time[k] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            
            for(auto v: graph[node]) {
                int nbr = v.first;
                int l = v.second;
                
                if(time[nbr] > time[node] + l) {
                    time[nbr] = time[node] + l;
                    pq.push({time[nbr], nbr});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i < n+1; i++){
            ans = max(time[i], ans);
            cout << time[i] << " ";
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};