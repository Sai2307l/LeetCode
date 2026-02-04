class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(4, vector<long long>(n, -1e18));
        long long ans = -1e18;
        for(int i = 0; i < n; i++) {
            dp[0][i] = nums[i];
            if(i) {
                //start increasing here OR we are alreading in increasing phase
                if(nums[i] > nums[i - 1]) 
                dp[1][i] = max(dp[0][i - 1] + nums[i], dp[1][i - 1] + nums[i]);
                //start decreasing phase here OR we are alreading in it
                if(nums[i] < nums[i - 1]) 
                dp[2][i] = max(dp[1][i - 1] + nums[i], dp[2][i - 1] + nums[i]);
                //start 2nd increasing phase or continue prev 2nd increasing phase
                if(nums[i] > nums[i - 1]) 
                dp[3][i] = max(dp[2][i - 1] + nums[i], dp[3][i - 1] + nums[i]); 
            }
            ans = max(ans, dp[3][i]);
        }
        
        return ans;
    }
};