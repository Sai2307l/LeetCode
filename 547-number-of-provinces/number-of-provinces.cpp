class Solution {
public:
    void dfs(vector<bool>& vis,vector<vector<int>>& graph,int idx){
        if(vis[idx]) return;
        vis[idx] = true;
        for(int i=0;i<graph.size();i++){
            if(i!=idx && graph[idx][i]==1 && !vis[i]) dfs(vis,graph,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> Visited(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(Visited[i]) continue;
            dfs(Visited,isConnected,i);
            ans++;
        }
        return ans;
    }
};