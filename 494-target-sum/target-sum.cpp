class Solution {
public:
    int count=0;
    void back_track(vector<int>& nums,int index,int sum,int target){
        if(index==nums.size() && sum == target){
            count++;
            return;
        }
        if(index==nums.size()) return;
        back_track(nums,index+1,sum+nums[index],target);
        back_track(nums,index+1,sum-nums[index],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        back_track(nums,0,0,target);
        return count;
    }
    
};