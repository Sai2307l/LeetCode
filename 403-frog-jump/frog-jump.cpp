class Solution {
public:

    bool func(vector<int>& v, unordered_map<int,int>& m, vector<vector<int>>& dp, int i, int k) {
        if (i == v.size() - 1) {
            return true;
        }
        if (i > v.size() - 1) {
            return false;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        int val = v[i];
        int k1 = k - 1;
        int k2 = k;
        int k3 = k + 1;
        bool c1 = false, c2 = false, c3 = false;
        if (k1 > 0) {
            int nextPos = val + k1;
            if (m.find(nextPos) != m.end()) {
                int nextIndex = m[nextPos];
                c1 = func(v, m, dp, nextIndex, k1);
            }
        }
        if (k2 > 0) {
            int nextPos = val + k2;
            if (m.find(nextPos) != m.end()) {
                int nextIndex = m[nextPos];
                c2 = func(v, m, dp, nextIndex, k2);
            }
        }
        if (k3 > 0) {
            int nextPos = val + k3;
            if (m.find(nextPos) != m.end()) {
                int nextIndex = m[nextPos];
                c3 = func(v, m, dp, nextIndex, k3);
            }
        }
        return dp[i][k] = (c1 || c2 || c3);
    }
    bool canCross(vector<int>& v) {
        unordered_map<int,int> m;
        for (int i = 0; i < v.size(); i++) {
            m[v[i]] = i;
        }
        vector<vector<int>> dp(v.size(), vector<int>(v.size(), -1));
        return func(v, m, dp, 0, 0);
    }
};
