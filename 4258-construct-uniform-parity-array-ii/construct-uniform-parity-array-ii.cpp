class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool fla = true;
        int small_odd=INT_MAX,small_eve=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0 && nums1[i]<small_eve) small_eve = nums1[i];
            if(nums1[i]%2==1 && nums1[i]<small_odd) small_odd = nums1[i];
            if(nums1[0]%2!=nums1[i]%2){
                fla = false;
            }
        }
        if(fla) return true;
        if(small_odd<small_eve) return true;
        return false;
    }
};