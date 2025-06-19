class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=1;
        int min_val=nums[0] , max_val=nums[0];
        for(int i=1;i<nums.size();i++){
           min_val = min(min_val,nums[i]);
           max_val = max(max_val,nums[i]);
            if(min_val!=INT_MAX && max_val!=INT_MIN && max_val-min_val>k){
            count++;
            min_val=nums[i];
            max_val=nums[i];
           }
        }
        return count;
    }
};