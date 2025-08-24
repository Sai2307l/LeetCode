class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)count++;
            else {
                v.push_back(count);
                count=0;
            }
        }
        if(count!=0) v.push_back(count);
        int maxi=0;
        if(nums.size()==1) return 0;
        if(v.size()==1)return v[0]-1;
        if(v.size()==nums.size()) return 0;
        int sum=v[0]+v[1];
        maxi=sum;
        for(int i=1;i<v.size()-1;i++){
            sum=sum+v[i+1]-v[i-1];
            maxi=max(sum,maxi);
        }
        return maxi;
        // for(auto i:v) cout<<i<<" ";
        return 0;
    }
};