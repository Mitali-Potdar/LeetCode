class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> vis(n, 0);
        int sum = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += val;
            for(int j = 0; j < n; j++){
                if(vis[j] == 0 && j != node){
                    int d = abs(points[j][0] - points[node][0]) + abs(points[j][1] - points[node][1]);
                    pq.push({d, j});
                }
            }
        }
        return sum;
    }
};