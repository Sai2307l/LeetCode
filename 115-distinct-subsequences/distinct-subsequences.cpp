class Solution {
public:
    int recursiveWithMemoization(string& s, string& t, int s_ind, int t_ind, vector<vector<int>>& dp) {
        if (t_ind == t.length()) {
            return 1;
        }
        if (s_ind == s.length()) {
            return 0;
        }

        if (dp[s_ind][t_ind] != -1) {
            return dp[s_ind][t_ind];
        }

        int take = 0, notTake = 0;

        if (s[s_ind] == t[t_ind]) {
            take = recursiveWithMemoization(s, t, s_ind + 1, t_ind + 1, dp);
        }

        notTake = recursiveWithMemoization(s, t, s_ind + 1, t_ind, dp);


        return dp[s_ind][t_ind] = take+notTake;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return recursiveWithMemoization(s, t, 0, 0, dp);
    }
};