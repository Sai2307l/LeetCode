class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<int> left(n, 0),right(n,0);
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i] = max(right[i+1],nums[i+1]);
        }
        for(int i=0;i<n;i++){
            res = max(res, (long long)(left[i]-nums[i])*right[i]);
        }

        return res;
    }
};