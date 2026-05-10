class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> idx;
        for(int i=0;i<nums.size();i++){
            if(idx.find(target - nums[i])!= idx.end()){
                return {i,idx[target-nums[i]]};
            }
            idx[nums[i]] = i;
        }
        return {0,0};
    }
};