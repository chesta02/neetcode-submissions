class Solution {
public:
    bool isCycle(int src,vector<bool>&vis,vector<bool>&res_path,vector<vector<int>>& courses){
        vis[src]=true;
        res_path[src]=true;
        for(int i=0;i<courses.size();i++){
            int v=courses[i][0];
            int u=courses[i][1];
            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,vis,res_path,courses)){
                        return true;
                    }
                }else if(res_path[v]){
                    return true;
                }
            }
        }
        res_path[src]=false;
        return false;
    }
    void TopoSort(int src,vector<bool>&vis,stack<int>&s,vector<vector<int>>& courses){
        vis[src]=true;
        for(int i=0;i<courses.size();i++){
            int v=courses[i][0];
            int u=courses[i][1];
            if(src==u){
                if(!vis[v]){
                    TopoSort(v,vis,s,courses);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& courses) {
        vector<bool>vis(n,false);
        vector<bool>res_path(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,vis,res_path,courses)){
                    return ans;
                }
            }
        }
        vis.assign(n,false);
        stack<int>s;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                TopoSort(i,vis,s,courses);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
