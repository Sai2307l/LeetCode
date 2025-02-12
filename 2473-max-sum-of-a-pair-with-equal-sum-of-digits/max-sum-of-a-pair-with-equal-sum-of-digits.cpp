class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>> freq;
        for(auto i:nums){
            int a=i,sum=0;
            while(a>0){
                sum+=a%10;
                a/=10;
            }
            freq[sum].push_back(i);
        }
        int ans= -1;
        for(auto i:freq){
            if(i.second.size()>=2){
                sort(i.second.begin(),i.second.end(),greater<int>());
                ans=max(ans,i.second[0]+i.second[1]);
            }
        }
        return ans;
    }
};