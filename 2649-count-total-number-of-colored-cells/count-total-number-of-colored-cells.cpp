class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        if(n==2) return 5;
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=4;
        for(int i=2;i<n;i++){
            dp[i]=4+dp[i-1];
        }
        return accumulate(dp.begin(),dp.end(), (long long) 0);
    }
};