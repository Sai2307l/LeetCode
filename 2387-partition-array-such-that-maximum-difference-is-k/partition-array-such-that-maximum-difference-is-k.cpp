class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        set<int> s;
        for(auto i:nums) s.insert(i);
        int min_val = *s.begin(),count=1;
        for(auto itr:s){
            if(itr-min_val>k){
                min_val=itr;
                count++;
            }
        }
        return count;
    }
};