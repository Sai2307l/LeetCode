class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int num = nums[i];
            for(int j=1;j<num;j++){
                int val = (j) | (j+1);
                if(num==val){
                    ans[i]=j;
                    break;
                }
            }
        }
        return ans;
    }
};