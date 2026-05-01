class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0,acc = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=i*nums[i];
        }
        cout<<sum<<endl;
        int sol = sum;
        for(int i=n-1;i>0;i--){
            sum+=acc-((n)*nums[i]);
            sol = max(sum,sol);
            cout<<sum<<endl;
        }
        return sol;
    }
};