class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> freq;
        int max_val=INT_MIN;
        for(auto i:nums){
            freq[i]++;
            max_val=max(max_val,i);
        }
        for(int i=1;i<=max_val;i++){
            if(freq[i]==0) return i;
        }
        return max(max_val+1,1);
    }
};