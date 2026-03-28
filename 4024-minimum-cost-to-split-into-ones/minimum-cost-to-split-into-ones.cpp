class Solution {
    vector<int> dp = vector<int>(501,-1);
public:
    int minCost(int n) {
        if(n==1) return 0;
        if(dp[n]!=-1)return dp[n];
        int ans = INT_MAX;
        for(int i=1;i<=(n/2);i++){
            int left = minCost(i);
            int right = minCost(n-i);
            int cost = i*(n-i);
            ans = min(ans,left+right+cost);
        }
        return dp[n] = ans;
    }
};