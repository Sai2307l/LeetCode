class Solution {
public:
    bool canWinNim(int n) {
        long long num = 4;
        while(num<=n){
            if(num==n) return false;
            else num+=4;
        }
        return true;
        
    }
};