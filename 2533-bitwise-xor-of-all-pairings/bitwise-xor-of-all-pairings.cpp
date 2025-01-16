class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans=0;
        if(m%2==0 && n%2==0) return 0;
        else if(m%2==1 && n%2==0){
            for(auto i:nums1)ans^=i;
        }
        else if(m%2==0 && n%2==1){
            for(auto i:nums2)ans^=i;
        }
        else{
            for(auto i:nums1)ans^=i;
            for(auto i:nums2)ans^=i;
        }
        return ans;
    }
};