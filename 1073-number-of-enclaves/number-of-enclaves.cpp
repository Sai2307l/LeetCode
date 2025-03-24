class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        if(i<0||j<0||i>=n||j>=m||grid[i][j]!=1) return;
        grid[i][j]=0;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],grid);
        } 
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1||j==m-1||i*j==0) && (grid[i][j]==1)){
                    dfs(i,j,grid);
                }
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};