class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> freq;
        sort(nums.begin(),nums.end());
        
        for(auto i:nums) freq.insert(i);
        if(nums[0]+nums[1]<=nums[2]) return "none";
        if(freq.size()==1) return "equilateral";
        if(freq.size()==2) return "isosceles";
        
        return "scalene";
        
    }
};