class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int max_num=INT_MIN;
        for(auto i:nums) max_num=max(max_num,i);
        vector<int> arr(max_num+1,0),count(max_num+1,0);
        for(int i=1;i<=max_num;i++){
            for(int j=i;j<=max_num;j+=i){ arr[j]+=i;
            count[j]++;
            }
        }
        int sum=0;
        for(auto i:nums) if(count[i]==4) sum+=arr[i];
        // for(auto i:nums) cout<<arr[i]<<" ";
        return sum;
    }
};