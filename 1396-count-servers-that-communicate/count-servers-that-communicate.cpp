class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row(n,0),column(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)continue;
                row[i]++;
                column[j]++;
            }
        }
        for(auto i:row)cout<<i<<" ";
        cout<<endl;
        for(auto i:column)cout<<i<<" ";
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                if(row[i]>=2 || column[j]>=2) count++;
            }
        }
        return count;
    }
};