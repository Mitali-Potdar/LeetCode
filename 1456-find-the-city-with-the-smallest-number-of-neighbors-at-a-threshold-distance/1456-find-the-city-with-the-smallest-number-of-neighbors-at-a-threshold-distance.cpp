class Solution {
public:
    int djk(vector<vector<pair<int,int>>> &graph, int src, int n, int t){
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto v : graph[node]){
                if(v.second + d < dist[v.first]){
                    dist[v.first] = v.second + d;
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(dist[j] <= t) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        int val = INT_MAX;
        int res;
        for(int i = 0; i < n; i++){
            if(djk(graph, i, n, t) <= val){
                res = i;
                val = djk(graph, i, n, t);
            }
        }
        return res;
    }
};