class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int op = 0;
        int prev = 0;

        for(int& height : target){
            if(height > prev){
                op += (height - prev);
            }
            prev = height;
        }
        return op;
    }
};