class Solution {
public:
    vector<unsigned int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,0);
        for(auto i:nums) if(i<=target)dp[i]=1;
        for(int i=1;i<=target;i++){
            for(auto j:nums){
                if(i-j>=0){
                    dp[i] += dp[i-j];
                }
            }
        }
        return dp[target];
    }
};