class Solution {
public:
    int dp[2501][2501];
    int minDeletion(int l,int r,string& s){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r]) return dp[l][r] = minDeletion(l+1,r-1,s);
        return dp[l][r] = 1 + min(minDeletion(l,r-1,s),minDeletion(l+1,r,s));
    }
    int almostPalindromic(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=1,n = s.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j-i+1>=2 && minDeletion(i,j,s)<=1){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};