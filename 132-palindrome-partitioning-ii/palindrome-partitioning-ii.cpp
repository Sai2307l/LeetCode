class Solution {
private:
    bool isPalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--)
        {
            int minSteps = INT_MAX;
            for(int k=i; k<n; k++)
            {
                if(isPalindrome(s, i, k))
                {
                    int steps = 1 + dp[k+1];
                    minSteps = min(minSteps, steps);
                }
            }
            dp[i] = minSteps;
        }
        return dp[0] - 1;
    }
};