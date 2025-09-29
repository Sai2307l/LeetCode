class Solution {
public:
    long long min(long long a,long long b){
        return a>b?b:a;
    }
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0),suffix(n,0);
        vector<bool> inc(n,false),dec(n,false);
        inc[0] = true;
        dec[n-1] = true;
        for(int i=0;i<n;i++){
            prefix[i] = nums[i];
            if(i!=0) prefix[i]+=prefix[i-1];
            if(i!=0 && nums[i]>nums[i-1]) inc[i] = inc[i-1]; 
        }
        for(int i=n-1;i>=0;i--){
            suffix[i] = nums[i];
            if(i!=n-1) suffix[i]+=suffix[i+1];
            if(i!=n-1 && nums[i]>nums[i+1]) dec[i] = dec[i+1];
        }

        long long sol = LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(inc[i] && dec[i+1])sol=min(sol,abs(prefix[i]-suffix[i+1]));
        }
        return sol==LLONG_MAX?-1:sol;
    }
};