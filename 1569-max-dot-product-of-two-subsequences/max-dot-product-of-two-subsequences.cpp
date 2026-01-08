class Solution {
public:
    typedef vector<int> vi;
    int recc_sol(vector<vi>& dp,vi& arr, vi& brr,int idx1, int idx2){
        if(idx1<0 || idx2<0 ) return -1e9;
        if(dp[idx1][idx2]!=INT_MIN) return dp[idx1][idx2];
        int take = arr[idx1]*brr[idx2] + max(0,recc_sol(dp,arr,brr,idx1-1,idx2-1));
        int notTake = max(recc_sol(dp,arr,brr,idx1,idx2-1),recc_sol(dp,arr,brr,idx1-1,idx2));
        return dp[idx1][idx2] = max(take,notTake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vi> dp(nums1.size(),vi(nums2.size(),INT_MIN));
        return recc_sol(dp,nums1,nums2,nums1.size()-1,nums2.size()-1);
    }
};