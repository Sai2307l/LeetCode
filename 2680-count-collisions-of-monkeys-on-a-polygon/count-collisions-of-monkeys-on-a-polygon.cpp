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
    int monkeyMove(int n) {
        return (power(2, n, mod) - 2 + mod)%mod;
    }
};