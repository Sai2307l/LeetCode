class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int val=0;
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){ 
            dp[i][0]=matrix[i][0];
            val+=dp[i][0];
        }

        for(int i=1;i<m;i++){ 
            dp[0][i]=matrix[0][i];
            val+=dp[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=matrix[i][j]==1?min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1:0;
                val+=dp[i][j];
            }
        }
        return val;
    }
};