class Solution {
public:
    int rev(int n){
        int num = 0;
        while(n){
            num*=10;
            num+=n%10;
            n /= 10;
        }
        cout<<num;
        return num;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};