class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int fx = 0;
        for(auto i : nums){
            fx += i;
        }
        int n = nums.size();
        int fi0 = 0;
        for(int i = 0; i < n ; i++){
            fi0 += (i*nums[i]);
        }
        int ans = fi0 , fii = 0;
        for(int i = 1; i < n; i++){
            fii = fi0 + fx - n*nums[n-i];
            ans = max(ans,fii);
            fi0 = fii;
        }
        return ans;
    }
};