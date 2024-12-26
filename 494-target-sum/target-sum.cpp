class Solution {
public:
    int count=0;
    int arr[20];
    void back_track(vector<int>& nums,int index,int sum,int target){
        if(index==nums.size() && sum == target){
            count++;
            return;
        }
        if(index==nums.size()) return;
        if(sum+arr[index]<target || sum-arr[index]>target) return;
        back_track(nums,index+1,sum+nums[index],target);
        back_track(nums,index+1,sum-nums[index],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        arr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) arr[i]=arr[i+1]+nums[i];
        for(auto i:arr) cout<<i<<" ";
        back_track(nums,0,0,target);
        return count;
    }
    
};