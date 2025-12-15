class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long sum = 0, ans = 0;
        int left = 0,n = prices.size(),prev=prices[0]+1;
        for(int i=0;i<n;i++){
            if(prev-prices[i]!=1){
                cout<<i-1<<" "<<left<<endl;
                sum = ((i-1)-left)+1;
                ans += (sum*(sum+1))/2;
                left = i;
            }
            prev = prices[i];
        }
        sum = ((n-1)-left)+1;
        ans += (sum*(sum+1))/2;
        return ans;
    }
};