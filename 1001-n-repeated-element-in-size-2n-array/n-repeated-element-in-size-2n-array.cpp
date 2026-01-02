class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int> freq;
        int n = nums.size(),m = n/2, num;
        for(auto i:nums){
            freq[i]++;
            if(freq[i]== m){
                num = i;
                break;
            }
        }
        return num;
    }
};