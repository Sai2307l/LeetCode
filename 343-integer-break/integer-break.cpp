class Solution {
public:
    vector<int> dp;
    int recc_break(int n){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int sol=1;
        for(int i=1;i<=n/2;i++){
            int val = i * recc_break(n-i);
            sol = max(sol,val);
        }
        return dp[n] = max(sol,n);
    }
    int integerBreak(int n) {
        dp.resize(n+1,-1);
        int sol = 1;
        for(int i=1;i<=n/2;i++){
            sol = max(i * recc_break(n-i),sol);
        }
        return sol;
    }
};