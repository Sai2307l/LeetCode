class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(auto i:nums){
            set.insert(i);
        }
        nums.clear();
        for(auto i:set) nums.push_back(i);
        return set.size();
    }
};