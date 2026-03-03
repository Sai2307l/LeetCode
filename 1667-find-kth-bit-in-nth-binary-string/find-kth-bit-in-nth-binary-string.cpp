class Solution {
public:
    char rev(char a){
        if(a=='0') return '1';
        else return '0';
    }
    char findKthBit(int n, int k) {
        if(n==1 && k==1) return '0';
        int idx = pow(2,n-1);
        if(k<idx) return findKthBit(n-1,k);
        else if(k == idx) return '1';
        else return rev(findKthBit(n-1,2*idx-k));
    }
};