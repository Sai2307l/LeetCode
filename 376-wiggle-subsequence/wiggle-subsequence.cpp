class Solution {
public:
    int solve(int idx,int isUp,vector<int>&nums,vector<vector<int>>&dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][isUp]!=-1){
            return dp[idx][isUp];
        }
        int notTake = solve(idx+1,isUp,nums,dp);
        int take = 0;
        if((isUp && nums[idx] < nums[idx - 1]) || (!isUp && nums[idx] > nums[idx - 1])){
            take = 1 + solve(idx+1,!isUp,nums,dp);
        }
        return dp[idx][isUp] = max(take,notTake);
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return max(solve(1,1,nums,dp),solve(1,0,nums,dp)) + 1;
    }
};
