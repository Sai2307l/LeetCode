class Solution {
public:
    int MOD = 1e9+7;
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        vector<vector<int>> adj(n+1);
        vector<int> cost(n+1);
        cost[0]=1;
        for(auto i:conversions){
            adj[i[0]].push_back(i[1]);
            cost[i[1]] = i[2];
        }

        cost_cal(adj,cost,-1,0);
        return cost;
    }

    void cost_cal(vector<vector<int>>& adj, vector<int>& cost, int parent_idx, int idx){
        if(idx!=0)cost[idx] =(int)(((long long)cost[idx]*(long long)cost[parent_idx])%MOD); 
        for(auto i:adj[idx]){
            cost_cal(adj,cost,idx,i);
        }
    }
};