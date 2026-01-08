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
    int tabulation(vector<vi>& dp,vi& arr,vi& brr){
        int n = arr.size();
        int m = brr.size();
        for(int i=0;i<n;i++){
            if(i>0)dp[i][0] = max(arr[i]*brr[0],dp[i-1][0]);
            else dp[0][0] = arr[0]*brr[0];
        }
        for(int i=0;i<m;i++){
            if(i>0)dp[0][i] = max(arr[0]*brr[i],dp[0][i-1]);
            else dp[0][0] = arr[0]*brr[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = max(arr[i]*brr[j] + max(0,dp[i-1][j-1]),max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n-1][m-1];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vi> dp(nums1.size(),vi(nums2.size(),INT_MIN));
        // int ans1 = recc_sol(dp,nums1,nums2,nums1.size()-1,nums2.size()-1);
        // dp.resize(nums1.size(),vi(nums2.size(),INT_MIN));
        int ans2 = tabulation(dp,nums1,nums2);
        return ans2;
    }
};