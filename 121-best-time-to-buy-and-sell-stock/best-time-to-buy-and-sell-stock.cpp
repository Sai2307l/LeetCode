static const int _ = []{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0],diff=INT_MIN,diffmax=INT_MIN;
        for(auto i:prices){
            if(min>i)min=i;
            if(i>min)diff=i-min;
            diffmax=max(diff,diffmax);
        }
        if(diffmax==INT_MIN) return 0;
        return diffmax;
    }
};