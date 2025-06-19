class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            if(freq.find(target-nums[i])!=freq.end()){
                return {i,freq[target-nums[i]]};
            }
            else{
                freq[nums[i]]=i;
            }
        }
        return {};
    }
};