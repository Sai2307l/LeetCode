class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,sum2=0;
        int count1=0,count2=0;
        for(auto i:nums1)sum1+=i;
        for(auto i:nums2)sum2+=i;
        for(auto i:nums1) if(i==0) count1++;
        for(auto i:nums2) if(i==0) count2++;
        if(count1==0 && count2==0 && sum1!=sum2) return -1;
        if(count2==0 && sum1+count1>sum2) return -1;
        if(count1==0 && sum2+count2>sum1) return -1;
        sum1+=count1;
        sum2+=count2;
        return max(sum1,sum2);
    }
};