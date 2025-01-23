#define ll long long
class Solution {
    const int mod = 1e9 + 7;

    ll power(ll a, ll b, ll p = 1){
        if(a == 0){
            return 0;
        }
        ll res = 1;
        a %= p;
        while(b > 0){
            if(b & 1){
                res = (res * a) % p;
            }
            b >>= 1;
            a = (a * a) % p;
        }
        return res;
    }
public:
    int minNonZeroProduct(int p) {
        if(p == 1){
            return 1;
        }

        ll largest = (1ll << p) - 1;         // 2^p - 1
        ll sec_largest = largest - 1;        // 2^p - 2
        ll times = (1ll << (p-1)) - 1;       // 2^(p-1) - 1;

        return (power(sec_largest, times, mod) * (largest%mod) * 1ll) % mod;
    }
};