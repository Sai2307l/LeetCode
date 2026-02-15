class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;

        int sum = accumulate(nums.begin(),nums.end(),0);
        int curr = 0;
        for(int i = 0;i<n;i++){
            curr += nums[i]*i;
        }
        int ans = curr;
        for(int i = 0;i<n;i++){
            curr += sum - n*nums[n-1-i];
            ans = max(ans,curr);
        }
        return ans;
    }
};