class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) if(matrix[i][0]==1) dp[i][0]=1;
        for(int i=0;i<m;i++) if(matrix[0][i]==1) dp[0][i]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=matrix[i][j]==1?min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1:0;
            }
        }
        int sol=0;
        for(auto i:dp){
            for(auto j:i) sol+=j;
        }
        for(auto i:dp){
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
        return sol;
    }
};