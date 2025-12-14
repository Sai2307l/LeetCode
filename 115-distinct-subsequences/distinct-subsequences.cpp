class Solution {
public:
    int recc_sol(string& s,string& t, int idxs, int idxt,vector<vector<int>>& dp){
        if(idxt==t.size()){
            return 1;
        }
        if(idxs==s.size()) return 0;

        if(dp[idxs][idxt]!=-1) return dp[idxs][idxt];

        int take = 0,notake=0;

        if(s[idxs] == t[idxt]) take=recc_sol(s,t,idxs+1,idxt+1,dp);
        notake=recc_sol(s,t,idxs+1,idxt,dp);
        return dp[idxs][idxt] = take + notake;
    }
    int numDistinct(string s, string t) {
       if(t.size()>s.size()) return false;
       vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
       return recc_sol(s,t,0,0,dp);
    }
};