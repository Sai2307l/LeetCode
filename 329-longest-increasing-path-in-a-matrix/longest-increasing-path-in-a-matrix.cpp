class Solution {
public:

// Memoization array to store longest path from each cell
   int dp[200][200];

int rec(int i,int j,vector<vector<int>>& matrix)
{
// Return cached result if available
	if(dp[i][j]!=-1)return dp[i][j];

	int n=matrix.size();
 	int m=matrix[0].size();
// Initial path length (itself)
	int val=1;

// Move downward
	if(i+1<n && matrix[i+1][j]>matrix[i][j])
	    val=max(val,rec(i+1,j,matrix)+1);
// Move upward
	if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
	    val=max(val,rec(i-1,j,matrix)+1);
// Move leftward
	if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
	    val=max(val,rec(i,j-1,matrix)+1);
// Move rightward
	if(j+1<m && matrix[i][j+1]>matrix[i][j])
	    val=max(val,rec(i,j+1,matrix)+1);

// Store and return the computed result	
	return dp[i][j]=val;
}


 int longestIncreasingPath(vector<vector<int>>& matrix) {
 		
 		int n=matrix.size();
 		int m=matrix[0].size();
 		int ans=0;
    // Initialize dp array with -1
        memset(dp,-1,sizeof(dp));
    // Calculate longest path for each cell
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<m;j++)
        		ans=max(ans,rec(i,j,matrix));// update the maximum
        }
        return ans;
    }
};