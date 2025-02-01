class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int parity=nums[0]%2;
        for(auto i:nums){
            if(parity==i%2){
                parity=parity==1?0:1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};