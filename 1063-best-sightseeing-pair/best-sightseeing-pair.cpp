class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res=0,count=0;
        for(auto b:values){
            res=max(res,count+b);
            count=max(count,b)-1;
        }
        return res;
    }
};