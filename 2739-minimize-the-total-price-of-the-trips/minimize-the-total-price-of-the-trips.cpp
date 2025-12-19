class Solution {
public:
    void find_contri(int par,int pos,int end,map<int,vector<int>>& adj,vector<int>& contri,vector<int>& state){
        if(pos==end){
            for(auto i:state) contri[i]++;
            return;
        }
        for(auto i:adj[pos]){
            if(i==par) continue;
            state.push_back(i);
            find_contri(pos,i,end,adj,contri,state);
            state.pop_back();
        }
    }
    int dfs(int pos,map<int,vector<int>>& adj,vector<int>& contri,vector<vector<int>>& dp,vector<int>& prices,int par,bool par_halfed){
        if(dp[pos][(int)par_halfed]!=-1) return dp[pos][(int)par_halfed];

        int take = (contri[pos]*prices[pos])/2;
        int notTake = (contri[pos]*prices[pos]);
        
        for(auto i:adj[pos]){
            if(i==par) continue;
            notTake += dfs(i,adj,contri,dp,prices,pos,0);
        }
        if(par_halfed) return dp[pos][(int)par_halfed] = notTake;
        else{
            for(auto i:adj[pos]){
            if(i==par) continue;
            take += dfs(i,adj,contri,dp,prices,pos,1);
            }
        }
        return dp[pos][(int)par_halfed] = min(take,notTake);
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        map<int,vector<int>> adj_set;
        for(auto i:edges){
            int a = i[0];
            int b = i[1];
            adj_set[a].push_back(b);
            adj_set[b].push_back(a);
        }
        vector<int> contri(n,0);
        vector<int> state;
        for(auto i:trips){
            int a = i[0];
            int b = i[1];
            state.push_back(a);
            find_contri(a,a,b,adj_set,contri,state);
            state.pop_back();
        }
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = dfs(0,adj_set,contri,dp,price,-1,0);
        return ans;
    }
};