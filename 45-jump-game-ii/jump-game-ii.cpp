static const int _ =[]{
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j<nums.size())dp[i+j]=min(dp[i]+1,dp[i+j]);
                else break;
            }
        }
        return dp[nums.size()-1];
    }
};