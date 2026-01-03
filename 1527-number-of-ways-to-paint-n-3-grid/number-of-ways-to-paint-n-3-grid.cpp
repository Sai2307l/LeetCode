class Solution {
public:
    const int mod  = 1e9+7;
    int numOfWays(int n) {
        vector<long long> a(n+1),b(n+1);
        a[1] = 6;
        b[1] = 6;
        for(int i=2;i<=n;i++){
            a[i] = (2*a[i-1] + 2*b[i-1])%mod;
            b[i] = (2*a[i-1] + 3*b[i-1])%mod;
        }
        return (a[n]+b[n])%mod;
    }
};