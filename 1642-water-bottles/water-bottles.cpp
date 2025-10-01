class Solution {
public:
     int exchange(int n, int k){
        if (n<k) return 0;
        auto [n0, r]=div(n, k);
        return n0+exchange(n0+r, k);
    }
     int numWaterBottles(int n, int k) {
        return n+exchange(n, k);
    }
};