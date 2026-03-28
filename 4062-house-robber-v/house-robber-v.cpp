class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<vector<long long>> dp(2,vector<long long>(n));
        dp[0][0] = nums[0];
        dp[1][0] = 0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                dp[0][i]= dp[1][i-1]+nums[i];
                dp[1][i]= max(dp[0][i-1],dp[1][i-1]);
            }else{
                dp[0][i] = max(dp[0][i-1],dp[1][i-1])+nums[i];
                dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
            }
        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};