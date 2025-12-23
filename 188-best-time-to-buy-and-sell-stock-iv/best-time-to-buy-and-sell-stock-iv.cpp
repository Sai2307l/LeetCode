class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans  = 0, n=prices.size();
        vector<vector<int>> dp(2*k,vector<int>(n,INT_MIN));
        dp[0][0] = -prices[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                dp[0][i] = max(dp[0][i-1],-prices[i]);
                for(int j=1;j<2*k;j++){
                    if(j%2==1 && j<=i)dp[j][i] = max(dp[j-1][i-1]+prices[i],dp[j][i-1]);
                    if(j%2==0 && j<=i)dp[j][i] = dp[j-1][i-1]!=INT_MIN?max(dp[j-1][i-1]-prices[i],dp[j][i-1]):dp[j][i-1];
                    if(j<=i)ans = max(dp[j][i],ans);
                }
            }
        }
        
        return ans;
    }
};