class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int column = n/rows;
        vector<vector<char>> enc(rows,vector<char>(column));
        for(int i=0;i<rows;i++){
            for(int j=0;j<column;j++){
                enc[i][j] = encodedText[i*column+j];
            }
        }
        string sol="";
        for(int i=0;i<column;i++){
            int col = i;
            for(int j=0;j<rows;j++){
                if(col<column)sol+=enc[j][col];
                col++;
            }
        }
        int idx=sol.size();
        for(int i=sol.size()-1;i>=0;i--){
            if(sol[i]==' ')idx = i;
            else break;
        }
        int len = idx;
        string ans = sol.substr(0,len);
        return ans;
    }
};