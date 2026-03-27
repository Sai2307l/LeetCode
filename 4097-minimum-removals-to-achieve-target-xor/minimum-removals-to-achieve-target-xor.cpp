class Solution {
public:
    int count(vector<int>& arr,int target, int i,vector<unordered_map<int,int>>& dp){
        if(i<0){
            if(target==0) return 0;
            return -1;
        }
        if(dp[i].count(target)) return dp[i][target];
        int take = -1;
        int temp = count(arr,target^arr[i],i-1,dp);
        if(temp!=-1)
        take= 1+temp;
        int notTake = count(arr,target,i-1,dp);
        return dp[i][target] = max(take,notTake);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n,unordered_map<int,int>());
        int temp = count(nums,target,n-1,dp);
        if(temp==-1) return -1;
        return n-temp;
    }
};