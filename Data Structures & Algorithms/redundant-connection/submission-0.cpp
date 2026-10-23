class Solution {
public:
    vector<vector<int>>adj;
    bool dfs(int src,vector<bool>&vis,int target){
        if(src==target){
            return true;
        }
        vis[src]=true;
        for(int v:adj[src]){
            if(!vis[v]){
                if(dfs(v,vis,target)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        adj.resize(n+1);
        for(auto&edge:edges){
            int u=edge[0];
            int v=edge[1];
            vector<bool>vis(n+1,false);
            if(dfs(u,vis,v)){
                return edge;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
