class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int cells = n*n;
        while(cells*w>maxWeight){
            cells--;
        }
        return cells;
    }
};