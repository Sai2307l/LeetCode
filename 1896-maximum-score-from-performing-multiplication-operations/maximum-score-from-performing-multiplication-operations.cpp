class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return recc_sol(nums,multipliers,0,0,0,dp);
    }
    int recc_sol(vector<int>& nums,vector<int>& multipliers,int left,int right,int index,vector<vector<int>>& dp){
        if(dp[left][right]!=-1) return dp[left][right];
        if(index==multipliers.size()) return dp[left][right] = 0;
        return dp[left][right] = max((nums[left]*multipliers[index])+recc_sol(nums,multipliers,left+1,right,index+1,dp),(nums[nums.size()-1-right]*multipliers[index])+recc_sol(nums,multipliers,left,right+1,index+1,dp));
    }
};