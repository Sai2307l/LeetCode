class Solution {
public:

long long res = 0;
bool xuoi[20] = {};
bool nguoc[20] = {};
bool col[9] = {};
    void backtrack ( int pos , int en ){
        if ( pos == en ){
            res++;
            return;
        }
        for ( int i = 0 ; i < en ; i ++ ){
            if ( !col[i] && !xuoi[en+i-pos+1] && !nguoc[i+pos] ){
                col[i] = true;
                xuoi[en+i-pos+1] = true;
                nguoc[i+pos] = true;
                backtrack ( pos + 1 , en );
                col[i] = false;
                xuoi[en+i-pos+1] = false;
                nguoc[i+pos] = false;
            }
        }
    }
    int totalNQueens(int n) {
        backtrack(0,n);
        return res;
    }
};