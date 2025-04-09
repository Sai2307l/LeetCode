class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> val;
        int min_val=INT_MAX;
        for(auto i:nums){
            val.insert(i);
            min_val=min(i,min_val);
        }
        if(min_val<k) return -1;
        if(min_val==k) return val.size()-1;
        if(min_val>k) return val.size();
        return 0;
    }
};