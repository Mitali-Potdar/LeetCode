class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> in(n, 0);
        vector<int> vis(n, 0);
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            in[edges[i]]++;
        }
        queue <int> q;
        stack <int> s;
        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                q.push(i);
                vis[i] = 1;
                s.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int v = edges[node];
            in[v]--;
            if(in[v] == 0){
                q.push(v);
                vis[v] = 1;
                s.push(v);
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){ //part of cycle
                int length = 0;
                for (int x = i; !vis[x]; x = edges[x]) {
                    vis[x] = 1;
                    length++;
                }
                res[i] = length;
                for(int x = edges[i]; x != i; x = edges[x]) {
                    res[x] = length;
                }
            }
        }
        while(!s.empty()){
            int v = s.top();
            s.pop();
            res[v] = res[edges[v]]+1;
        }
        return res;
    }
};