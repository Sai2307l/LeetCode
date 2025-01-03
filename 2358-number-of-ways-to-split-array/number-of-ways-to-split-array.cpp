class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
     vector<long long> prefixsum;
     long long sum=0;
     for(auto i:nums){
        sum+=i;
        prefixsum.push_back(sum);
     }     
     int count=0;
     for(int i=0;i<nums.size()-1;i++){
        if(2*prefixsum[i]>=sum)count++;
     }   
     return count;
    }
};