class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums){
            freq[i]++;
        }
        vector<pair<int,int>> sol;
        for(auto i:freq) sol.push_back(make_pair(i.first,i.second));
        int n=sol.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            if(sol[i-1].first+1==sol[i].first) ans=max(ans,sol[i-1].second+sol[i].second);
        }
        return ans;
    }
};