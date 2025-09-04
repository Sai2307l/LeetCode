class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xz = abs(z-x);
        int yz = abs(z-y);
        if(xz == yz){
            return 0;
        }
        else if(xz<yz){
            return 1;
        }else{
            return 2;
        }
    }
};