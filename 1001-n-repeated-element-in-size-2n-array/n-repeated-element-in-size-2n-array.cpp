class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> freq;
        for(auto i:nums){
            freq[i]++;
            if(freq[i]==2)return i;
        }
        return 0;
    }
};