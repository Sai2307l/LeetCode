class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int i=0;i<5;i++) dp[0][i]=1;
        for(int i=0;i<=n;i++) dp[i][4]=1;
        for(int i=1;i<=n;i++){
            for(int j=3;j>=0;j--){
                dp[i][j]=dp[i-1][j]+dp[i][j+1];
            }
        }
        for(auto i:dp){
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
        int val=accumulate(dp[n-1].begin(),dp[n-1].end(),0);
        return val;
    }
};