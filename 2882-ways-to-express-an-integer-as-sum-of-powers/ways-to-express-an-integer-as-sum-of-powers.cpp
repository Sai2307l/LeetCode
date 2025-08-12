int const M = 1e9+7;

class Solution {
private:
    vector<vector<int>> memo;
    vector<int> power; // store precomputed powers

    int func(int n, int sum, int x, int num) {
        if (sum == n) return 1;
        if (sum > n) return 0;

        if (num >= power.size()) return 0; // no more numbers left

        if (memo[num][sum] != -1) return memo[num][sum]; // added

        int take = 0;
        if (sum + power[num] <= n) { // early pruning
            take = func(n, sum + power[num], x, num + 1);
        }
        int notTake = func(n, sum, x, num + 1);

        return memo[num][sum] = (take + notTake) % M; // updated
    }

public:
    int numberOfWays(int n, int x) {
        // precompute powers
        for (int i = 1; pow(i, x) <= n; i++) {
            power.push_back((int)pow(i, x));
        }
        memo.assign(power.size(), vector<int>(n + 1, -1));
        return func(n, 0, x, 0);
    }
};