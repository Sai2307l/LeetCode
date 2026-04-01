class Solution {
public:
    static const int MOD = 1e9 + 7;

    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] ^ nums[i];

        vector<long long> dp0(n + 1, 0), dp1(n + 1, 0);
        dp0[n] = dp1[n] = 1;

        unordered_map<int, long long> cnt0, cnt1;
        cnt0[pref[n]] = 1;
        cnt1[pref[n]] = 1;

        for (int i = n - 1; i >= 0; i--) {
            int want1 = pref[i] ^ t1;
            int want2 = pref[i] ^ t2;

            dp0[i] = cnt1[want1] % MOD;
            dp1[i] = cnt0[want2] % MOD;

            cnt0[pref[i]] = (cnt0[pref[i]] + dp0[i]) % MOD;
            cnt1[pref[i]] = (cnt1[pref[i]] + dp1[i]) % MOD;
        }

        return dp0[0];
    }
};