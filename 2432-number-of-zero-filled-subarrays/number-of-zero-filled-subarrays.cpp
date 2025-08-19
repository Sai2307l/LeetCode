class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        map<long long,long long> freq;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
            }
            else{
                if(count>0) freq[count]++;
                count=0;
            }
            if(i==nums.size()-1 && count!=0) freq[count]++;
        }
        long long ans = 0;
        for(auto i:freq){
            cout<<i.first<<" "<<i.second<<endl;
            ans += i.second* (i.first*(i.first+1))/2;
        }
        return ans;
    }
};