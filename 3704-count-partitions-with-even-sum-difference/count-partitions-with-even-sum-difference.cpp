class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int left =0,right=sum,count=0;
        for(int i=0;i<nums.size()-1;i++){
            left+=i;
            right-=i;
            if(abs(left-right)%2==0)count++;
        }
        cout<<sum;
        return count;
    }
};