class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0,emp=0;
        for(auto i:moves){
            if(i=='L') count++;
            else if(i=='R') count--;
            else emp++;
        }
        return abs(count)+emp;

    }
};