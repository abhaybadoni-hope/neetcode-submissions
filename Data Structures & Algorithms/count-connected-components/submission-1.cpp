class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,int node,vector<int>& vis){
        vis[node] = 1;

        for(auto& next:adj[node]){
            if(!vis[next]){
               dfs(adj,next,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;

        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int res = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                res++;
            }
        }

        return res;
    }
};
