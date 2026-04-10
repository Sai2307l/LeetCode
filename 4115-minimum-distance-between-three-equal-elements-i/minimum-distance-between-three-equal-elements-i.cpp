class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int min_dis = INT_MAX,n=nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k])
                    min_dis = min(min_dis,abs(i-j)+abs(i-k)+abs(k-j));
                }
            }
        }
        return min_dis==INT_MAX?-1:min_dis;
    }
};