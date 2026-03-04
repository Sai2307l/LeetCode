class Solution {
public:
    bool check(vector<vector<int>>& mat,int x,int y){
        int count_x=0,count_y=0;
        for(int i=0;i<mat.size();i++){
            if(mat[i][y]==1) count_x++;
        }
        for(int i=0;i<mat[0].size();i++){
            if(mat[x][i]==1) count_y++;
        }
        return count_x==1 && count_y==1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && check(mat,i,j)) count++;
            }
        }
        return count;
    }
};