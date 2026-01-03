class Solution {
public:
    const int mod  = 1e9+7;
    int numOfWays(int n) {
        long long same=6,notsame=6,currsame,currnotsame;
        for(int i=0;i<n-1;i++){
            currnotsame = (2*notsame + 2*same)%mod;
            currsame = (2*notsame + 3*same)%mod;
            same = currsame;
            notsame  = currnotsame; 
        }
        return (same+notsame)%mod;
    }
};