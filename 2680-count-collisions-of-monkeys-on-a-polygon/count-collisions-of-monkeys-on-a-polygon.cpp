class Solution {
public:
    int monkeyMove(int n) {
        long long a=2,m=1e9+7;
        a %= m;
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return (res-2+m)%m;
    }
};