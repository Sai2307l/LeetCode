class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> tab(grid.size(),vector<int>(grid[0].size(),INT_MAX));

        for (int i = 0;i<grid[0].size();i++) {
            tab[0][i] = grid[0][i];
        }

        for (int i = 0;i<grid.size()-1;i++) {
            for (int b = 0;b<grid[i].size();b++) {
                for (int x = 0;x<grid[i].size();x++) {
                    tab[i+1][x] = min(tab[i+1][x],tab[i][b]+grid[i+1][x]+moveCost[grid[i][b]][x]);
                }
            }
        }

        int res = INT_MAX;
        
        for (int i = 0;i<grid[0].size();i++) {
            res = min(res,tab[tab.size()-1][i]);
        }

        return res;
    }
};