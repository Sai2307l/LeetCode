class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(), max_ele = *max_element(nums.begin(),nums.end());
        map<int,pair<int,int>> pos;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(pos.find(x)!=pos.end() && pos[x].second!=-1){
                ans = min(ans , (i-pos[x].first)<<1);
                pos[x].first = pos[x].second;
                pos[x].second = i;
            }
            else if(pos.find(x)!=pos.end()){
                pos[x].second = i;
            }else{
                pos[x] = {i,-1};
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};